#include "Map.h"
void drawMap(sf::RenderWindow& window)
{
	Texture map;
	map.loadFromFile("images/map.png");
	Sprite s_map;
	s_map.setTexture(map);
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 773, 64, 64));
			if ((TileMap[i][j] == ' ')) s_map.setTextureRect(IntRect(72, 773, 64, 64));


			s_map.setPosition(j * 32, i * 32);

			window.draw(s_map);
		}
}