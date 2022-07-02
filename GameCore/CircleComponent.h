#pragma once
#include "TransformComponent.h"
#include <raylib.h>

namespace GameCore {
	class CircleComponent : public TransformComponent
	{
	public:
		CircleComponent(float radius = 5.0f, Color color = RAYWHITE);

		void onDraw() override;

	private:
		float m_radius;
		Color m_color;
	};
}
