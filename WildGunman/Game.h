#pragma once
#include "Enemy.h";
#include "Crosshair.h";

class Game
{
	Enemy *_enemies;
	Crosshair _crosshair;
	RenderWindow *_window;
	Texture _txBackground;
	Sprite _background;

public:
	Game();
	~Game();
	void Loop();
	void EventHandling();
	void Update();
	void Draw();

};

