#pragma once
#include "Enemy.h";
#include "Innocent.h"
#include "Crosshair.h";
#include "BarWindow.h";
#include <list>
#include <SFML\Audio.hpp>

class Game
{
	int _points;
	std::list<Enemy*> _enemies;
	Crosshair _crosshair;
	RenderWindow *_window;
	Texture _txBackground;
	Sprite _background;
	BarWindow _bws[5];
	Text _txtPoints;
	Font _font;
	SoundBuffer _sbuffer;
	Sound _gunSound;

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
	void UpdateScore(int points);
	void InitWindow();
	void InitText();
	void InitSound();
	int GetAliveEnemyCount();
	Enemy* GetInactiveEnemy();

};

