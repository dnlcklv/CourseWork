#include "Hero.h"

Hero::Hero(float X, float Y) : Entity(X, Y)
{
	name = "hero";
	w = 34; h = 59;
	CurrentFrame = 0;
	texture.loadFromFile("images/hero.png");
	sprite.setTexture(texture);
	sprite.setOrigin(w / 2, h / 2);
	playerScore = 0; state = stay;
	sprite.setTextureRect(IntRect(64, 126, w, h));
	isMove = false;
}

void Hero::Animation(float time, int dir) 
{
	if (dir == 1)
	{
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 62, w, h));
	}
	else 
	{
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 127, w, h));
	}
}



void Hero::Control(float time)
{
	if (Keyboard::isKeyPressed)
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
		    Animation(time, 1);
			state = left; speed = 0.15;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			Animation(time, 2);
			state = right; speed = 0.15;
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
			if (map.getTileMap(i,j) == '1' || map.getTileMap(i,j) == '2' || map.getTileMap(i, j) == '|')
			{
				if (dx > 0) { x = j * 32 - w; }
				if (dx < 0) { x = j * 32 + 32; }
			}
			if (map.getTileMap(i, j) == '3') 
			{
				life = false; 
				if (dx > 0) { x = j * 32 - w; }
				if (dx < 0) { x = j * 32 + 32; }
			}
		}
}
void Hero::CheckColissionWithMapY(float& dy)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (map.getTileMap(i, j) == '1' || map.getTileMap(i, j) == '|')
			{
				if (dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
				if (dy < 0) { y = i * 32 + h; dy = 0; }
			}
			if (map.getTileMap(i, j) == '2') dy = -1.1;
			if (map.getTileMap(i, j) == '3') 
			{
				if (dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
				if (dy < 0) { y = i * 32 + h; dy = 0; }
				life = false; 
			}
		}
}

void Hero::updateView(float X, float Y) 
{
	view.reset(FloatRect(0,0,1000,900));
	view.setCenter(x+100, y-150);
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
	if (life = false) { sprite.setRotation(10); }
	if (!isMove) speed = 0;
	dy += 0.0015 * time;
	updateView(x, y);
}

View Hero::getView()
{
	return view;
}

int Hero::getDirection()
{
	{ if (state == left) return 0; if (state == right) return 1; }
}

void Hero::setXY(float X, float Y)
{
	x = X;
	y = Y;
}

