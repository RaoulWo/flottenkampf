#pragma once

enum class ShipType
{
	hunter, destroyer, cruiser
};

class Ship
{
public:
	Ship(int hull, int size, int damage, ShipType type);

	int GetHull() const;
	int GetSize() const;
	int GetDamage() const;
	ShipType GetShipType() const;
	bool IsAlive() const;

	void SetHull(int h);

	virtual bool Attack(Ship& other) = 0;
	
protected:
	int hull;
	int size;
	int damage;
	ShipType type;
};

