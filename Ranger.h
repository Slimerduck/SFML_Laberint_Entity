#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Arrow.h"
#include <list>
using namespace sf;

class Ranger : public Entity{
    private:
        void init();
        bool isShot = false;
        Arrow* arrow;
        float currentFrame = 4;
        void animation();
        void shot();
        
    public:
        Ranger(Vector2f position,String imagePath);
        void update();
        void collision(std::list<Entity*> entities);
        Arrow* getArrow();
};