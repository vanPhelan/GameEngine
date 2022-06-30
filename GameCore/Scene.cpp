#include "pch.h"
#include "Scene.h"
#include "Actor.h"

GameCore::Scene::Scene()
{
}

void GameCore::Scene::start()
{
	onStart();
	m_hasStarted = true;
}

void GameCore::Scene::update(float deltaTime)
{
	if (!m_hasStarted) {
		start();
	}

	onUpdate(deltaTime);

	for (Actor* actor : m_actors) {
		actor->update(deltaTime);
	}
}

void GameCore::Scene::draw()
{
	onDraw();

	for (Actor* actor : m_actors) {
		actor->draw();
	}
}

void GameCore::Scene::addActor(Actor* actor)
{
	m_actors.push_front(actor);
}

void GameCore::Scene::removeActor(Actor* actor)
{
	m_actors.remove(actor);
}
