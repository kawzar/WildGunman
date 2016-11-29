#include "Enemy.h"



Enemy::Enemy()
{
	_isAlive = true;
	_isShowing = false;
	_visibleTime = 0.7f;
	_clock.restart();
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
	if (!_isShowing)
	{
		_isShowing = true;
		_sprite.setPosition(position);
	}

	_clock.restart();
}

void Enemy::Draw(RenderWindow * window)
{
	if (_isShowing)
	{
		window->draw(_sprite);
	}
}

void Enemy::Update()
{
	if (_clock.getElapsedTime().asSeconds() > _visibleTime)
	{
		if (_isShowing)
		{
			_isShowing = false;
		}
		else
		{
			_isShowing = true;
		}

		_clock.restart();
	}
}