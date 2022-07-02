#pragma once
#include "Component.h"
#include "Matrix4.h"
#include "Vector3.h"
#include <forward_list>

namespace GameCore {
	class TransformComponent : public Component
	{
	public:
		TransformComponent() {}

		GameMath::Matrix4 getGlobalMatrix();
		GameMath::Matrix4 getLocalMatrix();

		void setLocalPosition(GameMath::Vector3 position);
		GameMath::Vector3 getLocalPosition();
		GameMath::Vector3 getGlobalPosition();

		void setLocalRotation(GameMath::Vector3 rotation);
		GameMath::Vector3 getLocalRotation();

		void setLocalScale(GameMath::Vector3 scale);
		GameMath::Vector3 getLocalScale();

		void setParent(TransformComponent* parent);
		TransformComponent* getParent();

	private:
		void updateLocalMatrix();
		void updateGlobalMatrix();

	private:
		GameMath::Matrix4 m_globalMatrix;
		GameMath::Matrix4 m_localMatrix;
		GameMath::Vector3 m_translation;
		GameMath::Vector3 m_rotation;
		GameMath::Vector3 m_scale;
		TransformComponent* m_parent = nullptr;
		std::forward_list<TransformComponent*> m_children;
		bool m_shouldUpdateLocal = false;
		bool m_shouldUpdateGlobal = false;
	};
}
