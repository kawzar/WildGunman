#include "Innocent.h"



Innocent::Innocent()
{
	_isAlive = true;
	_isShowing = false;
	_hasWindow = false;
	_visibleTime = 0.7f;
	_notVisibleTime = 0.9f;
	_clock.restart();
	_tx.loadFromFile("Images/innocent.png");
	_sprite.setTexture(_tx);
	_sprite.setOrigin(_tx.getSize().x / 2, _tx.getSize().y);
}


Innocent::~Innocent()
{
}

int Innocent::Points()
{
	return -10;
}

bool Innocent::Shoot()
{
	return false;
}
