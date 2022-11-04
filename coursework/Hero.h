#pragma once
#include "Entity.h"

class Hero : public Entity
{
private:
	enum { left, right, up, down, jump, stay } state;
	int playerScore;
	float CurrentFrame;
	View view;
public:
	Hero(float X, float Y, int W, int H) :Entity(X, Y, W, H) 
	{
		CurrentFrame = 0;
		texture.loadFromFile("images/hero.png" );
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
		playerScore = 0; state = stay;
		sprite.setTextureRect(IntRect(64, 126, W, H));
	}
	View getView() { return view; }
	void Control(float time);
	void updateView(float X, float Y);
	void CheckColissionWithMapX(float& dx) override;
	void CheckColissionWithMapY(float& dy) override;
	void update(float time) override;
};

