#include <iostream>
#include <vector>
#include <Windows.h>
#include "map.h"

// Class
void Map::AddRoute(const Route &route) {
	if (!route.Empty()) {
		this->map.push_back(route);
	}
}

void Map::BuildLine(int y) {
	vector_2D pos;
	pos.x = BORDER_MARGIN;
	pos.y = y;

	do {
		vector_2D tmp = pos;
		pos.x += ROUTE_WIDTH;
		AddRoute(*new Route(tmp, pos));
	} while(pos.x < SCREEN_WIDTH - BORDER_MARGIN - ROUTE_WIDTH);
}

void Map::Generate() {
	if (!this->map.empty()) {
		for (std::vector<Route>::iterator i = this->map.begin(); i != this->map.end(); i++) 
		{
			DrawRoute(*i);
		}
	}
}

// function to set console cursor at specified column and line
void GotoXY(int column, int line)
{
	COORD pos = { column, line };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}