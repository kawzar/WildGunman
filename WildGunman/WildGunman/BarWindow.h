#pragma once
#include "Enemy.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class BarWindow
{
	bool _isEmpty;
	Vector2i _position;

public:
	BarWindow() {}
	BarWindow(int x, int y);
	~BarWindow();
	bool IsEmpty();
	void Ocuppy(Enemy *enemy);
};

