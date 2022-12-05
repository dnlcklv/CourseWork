#pragma once
#include "Entity.h"
#include <list>

class Hero : public Entity
{
private:
	enum state { left, right, up, down, jump, stay } state;
	float CurrentFrame;
	View view;
	bool isMove;
public:
	Hero(float X, float Y);
	View getView();

	int getDirection();

	void setXY(float X, float Y);

	int getX();
	int getY();

	void Control(float time);
	void updateView(float X, float Y);
	void Animation(float time, int dir);

	void hit() override;
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

