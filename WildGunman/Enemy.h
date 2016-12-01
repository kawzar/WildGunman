#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "BarWindow.h"

using namespace sf;

class Enemy
{
protected:
	bool _isAlive;
	bool _isShowing;
	bool _hasWindow;
	float _visibleTime;
	float _notVisibleTime;
	Texture _tx;
	Sprite _sprite;
	Clock _clock;
	BarWindow* _window;

public:
	Enemy();
	~Enemy();
	bool IsAlive();
	bool IsShowing();
	bool IsActive();
	bool Intersects(float x, float y);
	void Show(BarWindow* bw);
	void Draw(RenderWindow *window);
	void Update();
	void Die();
	virtual bool Shoot();
	virtual int Points();
};

