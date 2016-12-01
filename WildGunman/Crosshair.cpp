#include "Crosshair.h"



Crosshair::Crosshair()
{
	_myTex.loadFromFile("Images/crosshair.png");
	_sprite.setTexture(_myTex);
	_sprite.setScale(0.03f, 0.03f);
	_sprite.setOrigin(_myTex.getSize().x / 2, _myTex.getSize().y / 2);
}


Crosshair::~Crosshair()
{
}

void Crosshair::Draw(RenderWindow *wnd)
{
	wnd->draw(_sprite);
}

void Crosshair::SetPosition(Vector2f position)
{
	_sprite.setPosition(position);
}

Vector2f Crosshair::GetPosition()
{
	return _sprite.getPosition();
}
