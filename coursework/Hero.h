#pragma once
#include "Entity.h"

class Hero : public Entity
{
private:
	enum { left, right, up, down, jump, stay } state;
	int playerScore;
	float CurrentFrame;
	View view;
	bool isMove;
public:
	Hero(float X, float Y);
	View getView();

	int getDirection();
	void setXY(float X, float Y);

	void Control(float time);
	void updateView(float X, float Y);
	void Animation(float time, int dir);

	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

