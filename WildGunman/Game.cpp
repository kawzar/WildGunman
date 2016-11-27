#include "Game.h"



Game::Game()
{
	_window = new RenderWindow(VideoMode(780, 438), "Wild Gunman");
	_window->setMouseCursorVisible(false);
	_txBackground.loadFromFile("Images/background.png");
	_background.setTexture(_txBackground);
}


Game::~Game()
{
}

void Game::Loop()
{
	while (_window->isOpen())
	{
		EventHandling();
		Update();
		Draw();
	}
}

void Game::EventHandling()
{
	Event evt;
	while (_window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
			_window->close();
			break;
		}
	}
}

void Game::Update()
{
	Vector2i mousePos = Mouse::getPosition(*_window);
	_crosshair.SetPosition((Vector2f)mousePos);
}

void Game::Draw()
{
	_window->clear(Color::Black);
	_window->draw(_background);
	_crosshair.Draw(_window);
	_window->display();
}
