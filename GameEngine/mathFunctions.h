#pragma once
#include <math.h>

struct position;

class mathFunctions
{
public:
	static float get_triangle_area(position* a, position* b, position* c);
	static bool get_circle_line_intersecting(float radius, position* o, position* p, position* q);
	static float get_distance(position* a, position* b);
};

