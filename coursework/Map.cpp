#include "Map.h"

Map::Map() 
{
	mapTexture.loadFromFile("images/map.png");
	mapSprite.setTexture(mapTexture);;
}
void Map::Draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j <= width; j++)
		{
			if (tileMap[i][j] == ' ' || tileMap[i][j] == '|' || tileMap[i][j] == 'z' || tileMap[i][j] == 'x' || tileMap[i][j] == 'c') mapSprite.setTextureRect(IntRect(0, 152, 32, 32));
			if (tileMap[i][j] == '1') mapSprite.setTextureRect(IntRect(127, 58, 32, 32));
			if (tileMap[i][j] == '2') mapSprite.setTextureRect(IntRect(385, 85, 32, 32));
			if (tileMap[i][j] == '3') mapSprite.setTextureRect(IntRect(32, 31, 32, 32));
			if (tileMap[i][j] == '4') mapSprite.setTextureRect(IntRect(31, 290, 32, 32));
			if (tileMap[i][j] == '5') mapSprite.setTextureRect(IntRect(94, 222, 32, 32));
			if (tileMap[i][j] == '6') mapSprite.setTextureRect(IntRect(64, 257, 32, 32));
			if (tileMap[i][j] == '7') mapSprite.setTextureRect(IntRect(94, 191, 32, 32));
			if (tileMap[i][j] == '8') mapSprite.setTextureRect(IntRect(62, 191, 32, 32));
			if (tileMap[i][j] == '9') mapSprite.setTextureRect(IntRect(161, 191, 32, 32));
			if (tileMap[i][j] == '0') mapSprite.setTextureRect(IntRect(192, 289, 32, 32));
			if (tileMap[i][j] == 'q') mapSprite.setTextureRect(IntRect(161, 222, 32, 32));
			if (tileMap[i][j] == 'w') mapSprite.setTextureRect(IntRect(256, 258, 32, 32));
			if (tileMap[i][j] == 'e') mapSprite.setTextureRect(IntRect(288, 258, 32, 32));
			if (tileMap[i][j] == 'r') mapSprite.setTextureRect(IntRect(256, 223, 32, 32));
			if (tileMap[i][j] == 't') mapSprite.setTextureRect(IntRect(288, 223, 32, 32));
			if (tileMap[i][j] == 'y') mapSprite.setTextureRect(IntRect(256, 191, 32, 32));
			if (tileMap[i][j] == 'u') mapSprite.setTextureRect(IntRect(288, 191, 32, 32));
			if (tileMap[i][j] == 'i') mapSprite.setTextureRect(IntRect(96, 288, 32, 32));
			if (tileMap[i][j] == 'o') mapSprite.setTextureRect(IntRect(128, 256, 32, 32));

			mapSprite.setPosition(j * 32, i * 32);
			window.draw(mapSprite);
		}
}
int Map::getHeight() 
{
	return height;
}
int Map::getWidth() 
{
	return width;
}
char Map::getTileMap(int i, int j) 
{
	return tileMap[i][j];
}

