#include "Fleet.h"

std::shared_ptr<Ship> Fleet::GetShip(int i)
{
	return ships[i];
}

void Fleet::AddShip(std::shared_ptr<Ship> s)
{
	ships.push_back(s);
}

bool Fleet::Attack(int i, int j, Fleet& enemy)
{
	if (i < 0 || i >= MAX_FLEET_SIZE)
		return false;

	if (j < 0 || j >= MAX_FLEET_SIZE)
		return false;

	if (!ships[i]->IsAlive() || !enemy.ships[j]->IsAlive())
		return false;

	return ships[i]->Attack(*(enemy.ships[j]));
}

bool Fleet::IsAlive() const
{
	for (int i = 0; i < ships.size(); i++)
	{
		if (ships[i]->IsAlive())
			return true;
	}
	return false;
}
