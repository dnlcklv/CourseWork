#include "Hero.h"

void Hero::Control(float time)
{
	if (Keyboard::isKeyPressed)
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 62, w, h));
			state = left; speed = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 127, w, h));
			state = right; speed = 0.1;
		}
		if ((Keyboard::isKeyPressed(Keyboard::W)) && (onGround))
		{
			state = jump;
			dy = -0.6;
			onGround = false;
		}
	}
}
void Hero::CheckColissionWithMapX(float& dx)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if ((map.getTileMap(i,j) == '1') || (map.getTileMap(i,j) == '2'))
			{
				if (dx > 0) { x = j * 32 - w; }
				if (dx < 0) { x = j * 32 + w; }
			}
			else { onGround = false; } 
		}
}
void Hero::CheckColissionWithMapY(float& dy)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if ((map.getTileMap(i, j) == '1') || (map.getTileMap(i, j) == '2'))
			{
				if (dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
				if (dy < 0) { y = i * 32 + 32; dy = 0; }
			}
			else { onGround = false; }
		}
}
void Hero::update(float time)
{
	Control(time);
	switch (state)
	{
	case right:dx = speed; break;
	case left:dx = -speed; break;
	case up: break;
	case down: dx = 0; break;
	case stay: break;
	}
	x += dx*time;
	CheckColissionWithMapX(dx);
	y += dy*time;
	CheckColissionWithMapY(dy);
	sprite.setPosition(x + w / 2, y + h / 2);
	if (health <= 0) life = false;
	if (!isMove) speed = 0;
	dy += 0.0015 * time;

}


