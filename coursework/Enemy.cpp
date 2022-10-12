#include "Enemy.h"

void Enemy::checkCollisionWithMap(float dx, float dy)
{
	for (int i = y / 32; i < (y + h) / 32;i++)
		for (int j = x / 32;j < (x + w) / 32;j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (dy > 0) { y = i * 32 - h; }
				if (dy < 0) { y = i * 32 + 32; }
				if (dx > 0) { x = j * 32 - w; dx *=-1; }
				if (dx < 0) { x = j * 32 + 32; dx *=1; }
			}
		}
}
void Enemy::update(float time)
{
	moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }
	checkCollisionWithMap(dx,0);
	x += dx * time;
	sprite.setPosition(x + w / 2, y + h / 2); 
	if (health <= 0) { life = false; }
}
