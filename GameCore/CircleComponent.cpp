#include "pch.h"
#include "CircleComponent.h"

GameCore::CircleComponent::CircleComponent(float radius, Color color)
{
	m_radius = radius;
	m_color = color;
}

void GameCore::CircleComponent::onDraw()
{
	GameMath::Vector3 position = getGlobalPosition();
	DrawCircle((int)position.x, (int)position.y, m_radius, m_color);
}
