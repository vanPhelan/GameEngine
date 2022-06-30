#include "pch.h"
#include "Engine.h"
#include "Scene.h"
#include <raylib.h>
#include <ctime>

GameCore::Engine::Engine(const char* title, int width, int height)
{
	m_title = title;
	m_width = width;
	m_height = height;
}

void GameCore::Engine::run()
{
	start();

	//Main loop
	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();

		update(deltaTime);
		draw();
	}

	end();
}

void GameCore::Engine::start()
{
	//Initialize window
	InitWindow(m_width, m_height, m_title);
	SetTargetFPS(0);
}

void GameCore::Engine::update(float deltaTime)
{
	m_currentScene->update(deltaTime);
}

void GameCore::Engine::draw()
{
	BeginDrawing();

	ClearBackground(DARKBROWN);

	m_currentScene->draw();

	EndDrawing();
}

void GameCore::Engine::end()
{
	//Close window
	CloseWindow();
}
