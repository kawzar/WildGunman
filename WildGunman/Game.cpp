#include "Game.h"



Game::Game()
{
	_points = 0;	
	_lifes = 3;
	_shootTime = 10.5f;
	_shootClock.restart();

	InitWindow();
	InitText();
	InitSound();	
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
		if (GetAliveEnemyCount() > 0 && _lifes > 0)
		{
			EventHandling();
			Update();
			SpawnEnemies();
			Draw();
		}
		else
		{
			ShowGameOverScreen();
			Event evt;
			while (_window->pollEvent(evt))
			{
				if (evt.type == Event::Closed)
				{
					_window->close();
				}
			}
		}
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
				_gunSound.play();
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
	_window->draw(_txtPoints);
	_window->draw(_txtLifes);
	_window->display();
}

void Game::SpawnEnemies()
{
	bool spawn = rand() % 200 == 33;

	if (spawn && GetEmptyBarWindowCount() > 2)
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
		if (enemy->IsActive() && enemy->IsShowing() && enemy->Intersects(playerPosition.x, playerPosition.y))
		{
			int pts = enemy->Points();
			UpdateScore(pts);
			enemy->Die();

			if (pts < 0) // logic for innocents. This is the best idea i had without making the enemies to know the game -- i wanted to avoid circular reference. 
			{
				_lifes--;
				UpdateLifes();
			}
		}
	}
}

void Game::ShootAtPlayer()
{
	_hitSound.play();
	_lifes--;
	UpdateLifes();
}

void Game::ShowGameOverScreen()
{
	_window->clear();

	if (_lifes > 0)
	{
		_txtResult.setString("You defeated all enemies!");		
	}
	
	_window->setMouseCursorVisible(true);
	_window->draw(_txtResult);
	_txtPoints.setPosition(100, 200);
	_window->draw(_txtPoints);
	_window->display();
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

		if (_shootClock.getElapsedTime().asSeconds() > _shootTime && enemy->IsActive() && enemy->Shoot())
		{
			ShootAtPlayer();
			_shootClock.restart();
		}
	}
}

void Game::UpdateScore(int points)
{
	_points += points;
	char pt[10];
	char score[20] = "Score: ";
	_itoa_s(_points, pt, 10);
	strcat_s(score, pt);
	_txtPoints.setString(score);

}

void Game::UpdateLifes()
{
	char lf[10];
	char life[20] = "Lifes: ";
	_itoa_s(_lifes, lf, 10);
	strcat_s(life, lf);
	_txtLifes.setString(life);
}

void Game::InitWindow()
{
	_window = new RenderWindow(VideoMode(780, 438), "Wild Gunman");
	_window->setMouseCursorVisible(false);
	_txBackground.loadFromFile("Images/background.png");
	_background.setTexture(_txBackground);
}

void Game::InitText()
{
	_font.loadFromFile("Fonts/LCD_Solid.ttf");

	_txtPoints.setFont(_font);
	_txtPoints.setPosition(56, 410);
	_txtPoints.setString("Score: ");
	_txtPoints.setCharacterSize(20);
	_txtPoints.setOutlineColor(Color::White);

	_txtLifes.setFont(_font);
	_txtLifes.setPosition(250, 410);
	_txtLifes.setString("Lifes: 3");
	_txtLifes.setCharacterSize(20);
	_txtLifes.setOutlineColor(Color::White);

	_txtResult.setFont(_font);
	_txtResult.setPosition(100, 100);
	_txtResult.setString("Game Over");
	_txtResult.setCharacterSize(20);
	_txtResult.setOutlineColor(Color::White);
}

void Game::InitSound()
{
	_sbuffer.loadFromFile("Sounds/gun.wav");
	_gunSound.setBuffer(_sbuffer);
	_sbHit.loadFromFile("Sounds/Hit_Hurt2.wav");
	_hitSound.setBuffer(_sbHit);
}

int Game::GetAliveEnemyCount()
{
	int count = 0;

	for each (Enemy* e in _enemies)
	{
		if (e->IsAlive() && e->Points() > 0)
		{
			count++;
		}
	}

	return count;
}

int Game::GetEmptyBarWindowCount()
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		if(_bws[i].IsEmpty())
		{
			count++;
		}
	}

	return count;
}

void Game::InitEnemies()
{
	int innocentCount = 2;

	for (int i = 0; i < 20; i++)
	{
		bool innocent = rand() % 100 < 25;

		if (innocent && innocentCount > 0)
		{
			_enemies.push_back(new Innocent());
			innocentCount--; // to prevent blocking the windows
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
