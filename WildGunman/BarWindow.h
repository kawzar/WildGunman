#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
class BarWindow
{
	Vector2i _position;
	bool _isEmpty;
public:
	BarWindow();
	BarWindow(int x, int y);
	~BarWindow();
	bool IsEmpty();
	Vector2i GetPosition();
	void SetPosition(Vector2i position);
	void ToggleEmpty();
};

