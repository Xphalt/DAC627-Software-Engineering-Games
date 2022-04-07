#include "mathFunctions.h"
#include "gameobject.h"

float mathFunctions::get_triangle_area(position* a, position* b, position* c)
{
	position ab;
	position ac;

	//Work out AB
	ab.x = b->x - a->x;
	ab.y = b->y - a->y;

	//Work out AC
	ac.x = c->x - a->x;
	ac.y = c->y - a->y;

	//Cross Product
	float crossProduct = (ab.x * ac.y) - (ab.y * ac.x);

	return std::abs(crossProduct / 2);
}

bool mathFunctions::get_circle_line_intersecting(float radius, position* o, position* p, position* q)
{
	float minDistance = get_triangle_area(o, p, q) * 2;
	minDistance = minDistance / get_distance(p, q);

	if (minDistance < radius)
	{
		return true;
	}
	else
	{
		return false;
	}

}

float mathFunctions::get_distance(position* a, position* b)
{
	float diffx = a->x - b->x;
	float diffy = a->y - b->y;

	float mag = (diffx * diffx) + (diffy * diffy);
	mag = sqrt(mag);

	return mag;
}
