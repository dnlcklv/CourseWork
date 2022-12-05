#pragma once
#include "Enemy.h"
class EasyEnemy : public Enemy
{
public:
	EasyEnemy(float X, float Y) :Enemy(X, Y)
	{
		onGround = false;
		textureEntity.loadFromFile("images/EasyEnemy.png");
		spriteEntity.setTexture(textureEntity);
		spriteEntity.setOrigin(w / 2, h / 2);
		spriteEntity.setTextureRect(IntRect(57, 0, w, h));
		dx = 0.1;
		health = 1;
		for (int i = 1; i <= health; i++)
		{
			healths.push_back(spriteHealth);
		}
	}
};

