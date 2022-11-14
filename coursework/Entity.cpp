#include "Entity.h"
Entity:: Entity(float X, float Y)
{
	health = 100;
	x = X;  dx = 0;
	y = Y;  dy = 0;
	speed = 0;
	life = true; onGround = false;
	bufHealth = health;
	textureHealth.loadFromFile("images/hearth.png");
	spriteHealth.setTexture(textureHealth);
}

void Entity::drawSprite(RenderWindow& window)
{
	window.draw(spriteEntity);
	for (int i = 0; i < healths.size(); i++)
	{
		window.draw(healths[i]);
	}
}
void Entity::setDx(float value)
{
	dx = value;
}
float Entity::getDx()
{
	return dx;
}


Sprite Entity:: getSprite()
{
	return spriteEntity;
}
bool Entity:: getLife()
{
	return life;
}
void Entity:: setLife(bool value)
{
	life = value;
}
std::string  Entity::getName()
{
	return name;
}