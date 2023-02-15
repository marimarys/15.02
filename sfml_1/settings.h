#pragma once 
#include <string> 

//ÊÎÍÑÒÀÍÒÛ 
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 800.f };
const std::string WINDOW_TITLE{ "SFML Lesson3" };
const unsigned int FPS{ 60 };

float ROAD_SPEEDY = 5.f;
const std::string PLAYER_FILE_NAME{ "CAR1.png" };
const float PLAYER_WIDTH = 150.f;
const float PLAYER_HEIGHT = 150.f;
sf::Vector2f PLAYER_START_POS{ (WINDOW_WIDTH - PLAYER_WIDTH) / 2.f,WINDOW_HEIGHT - PLAYER_HEIGHT };

float PLAYER_SPEEDY = 5.f;
float PLAYER_SPEEDX = 5.f;

const sf::Vector2f ROAD_POS{ 190.f, 0.f };