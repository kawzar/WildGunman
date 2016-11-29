#include "Enemy.h"



Enemy::Enemy()
{
	_isAlive = true;
	_isShowing = false;
	_hasWindow = false;
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

bool Enemy::IsActive()
{
	return _isAlive && _hasWindow;
}

void Enemy::Show(Vector2f position)
{
	if (!_isShowing)
	{
		_isShowing = true;
		_hasWindow = true;
		_sprite.setPosition(position);
		_clock.restart();
	}
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
	if (_isShowing && _clock.getElapsedTime().asSeconds() > _visibleTime)
	{
		_isShowing = false;
		_clock.restart();
		return;
	}
	if(!_isShowing && _clock.getElapsedTime().asSeconds() > _visibleTime)
	{
		_isShowing = true;
		_clock.restart();
		return;
	}
}