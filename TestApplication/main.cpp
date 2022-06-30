#include <Engine.h>
#include <Scene.h>
#include <Actor.h>
#include <CircleComponent.h>

int main() {
	GameCore::Engine game = GameCore::Engine("Test Application");
	GameCore::Scene* scene = new GameCore::Scene();
	GameCore::Actor* actor = new GameCore::Actor();
	GameCore::CircleComponent* circle = new GameCore::CircleComponent(25.0f);

	actor->addComponent(circle);
	scene->addActor(actor);
	game.setCurrentScene(scene);

	game.run();

	delete circle;
	delete actor;
	delete scene;

	return 0;
}