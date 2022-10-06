﻿#include <SFML/Graphics.hpp>

#include "Hero.h"
#include "Map.h"
using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(1920, 1080), "sfml");
     
	Hero hero(512,512,34,59);

	Clock clock;


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
		
		hero.update(time);
		window.clear();
		//Texture map;
		//map.loadFromFile("images/map.png");
		//Sprite s_map;
		//s_map.setTexture(map);
		//for (int i = 0; i < HEIGHT_MAP; i++)
		//	for (int j = 0; j < WIDTH_MAP; j++)
		//	{
		//		if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 773, 64, 64));
		//		if ((TileMap[i][j] == ' ')) s_map.setTextureRect(IntRect(72, 773, 64, 64));


		//		s_map.setPosition(j * 32, i * 32);
		//		/*window.draw(s_map);*/
		//	}
		window.draw(hero.getSprite());

		window.display();
	}

	return 0;
}