#pragma once
#include "Utility.h"
#include "Consumer.h"
#include "Vendor.h"
#include "City.h"
#include"BookingStrategy.h"
#include "BookMaxMedical.h"
#include "BookMaxIndustrial.h"
#include "BookMaxCombined.h"
class OxygenDispersalSystem
{
private:
	unordered_map<string, Consumer >consumers;
	unordered_map<string, Vendor > vendors;
	unordered_map<string, City> cities;
	unordered_map<string, State> states;

	vector<Vendor> getAllVendors()
	{
		vector<Vendor> allVendors;
		for (auto vendor : vendors)
		{
			allVendors.push_back(vendor.second);
		}

		return allVendors;
	}

	vector<Consumer> getHospitals()
	{
		vector<Consumer> hospitals;
		for (auto consumer : consumers)
		{
			if(consumer.second.getType()==ConsumerType::HOSPITAL)
				hospitals.push_back(consumer.second);
		}

		return hospitals;
	}

	void sortByTotalOxygen(vector<Vendor>& allVendors)
	{
		sort(allVendors.begin(), allVendors.end(), [](const Vendor& v1, const Vendor& v2) 
			{
			return v1.getIndustrialOxygenUnits() + v1.getMedicalOxygenUnits() > v2.getIndustrialOxygenUnits() + v2.getMedicalOxygenUnits(); 
			});
	}

	void sortByAvailaleOxygen(vector<Consumer>& hospitals)
	{
		sort(hospitals.begin(), hospitals.end(), [](const Consumer& v1, const Consumer& v2)
			{
				return v1.getAvailableOxygen() > v2.getAvailableOxygen();
			});
	}

	void sortByRequiredOxygen(vector<Consumer>& industries)
	{
		sort(industries.begin(), industries.end(), [](const Consumer& v1, const Consumer& v2)
			{
				return v1.getRemaningRequirement() > v2.getRemaningRequirement();
			});
	}

	void displayVendors(const vector<Vendor>& vendors)
	{
		for (const auto vendor : vendors)
			cout << " \t Vendor ID : " << vendor.getVendorId() << " City : " << vendor.getCity() << " MEDICAL : " << vendor.getMedicalOxygenUnits() << " INDUSTRIAL :" << vendor.getIndustrialOxygenUnits()<<endl;
	}
	void displayConsumer(const vector<Consumer>& consumers)
	{
		for (const auto consumer : consumers)
			cout << "\t Consumer ID : " << consumer.getConsumerId() << " City : " << consumer.getCity() << " " << consumer.getState() << " AVAILABLE : " << consumer.getAvailableOxygen() << " REQUIRED : " << consumer.getRemaningRequirement() << endl;
	}


	vector<Consumer> getIndustries()
	{
		vector<Consumer> industries;
		for (auto consumer : consumers)
		{
			if (consumer.second.getType() == ConsumerType::INDUSTRY)
				industries.push_back(consumer.second);
		}

		return industries;
	}

public:

	static OxygenDispersalSystem& getOxygenDisperalSystem()
	{
		static OxygenDispersalSystem system;
		return system;
	}

	void registerConsumer(string consumerId, ConsumerType type, string cityName, string stateName, int maxReq)
	{
		if (states.find(stateName) == states.end())
			states[stateName] = State(stateName);

		if (cities.find(cityName) == cities.end())
			cities[cityName] = City(cityName, states[stateName]);

		Consumer consumer(consumerId, type, cities[cityName], states[stateName], maxReq);
		consumers[consumerId] = consumer;

	}

	void registerVendor(string vendorId, string cityName, string stateName, int medicalOxygen, int indsutrialOxygen)
	{
		if (states.find(stateName) == states.end())
			states[stateName] = State(stateName);

		if (cities.find(cityName) == cities.end())
			cities[cityName] = City(cityName, states[stateName]);

		Vendor vendor(vendorId, cities[cityName], states[stateName], medicalOxygen, indsutrialOxygen);
		vendors[vendorId] = vendor;
	}

	void bookOxygen(string consumerId, int quantity)
	{
		Consumer& c = consumers[consumerId];
		int status = -1;
		BookingStrategy* bookingStrategy;
		if (c.getType() == HOSPITAL)
		{
			bookingStrategy = new BookMaxMedical();
			status = bookingStrategy->bookOxgyen(c, vendors, quantity);
			if (status == 2 and c.canFallbackToIndustial())
			{
				bookingStrategy = new BookMaxCombined();
				status = bookingStrategy->bookOxgyen(c, vendors, quantity);
			}

		}

		else if (c.getType() == INDUSTRY)
		{
			bookingStrategy = new BookMaxIndustrial();
			status = bookingStrategy->bookOxgyen(c, vendors, quantity);
		}

		if (status == 2)//OXYGEN_NOT_AVAILABLE)
			cout << " \t No Vendor has " << quantity << " of oxygen currently for consumer " << consumerId << endl;

		else if (status == 1)//MAX_QUANTITY_EXCEEDED)
			cout << "\t Max avialable quantity for consumer " << consumerId << " exceeded " << endl;

		else if (status == 0)
			cout << " \t " << quantity << " of Oxygen successfully procured for consumer " << consumerId << endl;
		else
			cout << "\t " << " Not registered " << endl;

	}

	void showVendors(string name) // of state
	{
		vector<Vendor> allVendors = getAllVendors();
		vector<Vendor> stateVendors = {};
		for (auto vendor : allVendors)
		{
			if (vendor.getState() == name)
				stateVendors.push_back(vendor);
		}

		sortByTotalOxygen(stateVendors);
		displayVendors(stateVendors);
	}

	void showHospitals(string name) // city
	{
		vector<Consumer> hospitals = getHospitals();
		vector<Consumer> cityHospitals = {};

		for (auto hospital : hospitals)
		{
			if (hospital.getCity() == name)
				cityHospitals.push_back(hospital);
		}

		sortByAvailaleOxygen(cityHospitals);
		displayConsumer(cityHospitals);
	}

	void showIndustries()
	{
		vector<Consumer> industries = getIndustries();
		sortByRequiredOxygen(industries);
		displayConsumer(industries);
	}

	void changeFallBackBehavior(string name, bool fallbackBehavior)
	{
		for (auto& consumer : consumers)
		{
			if (consumer.second.getState() == name)
				consumer.second.setFallbackToIndustrial(fallbackBehavior);
		}
	}
};