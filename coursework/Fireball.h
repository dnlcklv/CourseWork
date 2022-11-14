#pragma once
#include "Entity.h"

class Fireball : public Entity
{
	int direction;
public:
	Fireball(float X, float Y, int dir);
	void hit() override;
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

