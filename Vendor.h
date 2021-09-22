#pragma once
#include "Utility.h";
#include "City.h"
class Vendor
{
	string vendorId;
	City city;
	State state;
	int medicalOxygenAvailable;
	int industrialOxygenAvailable;

public:
	Vendor()
	{
		medicalOxygenAvailable = 0;
		industrialOxygenAvailable = 0;
	}

	Vendor(string vendorId, City city, State state, int medicalOxygenAvailable, int industrialOxygenAvailable)
	{
		this->vendorId = vendorId;
		this->city = city;
		this->state = state;
		this->medicalOxygenAvailable = medicalOxygenAvailable;
		this->industrialOxygenAvailable = industrialOxygenAvailable;
	}

	string getCity() const 
	{
		return city.getCityName();
	}

	string getState() const
	{
		return state.getStateName();
	}

	string getVendorId() const {
		return vendorId;
	}

	int getMedicalOxygenUnits() const
	{
		return medicalOxygenAvailable;
	}

	int getIndustrialOxygenUnits() const
	{
		return industrialOxygenAvailable;
	}

	void setMedicalOxygenUnits(int medicalOxygen)
	{
		this->medicalOxygenAvailable = medicalOxygen;
	}

	void setIndustrialOxygenUnits(int industrialOxygen)
	{
		this->industrialOxygenAvailable = industrialOxygen;
	}

};