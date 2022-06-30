#pragma once

namespace GameCore {
	class Scene;

	class Engine
	{
	public:
		Engine(const char* title, int width = 800, int height = 600);

		void run();

		void setCurrentScene(Scene* scene) { m_currentScene = scene; }
		Scene* getCurrentScene() { return m_currentScene; }

	private:
		void start();
		void update(float deltaTime);
		void draw();
		void end();

	private:
		int m_width, m_height;
		const char* m_title;
		Scene* m_currentScene = nullptr;
	};
}
