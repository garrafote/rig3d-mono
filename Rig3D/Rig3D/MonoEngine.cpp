#include "MonoEngine.h"
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/object.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/debug-helpers.h>
#include <proto-03-remix/trace.h>
#include <Rig3D/GraphicsMath/cgm.h>
#include "Common/Input.h"

using namespace Rig3D;

vec3f __Transform__GetPosition(MonoObject* that)
{
	return MonoEngine::SharedInstance().player->GetPosition();
}

void __Transform__SetPosition(MonoObject* that, vec3f value)
{
	MonoEngine::SharedInstance().player->SetPosition(value);
}

MonoEngine& MonoEngine::SharedInstance()
{
	static MonoEngine instance;
	return instance;
}

MonoEngine::MonoEngine()
{
}


MonoEngine::~MonoEngine()
{
	mono_free(mGame);
	mono_jit_cleanup(mDomain);
}


void MonoEngine::Initialize()
{
	mono_set_dirs("..\\3rd-party\\mono\\lib", "..\\3rd-party\\mono\\etc");
	mono_config_parse(nullptr);
	mDomain = mono_jit_init_version("Rig3DEngine", "v4.0.30319");
	mEngineAssembly = mono_domain_assembly_open(mDomain, "Rig3DEngine.dll");
	mEngineImage = mono_assembly_get_image(mEngineAssembly);

	mGameAssembly = mono_domain_assembly_open(mDomain, "Rig3DGame.dll");
	mGameImage = mono_assembly_get_image(mGameAssembly);

	mGameType = mono_class_from_name(mGameImage, "Rig3DGame", "Game");
	mGame = mono_object_new(mDomain, mGameType);

	auto method = mono_class_get_method_from_name(mGameType, ".ctor", 0);
	mono_runtime_invoke(method, mGame, nullptr, &mException);

	mStartMethod = mono_class_get_method_from_name(mGameType, "Start", 0);
	mUpdateMethod = mono_class_get_method_from_name(mGameType, "Update", 0);

	mono_add_internal_call("Rig3DEngine.Engine::__InternalCall__GetPlayer", __GetPlayer);
	mono_add_internal_call("Rig3DEngine.Transform::__InternalCall__GetPosition", __Transform__GetPosition);
	mono_add_internal_call("Rig3DEngine.Transform::__InternalCall__SetPosition", __Transform__SetPosition);

	mono_add_internal_call("Rig3DEngine.Input::__InternalCall__GetKeyDown", Input::__GetKeyDown);
	mono_add_internal_call("Rig3DEngine.Input::__InternalCall__GetKeyUp", Input::__GetKeyUp);
	mono_add_internal_call("Rig3DEngine.Input::__InternalCall__GetKey", Input::__GetKey);
	mono_add_internal_call("Rig3DEngine.Input::__InternalCall__GetMouseButtonDown", Input::__GetMouseButtonDown);
	mono_add_internal_call("Rig3DEngine.Input::__InternalCall__GetMouseButtonUp", Input::__GetMouseButtonUp);
	mono_add_internal_call("Rig3DEngine.Input::__InternalCall__GetMouseButto", Input::__GetMouseButton);
}

void MonoEngine::Start()
{
	mono_runtime_invoke(mStartMethod, mGame, nullptr, &mException);

	if (mException)
	{
		auto mono_str = mono_object_to_string(mException, nullptr);
		auto c_str = mono_string_to_utf8(mono_str);
		TRACE(c_str);
	}
}

void MonoEngine::Update()
{
	mono_runtime_invoke(mUpdateMethod, mGame, nullptr, &mException);

	if (mException)
	{
		auto mono_str = mono_object_to_string(mException, nullptr);
		auto c_str = mono_string_to_utf8(mono_str);
		TRACE(c_str);
	}
}

MonoObject* MonoEngine::GetPlayer()
{
	auto type = mono_class_from_name(mEngineImage, "Rig3DEngine", "Transform");

	// create new object and call its constructor
	auto object = mono_object_new(mDomain, type);
	auto ctor = mono_class_get_method_from_name(mGameType, ".ctor", 0);
	mono_runtime_invoke(ctor, mGame, nullptr, &mException);

	auto property = mono_class_get_property_from_name(type, "ObjectId");
	int id = (int)object->vtable;
	void* args[1] = { &id };
	mono_property_set_value(property, object, args, &mException);

	return object;
}


// how to register using macro
MonoObject* MonoEngine::__GetPlayer()
{
	return SharedInstance().GetPlayer();
}