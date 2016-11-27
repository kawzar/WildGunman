#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Shoot();
	void Die();
	void SetPosition(Vector2i position);
};

