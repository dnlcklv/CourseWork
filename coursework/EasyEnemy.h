#pragma once
#include "Enemy.h"
class EasyEnemy : public Enemy
{
public:
	EasyEnemy(float X, float Y, int W, int H) :Enemy(X, Y, W, H)
	{
		texture.loadFromFile("images/EasyEnemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(57, 0, W, H));
		dx = -0.1;
	}

};

