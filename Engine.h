#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "map.h"
#include "KeyPressedAction.h"
#include "Camera.h"
using namespace sf;
using namespace std;


class Engine {
public:
	RenderWindow window;
	Map map;
	KeyPressedAction pressedAction;
	Engine();
	void init();
	void loop();
	void draw();
	void update();
	Camera* camera;
};





















