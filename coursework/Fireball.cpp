#include "Fireball.h"
void Fireball::CheckCollisionWithMap()
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if ((map.getTileMap(i, j) == '1') || (map.getTileMap(i, j) == '2'))
			{
				life = false;
			}
		}
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
	y += dy * time;
}