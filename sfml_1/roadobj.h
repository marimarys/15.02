#pragma once 
#include "settings.h" 
#include "SFML/Graphics.hpp" 
struct roadObj {
	sf::Texture texture;
	sf::Sprite sprite;
	float offset;
};
void roadObjInit(roadObj& obj, sf::Vector2f pos, std::string fileName, float offset) {
	obj.texture.loadFromFile(fileName);
	//obj.texture.setRepeated(true); 
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
	obj.offset = offset;

}
void roadObjUpdate(roadObj& obj) {
	obj.sprite.move(0, ROAD_SPEEDY);
	if (obj.sprite.getPosition().y >= WINDOW_HEIGHT) {
		obj.sprite.setPosition(obj.offset, -WINDOW_HEIGHT);
	}
}

void roadObjDraw(sf::RenderWindow& window, const roadObj& obj) {
	window.draw(obj.sprite);
}