#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#include "Hero.h"
#include "Map.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Fireball.h"
//w=58 h=928
using namespace sf;
int main()
{ 
	Map map;
	Hero hero(32,928,34,59);
	Clock clock;
	float time = 0;

	RenderWindow window(sf::VideoMode(1440,940) , "sfml");
	while (window.isOpen())
	{

		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		
		//for (it = entities.begin(); it != entities.end(); it++) (*it)->update(time);

		hero.update(time);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.setView(hero.getView());
		window.clear();

		map.Draw(window);
		window.draw(hero.getSprite());
		

		window.display();
	}
	return 0;
}