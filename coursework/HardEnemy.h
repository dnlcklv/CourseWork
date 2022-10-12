#pragma once
#include "Enemy.h"
class HardEnemy:public Enemy
{
public:
	HardEnemy(float X, float Y, int W, int H) :Enemy(X, Y, W, H)
	{
		texture.loadFromFile("images/HardEnemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(53, 0, W, H));
		dx = 0.1;
	}
};

