#pragma once
#include <mono/metadata/appdomain.h>

#ifdef _WINDLL
#define RIG3D __declspec(dllexport)
#else
#define RIG3D __declspec(dllimport)
#endif
#include "Common/Transform.h"

namespace Rig3D
{
	class RIG3D MonoEngine
	{
	private:
		MonoDomain* mDomain;
		MonoAssembly* mEngineAssembly;
		MonoImage* mEngineImage;

		MonoAssembly* mGameAssembly;
		MonoImage* mGameImage;

		MonoClass* mGameType;

		MonoObject* mGame;
		MonoObject* mException;

		MonoMethod* mUpdateMethod;
		MonoMethod* mStartMethod;
	public:

		Rig3D::Transform* player;

		static MonoEngine& SharedInstance();

		MonoEngine();
		~MonoEngine();

		void Initialize();

		void Start();
		void Update();

		MonoObject* GetPlayer();

		static MonoObject* __GetPlayer();
	};
}

