#pragma once 
#include "settings.h" 

struct Player {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedy;
	float speedx;
};
void playerObjInit(Player& player) {
	player.texture.loadFromFile(PLAYER_FILE_NAME);
	player.sprite.setTexture(player.texture);
	player.sprite.setPosition(PLAYER_START_POS);
	player.speedy = 0.f;
}
void playerControl(Player& player) {
	player.speedx = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.speedx = -PLAYER_SPEEDX;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.speedx = PLAYER_SPEEDX;
	}
	player.sprite.move(player.speedx, 0.f);
}
void playerObjUpdate(Player& player) {
	playerControl(player);
	if (player.sprite.getPosition().x < ROAD_POS.x) {
		player.sprite.setPosition(ROAD_POS.x, 650.f);
	}
	if (player.sprite.getPosition().x > ROAD_POS.x + 300.f) {
		player.sprite.setPosition(ROAD_POS.x + 300.f, 650.f);
	}
}
void playerObjDraw(sf::RenderWindow& window, const Player& player) {
	window.draw(player.sprite);
}