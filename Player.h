#pragma once
#include <SFML/Graphics.hpp>
#include "MoveEntity.h"
using namespace sf;

class Player: public MoveEntity {
private:
	void init();
	void dontMoveBehindMap();
public:
	Player(Vector2f position,String imagePath);
	float currentFrame = 0;
	void update();
};
//change speed









































