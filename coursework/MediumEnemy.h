#pragma once
#include "Enemy.h"

class MediumEnemy : public Enemy
{
public:
	MediumEnemy(float X, float Y, float W, float H) : Enemy(X,Y)
	{
		texture.loadFromFile("images/MediumEnemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(51, 0, W, H));
		dx = -0.1;
	}

};

