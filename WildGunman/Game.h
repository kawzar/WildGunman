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
	int _lifes;
	float _shootTime;
	std::list<Enemy*> _enemies;
	Crosshair _crosshair;
	RenderWindow *_window;
	Texture _txBackground;
	Sprite _background;
	BarWindow _bws[5];
	Text _txtPoints;
	Text _txtLifes;
	Text _txtResult;
	Font _font;
	SoundBuffer _sbuffer;
	SoundBuffer _sbHit;
	Sound _hitSound;
	Sound _gunSound;
	Clock _shootClock;


public:
	Game();
	~Game();
	void Loop();
	void EventHandling();
	void Update();
	void Draw();
	void SpawnEnemies();
	void CheckCollisions();
	void ShootAtPlayer();
	void ShowGameOverScreen();

private:
	void InitBarWindows();
	void DrawEnemies();
	void InitEnemies();
	void UpdateEnemies();
	void UpdateScore(int points);
	void UpdateLifes();
	void InitWindow();
	void InitText();
	void InitSound();
	int GetAliveEnemyCount();
	int GetEmptyBarWindowCount();
	Enemy* GetInactiveEnemy();

};

