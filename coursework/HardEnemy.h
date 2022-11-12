#pragma once
#include "Enemy.h"
class HardEnemy:public Enemy
{
public:
	HardEnemy(float X, float Y) :Enemy(X, Y)
	{
		texture.loadFromFile("images/HardEnemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(53, 0, w, h));
		dx = 0.17;
		health = 5;
	}
};

