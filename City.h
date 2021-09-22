#pragma once
#include "Utility.h"
#include "State.h"
class City
{
	string cityName;
	State state;

public:
	City() {};
	City(string cityName, State state)
	{
		this->cityName = cityName;
		this->state = state;

	}

	State getStateName() const
	{
		return state.getStateName();
	}

	string getCityName() const
	{
		return cityName;
	}
};