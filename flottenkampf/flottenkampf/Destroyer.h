#pragma once
#include "Ship.h"

class Destroyer : public Ship
{
public:
	Destroyer();

	bool Attack(Ship& other) override;
};

