#include "pch.h"
#include "CircleComponent.h"

GameCore::CircleComponent::CircleComponent(float radius, Color color)
{
	m_radius = radius;
	m_color = color;
}

void GameCore::CircleComponent::onDraw()
{
	DrawCircle(0, 0, m_radius, m_color);
}
