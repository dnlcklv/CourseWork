#include "Fireball.h"
void Fireball::CheckColissionWithMapX(float& dx)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (map.getTileMap(i, j) == '1')
			{
				if (dx > 0) { x = j * 32 - 32; dx *=-1; speed = 0; life = false; std::cout << "stuk"; }
				else if (dx < 0) { x = j * 32 + 32; dx *= -1; speed = 0; life = false; std::cout << "stuk";}
				std::cout << "stuk";
			}
		}

}
void Fireball::CheckColissionWithMapY(float& dy) 
{

}
void Fireball::update(float time)
{
	switch (direction)
	{
	case 0:
	{
		dx = -speed;
		break;
	}
	case 1:
	{
		dx = speed;
		break;
	}
	}
	x += dx * time;
	CheckColissionWithMapX(dx);
	sprite.setPosition(x + w / 2, y + h / 2);
}