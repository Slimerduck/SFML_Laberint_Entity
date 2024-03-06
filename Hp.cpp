#include "Hp.h"

void Hp::init(){
    width = 60;
    height = 60;
}

Hp::Hp(Vector2f position, String imagePath) : Entity(imagePath){
    init();
    setPosition(position);
    setName("hp");
}