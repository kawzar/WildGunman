#include "Game.h"



Game::Game()
{
	_window = new RenderWindow(VideoMode(780, 438), "Wild Gunman");
	_window->setMouseCursorVisible(false);
	_texBackground.loadFromFile("Images/background.png");
	_background.setTexture(_texBackground);
	_bws = new BarWindow[5];
	InitBarWindows();
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

void Game::InitBarWindows()
{
	_bws[0] = BarWindow(166, 159);
	_bws[1] = BarWindow(142, 367);
	_bws[2] = BarWindow(612, 159);
	_bws[3] = BarWindow(638, 367);
	_bws[4] = BarWindow(385, 367);
}

void Game::InitEnemies()
{
}

void Game::SpawnEnemies()
{
	bool spawn = rand() % 100 < 25;

	if (spawn)
	{
		int index = rand() % 5;
		if (_bws[index].IsEmpty())
		{
			Enemy* enemy = new Enemy();
			_enemies.push_back(enemy);
			_bws[index].Ocuppy(enemy);
		}
	}
}
