#include "Enemy.h"



Enemy::Enemy()
{
	_isAlive = true;
	_isShowing = false;
	_hasWindow = false;
	_visibleTime = 1.2f;
	_notVisibleTime = 3.3f;
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

bool Enemy::Intersects(float x, float y)
{
	FloatRect bounds = _sprite.getGlobalBounds();
	return bounds.contains(x, y);
}

void Enemy::Show(BarWindow *bw)
{
	if (!_isShowing)
	{
		_window = bw;
		_isShowing = true;
		_hasWindow = true;
		_window->ToggleEmpty();
		_sprite.setPosition((Vector2f)_window->GetPosition());
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
	if (_isAlive)
	{
		if (_isShowing && _clock.getElapsedTime().asSeconds() > _visibleTime)
		{
			_isShowing = false;
			_clock.restart();
			return;
		}
		if (!_isShowing && _clock.getElapsedTime().asSeconds() > _notVisibleTime)
		{
			_isShowing = true;
			_clock.restart();
			return;
		}
	}
}

void Enemy::Die()
{
	_isAlive = false;
	_isShowing = false;
	_window->ToggleEmpty();
}

bool Enemy::Shoot()
{
	bool shoot = false;

	if (_isShowing )
	{
		shoot = rand() % 100 == 47;
	}
	
	return shoot;
}

int Enemy::Points()
{
	return 10;
}
