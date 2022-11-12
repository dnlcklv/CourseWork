#pragma once
#include "Enemy.h"

class MediumEnemy : public Enemy
{
public:
	MediumEnemy(float X, float Y) : Enemy(X, Y)
	{
		texture.loadFromFile("images/MediumEnemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(51, 0, w, h));
		dx = 0.15;
		health = 3;
	}
};

