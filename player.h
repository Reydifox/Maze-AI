#ifndef PLAYER_H
#define PLAYER_H

#include "route.h"
#include "map.h"

#define PLAYER_MODEL		'X'
#define PLAYER_MODEL_STEP	'.'

class Player {
private:
	vector_2D position;
	vector_2D spawn;

public:
	Player();
	Player(vector_2D pos);

	void Spawn();
	void Step();
	vector_2D GetPosition();
};

#endif
