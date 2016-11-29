#include "Game.h"



Game::Game()
{
	_window = new RenderWindow(VideoMode(780, 438), "Wild Gunman");
	_window->setMouseCursorVisible(false);
	_txBackground.loadFromFile("Images/background.png");
	_background.setTexture(_txBackground);
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
		SpawnEnemies();
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
	_window->clear();
	DrawEnemies();
	_window->draw(_background);
	_crosshair.Draw(_window);
	_window->display();
}

void Game::SpawnEnemies()
{
	bool spawn = rand() % 100 < 5;

	if (spawn)
	{
		int index = rand() % 5;
		if(_bws[index].IsEmpty())
		{
			Enemy newEnemy = Enemy();
			newEnemy.Show((Vector2f)_bws[index].GetPosition());
			_enemies.push_back(newEnemy);
			_bws[index].ToggleEmpty();
		}
	}
}

void Game::InitBarWindows()
{
	_bws[0] = BarWindow(165, 163);
	_bws[1] = BarWindow(609, 163);
	_bws[2] = BarWindow(131, 367);
	_bws[3] = BarWindow(630, 367);
	_bws[4] = BarWindow(388, 367);
}

void Game::DrawEnemies()
{
	for each (Enemy e in _enemies)
	{
		e.Draw(_window);
	}
}
