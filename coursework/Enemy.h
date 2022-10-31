#pragma once
#include "Entity.h"


class Enemy : public Entity  
{
public:
	Enemy(float X, float Y, int W, int H) :Entity(X, Y, W, H) 
	{
	}
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

