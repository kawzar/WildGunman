#include "Enemy.h"



Enemy::Enemy()
{
	_isAlive = true;
	_isShowing = false;
	_tx.loadFromFile("Images/enemy4.png");
	_sprite.setTexture(_tx);
	_sprite.setOrigin(_tx.getSize().x / 2, _tx.getSize().y);
}


Enemy::~Enemy()
{
}

bool Enemy::IsAlive()
{
	return _isAlive;
}

bool Enemy::IsShowing()
{
	return _isShowing;
}

void Enemy::Show(Vector2f position)
{
	_isShowing = true;
	_sprite.setPosition(position);
}

void Enemy::Draw(RenderWindow * window)
{
	if (_isShowing)
	{
		window->draw(_sprite);
	}
}