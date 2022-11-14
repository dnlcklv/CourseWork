#pragma once
#include "Enemy.h"

class MediumEnemy : public Enemy
{
public:
	MediumEnemy(float X, float Y) : Enemy(X, Y)
	{
		texturEntity.loadFromFile("images/MediumEnemy.png");
		spriteEntity.setTexture(texturEntity);
		spriteEntity.setOrigin(w / 2, h / 2);
		spriteEntity.setTextureRect(IntRect(51, 0, w, h));
		dx = 0.15;
		health = 3;
		for (int i = 1; i <= health; i++)
		{
			healths.push_back(spriteHealth);
		}
	}
};

