#pragma once
#include "settings.h"

struct Obstacle {
	sf::Texture texture;
	sf::Sprite sprite;
};

void obstacleInit(Obstacle& obs, std::string fileName) {
	obs.texture.loadFromFile(fileName);
	obs.sprite.setTexture(obs.texture);
	int posx = rand() % 301 + 100;
	posx = posx - posx % 100;
	/*
	int c = rand()%4;
	if (c == 0) posx =100;
	else if (c==1) posx = 200;
	*/
	int posy = rand() % 201 - 1000;
	obs.sprite.setPosition(posx, posy);
}
	void obstacleUpdate(Obstacle & obs) {
		obs.sprite.move(0.f, 2.f);
		if (obs.sprite.getPosition().y >= WINDOW_HEIGHT) {
			int posx = rand() % 301 + 100;
			posx = posx - posx % 100;
			int posy = rand() % 201 - 1000;
			obs.sprite.setPosition(posx, posy);
		}
	}
	
	void obstacleDraw(sf::RenderWindow& window, const Obstacle& obs) {
		window.draw(obs.sprite);
	}
}
