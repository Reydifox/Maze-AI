#include <iostream>
#include <ctime>
#include <Windows.h>
#include "map.h"
#include "route.h"
#include "player.h"

using namespace std;

void initialization() {
	Map map;
	for (int i = 1; i < SCREEN_HEIGHT; i+=ROUTE_HEIGHT-1)
		map.BuildLine(i);

	map.Generate();
}

int main() {
	srand(time(NULL));
	initialization(); // map initialization

	Player player;
	player.Spawn();

	while (1) {
		if (player.GetPosition().x < SCREEN_WIDTH - BORDER_MARGIN) 
		{
			player.Step();
			Sleep(100);
		}
	}
	return 0;
}