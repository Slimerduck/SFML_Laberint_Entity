#include "Engine.h"




Engine::Engine() {
	init();
}



void Engine::init() {
	window.create(sf::VideoMode(1260, 720), "Game");
	pressedAction.setPlayer(map.getPlayer());
	camera = new Camera(map.getPlayer());
}
void Engine::loop() {
	while (window.isOpen()) {
		Event event;
		while(window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		draw();
		update();
	}
}
void Engine::draw() {
	window.clear(Color(100, 150, 50));
	window.setView(camera->getView());
	map.draw(window);
	window.display();
}
void Engine::update() {
	pressedAction.action();
	map.update();
	camera->update();
}






















