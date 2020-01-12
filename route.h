#ifndef ROUTE_H
#define ROUTE_H

// Macros
#define ROUTE_WIDTH		5
#define ROUTE_HEIGHT	3
#define ROUTE_MODEL		(char)219

enum route_type {
	line_vertical,
	line_horizontal,
	crossing_up,
	crossing_down,
	crossing,
	trap_right,
	trap_left,
	trap_up,
	trap_down 
};

typedef struct {
	int x;
	int y;
} vector_2D;

class Route {
private:
	vector_2D start;
	vector_2D end;
	route_type type;

	void DrawLineHorizontal(const Route &route);
	void DrawLineVertical(const Route &route);

protected:
	vector_2D GetLength();

public:
	Route() = default;
	Route(vector_2D start, vector_2D end);

	void DrawRoute(const Route &route);
	bool Empty() const;
};

#endif