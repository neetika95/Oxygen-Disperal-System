#pragma once
#include "Utility.h"
#include "ConsumerType.h"
#include "City.h"
class Consumer
{
	string consumerId;
	ConsumerType type;
	City city;
	State state;
	int maxRequiremnt;
	int availableOxygen;
	bool fallbackToIndustrial;

public:
	Consumer()
	{
		type = ConsumerType::UNKNOWN;
		maxRequiremnt = 0;
		availableOxygen = 0;
		fallbackToIndustrial = true;
	}

	Consumer(string consumerId, ConsumerType type, City city, State state, int maxRequirment)
	{
		this->consumerId = consumerId;
		this->type = type;
		this->city = city;
		this->state = state;
		this->maxRequiremnt = maxRequirment;
		this->availableOxygen = 0;
		fallbackToIndustrial = true;
	}

	ConsumerType getType(){
		return type;
	}

	string getCity() const {
		return city.getCityName();
	}

	string getState() const
	{
		return state.getStateName();
	}

	string getConsumerId() const
	{
		return consumerId;
	}

	int getRemaningRequirement() const
	{
		return maxRequiremnt - availableOxygen;
	}

	int getAvailableOxygen() const
	{
		return availableOxygen;
	}

	void incrementAvailableOxygen(int quantity)
	{
		this->availableOxygen += quantity;
	}

	bool canBeAssignedQuantity(int quantity)
	{
		return quantity + availableOxygen <= maxRequiremnt;
	}

	bool canFallbackToIndustial()
	{
		return fallbackToIndustrial;
	}

	void setFallbackToIndustrial(bool fallbackToIndustrial)
	{
		this->fallbackToIndustrial = fallbackToIndustrial;
	}

};