#include "Hero.h"

void Hero::Control(float time)
{
	float CurrentFrame = 0;
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
	    if((Keyboard::isKeyPressed(Keyboard::W)) && (onGround))
	    {
		    state = jump;
		    dy = -0.6;
		    onGround = false;
	    }
		if (Keyboard::isKeyPressed(Keyboard::S)) 
		{
			state = down;
		}
	}
}

void Hero::checkCollisionWithMap(float dx, float dy)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
				if (dy < 0) { y = i * 32 + 32;  dy = 0; }
				if (dx > 0) { x = j * 32 - w; }
				if (dx < 0) { x = j * 32 + 32; }
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
	checkCollisionWithMap(dx, 0);
	y += dy*time;
	checkCollisionWithMap(0, dy);
	sprite.setPosition(x + w / 2, y + h / 2);
	if (health <= 0) life = false;
	if (!isMove) speed = 0;
	dy += 0.0015 * time;

}
