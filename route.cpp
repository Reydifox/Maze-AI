#include <iostream>
#include "route.h"
#include "map.h"

// Default constructor
/*Route::Route() {
	switch (rand() % 2) {
		case 0: {
			this->start_x = rand() % SCREEN_WIDTH / 2;
			this->end_x = start_x + rand() % 5;

			int y = rand() % SCREEN_HEIGHT / 2;
			this->start_y = y;
			this->end_y = y + 1;
		}
		case 1: {
			int x = rand() % SCREEN_WIDTH / 2;
			this->start_x = x;
			this->end_x = x + 1;

			this->start_y = rand() % SCREEN_HEIGHT / 2;
			this->end_y = start_y + rand() % 5;
		}
	}
}*/
Route::Route(vector_2D start, vector_2D end) {
	int r_type = rand() % sizeof(route_type);
	this->start = start;
	this->end = end;
	this->type = static_cast<route_type>(r_type);
}

// Function to get line length
vector_2D Route::GetLength() {
	vector_2D tmp;
	tmp.x = abs(this->start.x - this->end.x);
	tmp.y = abs(this->start.y - this->end.y);
	return tmp;
}

void Route::DrawRoute(const Route &route) {
	switch (route.type) {
	case line_horizontal: DrawLineHorizontal(route);
		break;
	case line_vertical: DrawLineVertical(route);
	}
}

void Route::DrawLineHorizontal(const Route &route) {
	for (int x = 0; x < ROUTE_WIDTH; x++) {
		GotoXY(route.start.x + x, route.start.y -1);
		std::cout << ROUTE_MODEL;
		GotoXY(route.start.x + x, route.start.y + 1);
		std::cout << ROUTE_MODEL;
	}
}

void Route::DrawLineVertical(const Route &route) {
	for (int y = 1; y < ROUTE_HEIGHT; y++) {
		GotoXY(route.start.x - 1, route.start.y + y);
		std::cout << ROUTE_MODEL;
		GotoXY(route.start.x + 1, route.start.y + y);
		std::cout << ROUTE_MODEL;
	}
}

bool Route::Empty() const {
	if (!this->start.x && !this->end.x && !this->start.y && !this->end.y)
		return true;

	return false;
}