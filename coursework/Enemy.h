#pragma once
#include "Entity.h"


class Enemy : public Entity  
{
public:
	Enemy(float X, float Y) :Entity(X, Y)
	{
		name = "Enemy";
		w = 29; h = 45;
	}
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

