#include <list>
#include <vector>

#include "Hero.h"
#include "Map.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Fireball.h"
#include "Menu.h"
using namespace sf;
int main()
{ 
	Texture background;
	background.loadFromFile("images/menu/3.jpg");
	Sprite bg;
	bg.setTexture(background);

	

	std::list <Entity*> entities;
	std::list <Entity*>::iterator buf;

	Map map;
	Hero hero(0,0);
	Clock clock;

	float time = 0;
	bool select;


	for (int i = 0; i < map.getHeight(); i++)
		for (int j = 0; j < map.getWidth(); j++) 
		{
			if (map.getTileMap(i, j) == 'z') entities.push_back(new EasyEnemy(j * 32, i * 32));
			if (map.getTileMap(i, j) == 'x') entities.push_back(new MediumEnemy(j * 32, i * 32));
			if (map.getTileMap(i, j) == 'c') entities.push_back(new HardEnemy(j * 32, i * 32));
			if (map.getTileMap(i, j) == 'w') { hero.setXY(j * 32, i * 32); }
		}

	RenderWindow window(sf::VideoMode(1440, 940), "sfml");
	menu(window);
	while (window.isOpen())
	{
		select = false;
		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->update(time);

			if (!(*it)->getLife())
			{
				select = true;
				buf = it;
			}

			if (hero.getSprite().getGlobalBounds().intersects((*it)->getSprite().getGlobalBounds()) && (*it)->getName() == "Enemy")
			{
				(*it)->setDx((*it)->getDx() * -1);
				hero.hit();
			}

			for (auto it1 = entities.begin(); it1 != entities.end(); it1++)
			{
				if ((*it)->getName() == "Enemy" && (*it1)->getName() == "Fireball")
				{
					if ((*it)->getSprite().getGlobalBounds().intersects((*it1)->getSprite().getGlobalBounds()))
					{
						(*it)->hit();
						(*it1)->setLife(false);
					}
				}
			}
		}

		if (select) entities.erase(buf);

		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		
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
		bg.setTextureRect(IntRect(269, 73, 1440, 940));
		bg.setOrigin(720, 650);
		bg.setPosition(hero.getSprite().getPosition());

		window.setView(hero.getView());
		window.clear();
		window.draw(bg);
		map.Draw(window);
		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->drawSprite(window);
		}
		hero.drawSprite(window);
		window.display();
	}

	return 0;
}