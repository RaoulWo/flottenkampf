#pragma once
#include "Ship.h"
#include <vector>
#include <memory>

constexpr int MAX_FLEET_SIZE = 9;

class Fleet
{
public:
	std::shared_ptr<Ship> GetShip(int i);

	void AddShip(std::shared_ptr<Ship> s);

	bool Attack(int i, int j, Fleet& enemy); // i ... index of your ship, j ... index of other ship, enemy ... enemy Fleet
	bool IsAlive() const;
private:
	std::vector<std::shared_ptr<Ship>> ships = {};
};

