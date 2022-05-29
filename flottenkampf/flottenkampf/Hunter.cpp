#include "Hunter.h"
#include <random>

Hunter::Hunter()
	: Ship(75, 4, 30, ShipType::hunter)
{
}

bool Hunter::Attack(Ship& other)
{
	int d10 = rand() % 10 + 1;
	if (d10 < other.GetSize()) // Attack missed
		return false;

	if (d10 == 9 || d10 == 10)
	{
		other.SetHull(other.GetHull() - damage * 2);
		return false;
	}

	other.SetHull(other.GetHull() - damage);
	return false;
}
