#pragma once
#include "Entity.h"


class Enemy : public Entity  
{
public:
	Enemy(float X, float Y);
	void hit() override;
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

