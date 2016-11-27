#include "BarWindow.h"

BarWindow::BarWindow(int x, int y)
{
	_isEmpty = true;
	_position = Vector2i(x, y);
}


BarWindow::~BarWindow()
{
}

bool BarWindow::IsEmpty()
{
	return _isEmpty;
}

void BarWindow::Ocuppy(Enemy * enemy)
{
	_isEmpty = false;
	enemy->SetPosition(_position);
}
