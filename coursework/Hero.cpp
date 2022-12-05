#include "Hero.h"

Hero::Hero(float X, float Y) : Entity(X, Y)
{
	name = "hero";
	w = 34; h = 59;
	CurrentFrame = 0;
	textureEntity.loadFromFile("images/hero.png");
	spriteEntity.setTexture(textureEntity);
	spriteEntity.setOrigin(w / 2, h / 2);
	state = stay;
	health = 3;
	spriteEntity.setTextureRect(IntRect(64, 126, w, h));
	isMove = false;
	for (int i = 1; i <= health; i++)
	{
		healths.push_back(spriteHealth);
	}
}

void Hero::hit()
{

	health--;
	if (healths.size() != 0) healths.pop_back();
	if (health <= 0) life = false;
}

void Hero::Animation(float time, int dir) 
{
	if (dir == 1)
	{
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		spriteEntity.setTextureRect(IntRect(64 * int(CurrentFrame), 62, w, h));
	}
	else 
	{
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		spriteEntity.setTextureRect(IntRect(64 * int(CurrentFrame), 127, w, h));
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
				life = false; 
			}
		}
}

void Hero::updateView(float X, float Y) 
{
	view.reset(FloatRect(0, 0, 1000, 900));
	view.setCenter(x + 100, y  -150);
}
void Hero::update(float time)
{
	if (life)
	{
		Control(time);
	}
		int buf = 0;
		for (int i = 0; i < healths.size(); i++)
		{
			healths[i].setPosition(x + buf * 20, y - 10);
			buf++;
		}
		switch (state)
		{
		case right:dx = speed; break;
		case left:dx = -speed; break;
		case up: break;
		case down: dx = 0; break;
		case stay: break;
		}
		x += dx * time;
		CheckColissionWithMapX(dx);
		y += dy * time;
		CheckColissionWithMapY(dy);
		spriteEntity.setPosition(x + w / 2, y + h / 2);
		if (!isMove) speed = 0;
		dy += 0.0015 * time;
		updateView(x, y);
	if (!life)
	{
		spriteEntity.setRotation(90);
		speed = 0;
		for (int i = 0; i < healths.size(); i++)
		{
			healths.pop_back();
		}
	}
	if (health <= 0)
	{
		life = false; 
	}
}

View Hero::getView()
{
	return view;
}

int Hero::getDirection()
{
	{ if (state == left) return 0; if (state == right) return 1; }
}

int Hero::getX() 
{
	return x;
}
int Hero::getY() 
{
	return y;
}

void Hero::setXY(float X, float Y)
{
	x = X;
	y = Y;
}

