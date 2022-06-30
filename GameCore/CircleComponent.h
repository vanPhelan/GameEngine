#pragma once
#include "Component.h"
#include <raylib.h>

namespace GameCore {
	class CircleComponent : public Component
	{
	public:
		CircleComponent(float radius = 5.0f, Color color = RAYWHITE);

		void onDraw() override;

	private:
		float m_radius;
		Color m_color;
	};
}
