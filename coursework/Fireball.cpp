#include "Fireball.h"

Fireball::Fireball(float X, float Y, int dir) : Entity(X, Y)
{
	name = "Fireball";
		w = 38;
		h = 20;
		texture.loadFromFile("images/fireball.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(53, 52, w, h));
		direction = dir;
		speed = 0.3;
		dy = 0.07;
		dx = speed;
}

void Fireball::CheckColissionWithMapX(float& dx)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (map.getTileMap(i, j) == '1' || map.getTileMap(i,j) == '|')
			{
				if (dx > 0) {  life = false; }
				else if (dx < 0) { life = false;}
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
	y += dy * time;

	sprite.setPosition(x + w / 2, y + h / 2);
}