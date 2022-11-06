#pragma once
#include "Enemy.h"
class EasyEnemy : public Enemy
{
public:
	EasyEnemy(float X, float Y) :Enemy(X, Y)
	{
		w = 20; h = 45;
		onGround = false;
		texture.loadFromFile("images/EasyEnemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(57, 0, w, h));
		dx = 0.1;
	}

};

