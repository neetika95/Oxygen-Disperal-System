#pragma once
#include "Utility.h"
class State
{
	string stateName;

public:
	State()
	{

	}

	State(string stateName)
	{
		this->stateName = stateName;
	}

	string getStateName() const
	{
		return stateName;
	}
};