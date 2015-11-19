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
		MonoAssembly* mAssembly;
		MonoImage* mImage;

		MonoClass* mTScene;

		MonoObject* mScene;
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

