#pragma once
#include "BookingStrategy.h";
class BookMaxMedical : public BookingStrategy {
public:
	int bookOxgyen(Consumer& consumer, unordered_map<string, Vendor>& vendors, int quantity) {
		if (!consumer.canBeAssignedQuantity(quantity))
			return 1;//BookingStatus::MAX_QUANTITY_EXCEEDED;

		string maxMedicalVendor = vendors.begin()->first;
		int maxSupplyMedical = vendors[maxMedicalVendor].getMedicalOxygenUnits();

		for (auto& vendor : vendors)
		{
			if (vendor.second.getMedicalOxygenUnits() > maxSupplyMedical)
			{
				maxMedicalVendor = vendor.first;
				maxSupplyMedical = max(maxSupplyMedical, vendor.second.getMedicalOxygenUnits());
			}

		}

		if (maxSupplyMedical >= quantity)
		{
			vendors[maxMedicalVendor].setMedicalOxygenUnits(maxSupplyMedical - quantity);
			consumer.incrementAvailableOxygen(quantity);
			return 0;//BookingStatus::SUCCESSFUL;
		}
		return 2;// BookingStatus::OXYGEN_NOT_AVAILABLE;

	}

};