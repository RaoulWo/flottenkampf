#include "Ship.h"

Ship::Ship(int hull, int size, int damage, ShipType type)
	: hull(hull), size(size), damage(damage), type(type)
{
}

int Ship::GetHull() const
{
	return hull;
}

int Ship::GetSize() const
{
	return size;
}

int Ship::GetDamage() const
{
	return damage;
}

ShipType Ship::GetShipType() const
{
	return type;
}

bool Ship::IsAlive() const
{
	return hull > 0;
}

void Ship::SetHull(int h)
{
	hull = h;
	if (hull < 0)
		hull = 0;
}

