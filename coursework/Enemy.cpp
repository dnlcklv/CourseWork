#include "Enemy.h"

Enemy::Enemy(float X, float Y) :Entity(X, Y)
{
	name = "Enemy";
	w = 29; h = 45;
}
void Enemy::CheckColissionWithMapX(float& dx)
{
	for (int i = y / 32; i < (y + h) / 32;i++)
		for (int j = x / 32;j < (x + w) / 32;j++)
		{
			if (map.getTileMap(i, j) == '1' || map.getTileMap(i, j) == '2' || map.getTileMap(i, j) == '|')
			{
				if (dx > 0) { x = j * 32 - 32; dx *= -1;; }
				else if (dx < 0) { x = j * 32 + 32; dx *= -1; }
			}
		}
}
void Enemy::CheckColissionWithMapY(float& dy)
{
	for (int i = y / 32; i < (y + h) / 32;i++)
		for (int j = x / 32;j < (x + w) / 32;j++)
		{
			if (map.getTileMap(i, j) == '1' || map.getTileMap(i, j) == '2' || map.getTileMap(i, j) == '|')
			{
				if (dy > 0) { y = i * 32 - h; dy = 0; onGround = true; }
				if (dy < 0) { y = i * 32 + 32; dy = 0; onGround = false; }
			}
			else onGround = false;
			if (map.getTileMap(i, j) == ' ' || !onGround) dy = 0.5;
		}
}
void Enemy::hit()
{
	health--;
	healths.pop_back();
	if (health <= 0) life = false;
}
void Enemy::update(float time)
{
	int buf = 0;
	for (int i = 0; i < healths.size(); i++)
	{
		healths[i].setPosition(x + buf * 20, y - 10);
		buf++;
	}
	x += dx * time;
	CheckColissionWithMapX(dx);
	y += dy * time;
	CheckColissionWithMapY(dy);
	spriteEntity.setPosition(x + w / 2, y + h / 2);
	if (health <= 0) { life = false; }
}