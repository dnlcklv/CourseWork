#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#include "Hero.h"
#include "Map.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Fireball.h"
using namespace sf;
int main()
{ 
	std::list <Entity*> entities;
	Map map;
	Hero hero(32,928);
	Clock clock;
	float time = 0;
	entities.push_back(new EasyEnemy(64, 928));
	RenderWindow window(sf::VideoMode(1440,940) , "sfml");
	std::list <Entity*>::iterator buf;
	bool select;
	while (window.isOpen())
	{
		select = false;
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		
		for (auto it = entities.begin(); it != entities.end(); it++) { (*it)->update(time); }
		hero.update(time);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::P)
					{
						entities.push_back(new Fireball(hero.getX(), hero.getY() - 5, hero.getDirection()));
					}
				}
		}
		window.setView(hero.getView());
		window.clear();
		map.Draw(window);
		for ( auto it = entities.begin(); it != entities.end(); it++) 
		{
			window.draw((*it)->getSprite());
		}
		for (auto it = entities.begin(); it != entities.end();it++) if (!(*it)->Life()) 
		{
			select = true;
			buf = it;
		}
		if (select) entities.erase(buf);
		window.draw(hero.getSprite());
		window.display();
	}
	return 0;
}