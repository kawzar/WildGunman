
#include "Enemy.h"
class Innocent :
	public Enemy
{
public:
	Innocent();
	~Innocent();
	int Points();
	bool Shoot();
};
