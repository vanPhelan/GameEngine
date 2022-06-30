#pragma once
#include <forward_list>

namespace GameCore {
	class Actor;

	class Scene
	{
	public:
		Scene();

		void start();
		void update(float deltaTime);
		void draw();

		/// <summary>
		/// Called before the first update for this Scene. Override this function.
		/// </summary>
		virtual void onStart() {}
		/// <summary>
		/// Called each update loop for this Scene. Override this function.
		/// </summary>
		/// <param name="deltaTime">The time since the previous update.</param>
		virtual void onUpdate(float deltaTime) {}
		/// <summary>
		/// Called each loop after update. Override this function.
		/// </summary>
		virtual void onDraw() {}

		void addActor(Actor* actor);
		void removeActor(Actor* actor);

	private:
		bool m_hasStarted = false;
		std::forward_list<Actor*> m_actors;
	};
}
