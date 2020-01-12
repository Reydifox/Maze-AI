#include <iostream>
#include <ctime>
#include "map.h"
#include "route.h"

using namespace std;

void initialization() {
	Map map;
	for (int i = 1; i < SCREEN_HEIGHT; i+=ROUTE_HEIGHT-1)
		map.BuildLine(i);

	map.Generate();
}

int main() {
	srand(time(NULL));
	initialization();

	while (1) {
		// simulation
	}
	return 0;
}