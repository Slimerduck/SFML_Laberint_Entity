#include "map.h"
#include "Ranger.h"

void Map::init() {
	player = new Player(Vector2f(70,70),"images/player1.png");
	for (int r = 0;r < HEIGHT_MAP;r++) {
		for (int c = 0;c < WIDTH_MAP;c++) {
			if (TileMap[r][c] == 'm')
			{
				Floor* floor = new Floor(Vector2f(c*60,r*60),"images/floor.png");
				entities.push_back(floor);
				Money* money = new Money(Vector2f(c*60,r*60), "images/coin.png");
				entities.push_back(money);
			}
			
			if (TileMap[r][c] == 'k') {
				Wall* wall = new Wall(Vector2f(c*60,r*60),"images/brick.png");
				entities.push_back(wall);
			}
			if (TileMap[r][c] == 'g') {
				Floor* floor = new Floor(Vector2f(c*60,r*60),"images/floor.png");
				entities.push_back(floor);
			}
			if (TileMap[r][c] == 'h') {
				Floor* floor = new Floor(Vector2f(c*60,r*60),"images/floor.png");
				entities.push_back(floor);
				Hp* hp = new Hp(Vector2f(c*60,r*60),"images/hp.png");
				entities.push_back(hp);
			}
			if (TileMap[r][c] == 'a'){
				Floor* floor = new Floor(Vector2f(c* 60,r * 60 ),"image/floor.png");
				entities.push_back(floor);
				Ranger* ranger = new Ranger(Vector2f(c* 60 + 60,r * 60 ),"image/ranger.png");
				entities.push_back(ranger);
				entities.push_back(ranger->getArrow());
			}
		}
	}
}
Map::Map() {
	init();
}
void Map::draw(RenderWindow &window) {
	for(auto it = entities.begin(); it != entities.end();it++){
		window.draw((*it)-> getSprite());
	}
	window.draw(player->getSprite());
}
void Map::update() {
	player->update();
	for(auto it = entities.begin(); it!= entities.end();it++){
		if((*it)->getName() == "ranger"){
			(*it)->update();
			Ranger* ranger =(Ranger*)(*it);
			ranger->collision(entities);
		}
	}
	for(auto it = entities.begin(); it!= entities.end();it++){
		FloatRect playerCollider = player-> getSprite().getGlobalBounds();
		FloatRect otherCollider = (*it)->getSprite().getGlobalBounds();
		if(playerCollider.intersects(otherCollider)&& (*it)->getName()== "money"){
			entities.erase(it++);
		}else if (playerCollider.intersects(otherCollider)&&(*it)->getName()=="wall"){
			player->setSpeed(Vector2f(-player->getSpeed().x,-player->getSpeed().y));
			player->update();
		}
	}
}
Player* Map::getPlayer() {
	return player;
}