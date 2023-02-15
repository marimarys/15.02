#include <SFML/Graphics.hpp> 
#include "settings.h" 
#include "roadobj.h" 
#include "car.h" 
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE,
		Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	window.setPosition(Vector2i{ (1440 - (int)WINDOW_WIDTH) / 2,0 });

	roadObj grass;
	roadObjInit(grass, Vector2f{ 0.f,0.f }, "лес.jpg", 0.f);

	roadObj road;
	roadObjInit(road, Vector2f{ 200.f, 0.f }, "road (1).jpg", 200.f);

	roadObj road2;
	roadObjInit(road2, Vector2f{ 200.f, -800.f }, "road (1).jpg", 200.f);

	roadObj grass2;
	roadObjInit(grass2, Vector2f{ 0.f, -800.f }, "лес.jpg", 0.f);

	Player player;
	playerObjInit(player);




	while (window.isOpen())
	{
		// 1. обработка событий 
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//обновление игровых объектов (функции update) 
		roadObjUpdate(road);
		roadObjUpdate(grass);
		roadObjUpdate(road2);
		roadObjUpdate(grass2);
		playerObjUpdate(player);
		obstcleUpdate(obs1);
		//Проверка столкновений
		if(player.sprite.getGlobalBounds().intersects
			(obs1.sprite.getGlobalBounds))

		// отрисовка объектов и обновление окна 
		window.clear();

		roadObjDraw(window, grass2);
		roadObjDraw(window, grass);
		roadObjDraw(window, road2);
		roadObjDraw(window, road);
		playerObjDraw(window, player);
		//window.draw(shape); 
		window.display();
	}

	return 0;
}