#include "pch.h"
#include "Actor.h"
#include "Component.h"

GameCore::Actor::Actor()
{
}

void GameCore::Actor::start()
{
	onStart();
	m_hasStarted = true;
}

void GameCore::Actor::update(float deltaTime)
{
	if (!m_hasStarted) {
		start();
	}

	onUpdate(deltaTime);

	for (Component* component : m_components) {
		component->update(deltaTime);
	}
}

void GameCore::Actor::draw()
{
	onDraw();

	for (Component* component : m_components) {
		component->draw();
	}
}

void GameCore::Actor::addComponent(Component* component)
{
	m_components.push_front(component);
}

void GameCore::Actor::removeComponent(Component* component)
{
	m_components.remove(component);
}
