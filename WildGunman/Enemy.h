#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
	bool _isAlive;
	bool _isShowing;
	bool _hasWindow;
	float _visibleTime;
	Texture _tx;
	Sprite _sprite;
	Clock _clock;

public:
	Enemy();
	~Enemy();
	bool IsAlive();
	bool IsShowing();
	bool IsActive();
	void Show(Vector2f position);
	void Draw(RenderWindow *window);
	void Update();
};

