#pragma once

namespace GameCore {
	class Actor;

	class Component
	{
	public:
		Component();

		void start();
		void update(float deltaTime);
		void draw();

		/// <summary>
		/// Called before the first update for this Component. Override this function.
		/// </summary>
		virtual void onStart() {}
		/// <summary>
		/// Called each update loop for this Component. Override this function.
		/// </summary>
		/// <param name="deltaTime">The time since the previous update.</param>
		virtual void onUpdate(float deltaTime) {}
		/// <summary>
		/// Called each loop after update. Override this function.
		/// </summary>
		virtual void onDraw() {}

	private:
		void setOwner(Actor* owner) { m_owner = owner; }
		Actor* getOwner() { return m_owner; }

	private:
		bool m_hasStarted = false;
		Actor* m_owner = nullptr;

		friend Actor;
	};
}
