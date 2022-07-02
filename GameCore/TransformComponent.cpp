#include "pch.h"
#include "TransformComponent.h"

GameMath::Matrix4 GameCore::TransformComponent::getGlobalMatrix()
{
	updateGlobalMatrix();
	return m_globalMatrix;
}

GameMath::Matrix4 GameCore::TransformComponent::getLocalMatrix()
{
	updateLocalMatrix();
	return m_localMatrix;
}

void GameCore::TransformComponent::setLocalPosition(GameMath::Vector3 position)
{
	m_translation = position;
	m_shouldUpdateLocal = true;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalPosition()
{
	return m_translation;
}

GameMath::Vector3 GameCore::TransformComponent::getGlobalPosition()
{
	updateGlobalMatrix();
	return GameMath::Vector3(m_globalMatrix.m03, m_globalMatrix.m13, m_globalMatrix.m23);
}

void GameCore::TransformComponent::setLocalRotation(GameMath::Vector3 rotation)
{
	m_rotation = rotation;
	m_shouldUpdateLocal = true;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalRotation()
{
	return m_rotation;
}

void GameCore::TransformComponent::setLocalScale(GameMath::Vector3 scale)
{
	m_scale = scale;
	m_shouldUpdateLocal = true;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalScale()
{
	return m_scale;
}

void GameCore::TransformComponent::setParent(TransformComponent* parent)
{
	m_parent = parent;
	m_shouldUpdateGlobal = true;
}

GameCore::TransformComponent* GameCore::TransformComponent::getParent()
{
	return m_parent;
}

void GameCore::TransformComponent::updateLocalMatrix()
{
	if (!m_shouldUpdateLocal)
		return;

	//Create translation matrix
	GameMath::Matrix4 translation = GameMath::Matrix4::createTranslation(m_translation);
	//Create rotation matrix
	GameMath::Matrix4 rotation = GameMath::Matrix4::createRotationX(m_rotation.x) * GameMath::Matrix4::createRotationY(m_rotation.y) * GameMath::Matrix4::createRotationZ(m_rotation.z);
	//Create scale matrix
	GameMath::Matrix4 scale = GameMath::Matrix4::createScale(m_scale);

	//Calculate local matrix
	m_localMatrix = translation * rotation * scale;

	//Flag global matrices for update
	m_shouldUpdateGlobal = true;
	for (TransformComponent* child : m_children) {
		child->m_shouldUpdateGlobal = true;
	}

	m_shouldUpdateLocal = false;
}

void GameCore::TransformComponent::updateGlobalMatrix()
{
	//Ensure local matrix is up-to-date
	updateLocalMatrix();

	if (!m_shouldUpdateGlobal)
		return;

	if (m_parent) {
		m_globalMatrix = m_parent->getGlobalMatrix() * m_localMatrix;
	}
	else {
		m_globalMatrix = m_localMatrix;
	}

	m_shouldUpdateGlobal = false;
}
