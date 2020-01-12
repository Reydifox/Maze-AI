#ifndef MAP_H
#define MAP_H

#include "route.h";
#include <vector>

// Macros
#define CLEAR_MAP()		system("cls")

#define SCREEN_WIDTH	85
#define SCREEN_HEIGHT	24
#define BORDER_MARGIN	5

// Class
class Map : protected Route {
private:
	std::vector<Route> map;

	void AddRoute(const Route &route);

public:
	Map() = default;
	~Map() {
		map.clear();
	}

	void Generate();
	void BuildLine(int y);
};

// Functions
void GotoXY(int column, int line);
bool IsCollision(int x, int y);

#endif
