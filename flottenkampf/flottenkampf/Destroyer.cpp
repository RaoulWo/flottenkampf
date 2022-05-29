#include "Destroyer.h"
#include <random>

Destroyer::Destroyer()
	: Ship(150, 6, 60, ShipType::destroyer)
{
}

bool Destroyer::Attack(Ship& other)
{
	int d10 = rand() % 10 + 1;
	if (d10 + 2 < other.GetSize()) // Attack missed
		return false;

	other.SetHull(other.GetHull() - damage);
	return false;
}
