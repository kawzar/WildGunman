#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Crosshair
{
	Texture _myTex;
	Sprite _sprite;

public:
	Crosshair();
	~Crosshair();
	void Draw(RenderWindow *wnd);
	void SetPosition(Vector2f position);
	Vector2f GetPosition();
};

