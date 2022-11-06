#pragma once
#include "Entity.h"

class Fireball : public Entity
{
	int direction;
public:
	Fireball(float X, float Y, int dir) : Entity(X, Y)
	{
		w = 38;
		h = 20;
		texture.loadFromFile("images/fireball.png");
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(IntRect(53, 52, w, h));
		direction = dir;
		speed = 0.5;
		dx = speed;
	}
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;



};

