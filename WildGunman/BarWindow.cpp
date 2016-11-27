#include "BarWindow.h"



BarWindow::BarWindow()
{
	_isEmpty = true;
}

BarWindow::BarWindow(int x, int y)
{
	BarWindow::BarWindow();
	_position = Vector2i(x, y);
}

BarWindow::~BarWindow()
{
}

bool BarWindow::IsEmpty()
{
	return _isEmpty;
}

Vector2i BarWindow::GetPosition()
{
	return _position;
}

void BarWindow::SetPosition(Vector2i position)
{
	_position = position;
}

void BarWindow::ToggleEmpty()
{
	_isEmpty = !_isEmpty;
}


