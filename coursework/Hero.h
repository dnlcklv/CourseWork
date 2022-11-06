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
	Hero(float X, float Y) :Entity(X, Y) 
	{
		w = 34; h = 59;
		CurrentFrame = 0;
		texture.loadFromFile("images/hero.png" );
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		playerScore = 0; state = stay;
		sprite.setTextureRect(IntRect(64, 126, w, h));
		isMove = false;
	}
	View getView() { return view; }
	int getDirection() { if (state == left) return 0; if (state == right) return 1; }
	void Control(float time);
	void updateView(float X, float Y);
	void Animation(float time, int dir);
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

