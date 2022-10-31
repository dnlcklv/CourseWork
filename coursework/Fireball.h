#pragma once
#include "Entity.h"

class Fireball : public Entity
{
	int direction;
public:
	Fireball(float X, float Y, int W, int H, int dir) : Entity(X, Y, W, H)
	{
		texture.loadFromFile("images/fireball.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(53, 52, W, H));
		direction = dir;
	}
	void CheckCollisionWithMap();
	void update(float time);



};

