#pragma once
#include "Entity.h"

class Hero : public Entity
{
private:
	enum { left, right, up, down, jump, stay } state;
	int playerScore;
public:
	Hero(float X, float Y, int W, int H) :Entity(X, Y, W, H) 
	{
		texture.loadFromFile("images/hero.png" );
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		playerScore = 0; state = stay;
		sprite.setTextureRect(IntRect(64, 126, W, H));
	}
	void Control(float time);
	void checkCollisionWithMap(float dx, float dy);
	void update(float time);


};

