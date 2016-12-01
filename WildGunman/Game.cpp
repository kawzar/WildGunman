#include "Game.h"



Game::Game()
{
	points = 0;
	_window = new RenderWindow(VideoMode(780, 438), "Wild Gunman");
	_window->setMouseCursorVisible(false);
	_txBackground.loadFromFile("Images/background.png");
	_background.setTexture(_txBackground);
	InitBarWindows();
	InitEnemies();
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
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left)
			{
				CheckCollisions();
			}
		}
	}
}

void Game::Update()
{
	Vector2i mousePos = Mouse::getPosition(*_window);
	_crosshair.SetPosition((Vector2f)mousePos);
	UpdateEnemies();
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
	bool spawn = rand() % 200 == 33;

	if (spawn)
	{
		int index = rand() % 5;
		if (_bws[index].IsEmpty())
		{
			Enemy* enemy = GetInactiveEnemy();
			if (enemy != nullptr)
			{
				enemy->Show( &_bws[index]);
			}
		}
	}
}

void Game::CheckCollisions()
{
	Vector2f playerPosition = _crosshair.GetPosition();

	for each (Enemy* enemy in _enemies)
	{
		if (enemy->IsActive() && enemy->Intersects(playerPosition.x, playerPosition.y))
		{
			points += enemy->Points();
			enemy->Die();
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
	for each (Enemy* e in _enemies)
	{
		if (e->IsShowing())
		{
			e->Draw(_window);
		}
	}
}

void Game::UpdateEnemies()
{
	for each (Enemy* enemy in _enemies)
	{
		enemy->Update();
	}
}

void Game::InitEnemies()
{
	for (int i = 0; i < 3; i++)
	{
		bool innocent = rand() % 100 == 17;

		if (innocent)
		{
			_enemies.push_back(new Innocent());
		}
		else
		{
			_enemies.push_back(new Enemy());
		}
	}
}

Enemy * Game::GetInactiveEnemy()
{
	for each (Enemy* e in _enemies)
	{
		if (!e->IsActive() && e->IsAlive())
		{
			return e;
		}
	}

	return nullptr;
}
