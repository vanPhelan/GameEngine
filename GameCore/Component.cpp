#include "pch.h"
#include "Component.h"

GameCore::Component::Component()
{
}

void GameCore::Component::start()
{
	onStart();
	m_hasStarted = true;
}

void GameCore::Component::update(float deltaTime)
{
	if (!m_hasStarted) {
		start();
	}

	onUpdate(deltaTime);
}

void GameCore::Component::draw()
{
	onDraw();
}
