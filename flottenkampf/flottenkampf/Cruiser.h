#pragma once
#include "Ship.h"

class Cruiser : public Ship
{
public:
	Cruiser();

	bool Attack(Ship& other) override;
};

