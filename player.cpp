#include <iostream>
#include "player.h"
#include "map.h"

Player::Player() {
	this->position.x = rand() % BORDER_MARGIN;
	this->position.y = rand() % SCREEN_HEIGHT;
	this->spawn.x = this->position.x;
	this->spawn.y = this->position.y;
}

Player::Player(vector_2D pos) {
	this->position = pos;
	this->spawn = pos;
}

void Player::Spawn() {
	GotoXY(this->spawn.x, this->spawn.y);
	std::cout << PLAYER_MODEL;
}

void Player::Step() {
	this->position.x += rand() % 2 - 1;
	this->position.y -= rand() % 2 - 1;

	if (!IsCollision(this->position.x, this->position.y) && this->position.y < SCREEN_HEIGHT) {
		GotoXY(this->position.x, this->position.y);
		std::cout << PLAYER_MODEL_STEP;
	}
	else {
		Spawn();
	}
}

vector_2D Player::GetPosition() {
	return this->position;
}