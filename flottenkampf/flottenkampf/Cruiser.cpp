#include "Cruiser.h"
#include <random>

Cruiser::Cruiser()
	: Ship(250, 8, 50, ShipType::cruiser)
{
}

bool Cruiser::Attack(Ship& other)
{
	int d10 = rand() % 10 + 1;
	if (d10 < other.GetSize()) // Attack missed
		return false;

	other.SetHull(other.GetHull() - damage);
	return true;
}
