#pragma once
#include "Enemy.h";
#include "Innocent.h"
#include "Crosshair.h";
#include "BarWindow.h";
#include <list>

class Game
{
	int points;
	std::list<Enemy*> _enemies;
	Crosshair _crosshair;
	RenderWindow *_window;
	Texture _txBackground;
	Sprite _background;
	BarWindow _bws[5];

public:
	Game();
	~Game();
	void Loop();
	void EventHandling();
	void Update();
	void Draw();
	void SpawnEnemies();
	void CheckCollisions();

private:
	void InitBarWindows();
	void DrawEnemies();
	void InitEnemies();
	void UpdateEnemies();
	Enemy* GetInactiveEnemy();

};

