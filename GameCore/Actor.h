#pragma once
#include <forward_list>

namespace GameCore {
	class Component;

	class Actor
	{
	public:
		Actor();

		void start();
		void update(float deltaTime);
		void draw();

		/// <summary>
		/// Called before the first update for this Actor. Override this function.
		/// </summary>
		virtual void onStart() {}
		/// <summary>
		/// Called each update loop for this Actor. Override this function.
		/// </summary>
		/// <param name="deltaTime">The time since the previous update.</param>
		virtual void onUpdate(float deltaTime) {}
		/// <summary>
		/// Called each loop after update. Override this function.
		/// </summary>
		virtual void onDraw() {}

		void addComponent(Component* component);
		void removeComponent(Component* component);

	private:
		bool m_hasStarted = false;
		std::forward_list<Component*> m_components;
	};
}
