#pragma once
#include "Enemy.h"
class HardEnemy:public Enemy
{
public:
	HardEnemy(float X, float Y) :Enemy(X, Y)
	{
		textureEntity.loadFromFile("images/HardEnemy.png");
		spriteEntity.setTexture(textureEntity);
		spriteEntity.setOrigin(w / 2, h / 2);
		spriteEntity.setTextureRect(IntRect(53, 0, w, h));
		dx = 0.17;
		health = 5;
		for (int i = 1; i <= health; i++)
		{
			healths.push_back(spriteHealth);
		}
	}
};

