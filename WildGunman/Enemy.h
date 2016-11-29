#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
	bool _isAlive;
	bool _isShowing;
	Texture _tx;
	Sprite _sprite;

public:
	Enemy();
	~Enemy();
	bool IsAlive();
	bool IsShowing();
	void Show(Vector2f position);
	void Draw(RenderWindow *window);
};

