#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
protected:
	Vector2f position;
	Sprite sprite;
	Texture texture;
	Vector2f speed;
	int width = 80;
	int height = 120;
	String name;
	String imagePath;
	virtual void init();
	void dontMoveBehindMap();
public:
	Entity(String imagePath);
	void setPosition(Vector2f pos);
	void setTextureRect(IntRect rect);
	Vector2f getPosition();
	String getImagePath();
	Sprite getSprite();
	void setName(String name);
	String getName();
	virtual void update();
	void setWidth(int width);
	void setHeight(int height);
	int getWidth();
	int getHeight();
	void setImagePath(String imagePath);
};
