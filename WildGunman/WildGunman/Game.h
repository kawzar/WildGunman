#pragma once
#include <list>
#include "Enemy.h";
#include "Crosshair.h";
#include "BarWindow.h";

class Game
{
	std::list<Enemy*> _enemies;
	Crosshair _crosshair;
	RenderWindow *_window;
	Texture _texBackground;
	Sprite _background;
	BarWindow *_bws;

public:
	Game();
	~Game();
	void Loop();
	void EventHandling();
	void Update();
	void Draw();
private:
	void InitBarWindows();
	void InitEnemies();
	void SpawnEnemies();

};

