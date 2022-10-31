#include <SFML/Graphics.hpp>
#include <vector>

#include "Hero.h"
#include "Map.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Fireball.h"

using namespace sf;
int main()
{ 
	std::vector<Entity> entities;
	Map map;
	Hero hero(32,928,34,59);
	//EasyEnemy easyenemy(700,512,29,45);
	//MediumEnemy mediumenemy(600,512,29,45);
	//HardEnemy hardenemy(650, 512, 29, 45);
	Clock clock;
	float time = 0;
	RenderWindow window(sf::VideoMode(map.getWidth() * 32, map.getHeight() * 32), "sfml");
	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		
		hero.update(time);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		map.Draw(window);
		window.draw(hero.getSprite());
		

		window.display();
	}
	return 0;
}