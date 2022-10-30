#include <SFML/Graphics.hpp>

#include "Hero.h"
#include "Map.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"

using namespace sf;
int main()
{ 
	Map map;
	Hero hero(32,928,34,59);
	//EasyEnemy easyenemy(700,512,29,45);
	//MediumEnemy mediumenemy(600,512,29,45);
	//HardEnemy hardenemy(650, 512, 29, 45);
	Clock clock;
	RenderWindow window(sf::VideoMode(map.getWidth() * 32, map.getHeight() * 32), "sfml");

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		map.Draw(window);

		window.display();
	}

	return 0;
}