#pragma once
#include "Enemy.h";
#include "Crosshair.h";
#include "BarWindow.h";
#include <list>

class Game
{
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

private:
	void InitBarWindows();
	void UpdateAndDrawEnemies();
	void InitEnemies();
	Enemy* GetInactiveEnemy();

};

