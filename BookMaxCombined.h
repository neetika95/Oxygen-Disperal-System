#pragma once
#pragma once
#pragma once
#pragma once
#include "BookingStrategy.h"
class BookMaxCombined : public BookingStrategy {
public:
	int bookOxgyen(Consumer& consumer, unordered_map<string, Vendor>& vendors, int quantity) {

		if (!consumer.canBeAssignedQuantity(quantity))
			return 1;//BookingStatus::MAX_QUANTITY_EXCEEDED;

		string maxCombinedVendor = vendors.begin()->first;
		int maxSupplyCombined = vendors[maxCombinedVendor].getMedicalOxygenUnits() + vendors[maxCombinedVendor].getIndustrialOxygenUnits();

		for (auto& vendor : vendors)
		{
			if (vendor.second.getIndustrialOxygenUnits() + vendor.second.getMedicalOxygenUnits() > maxSupplyCombined)
			{
				maxCombinedVendor = vendor.first;
				maxSupplyCombined = max(maxSupplyCombined, vendor.second.getIndustrialOxygenUnits() + vendor.second.getMedicalOxygenUnits());
			}
		}

		//assert quantity greater than medical

		if (maxSupplyCombined >= quantity)
		{
			if (quantity < vendors[maxCombinedVendor].getMedicalOxygenUnits())
			{
				vendors[maxCombinedVendor].setMedicalOxygenUnits(vendors[maxCombinedVendor].getMedicalOxygenUnits() - quantity);
			}
			else
			{
				vendors[maxCombinedVendor].setIndustrialOxygenUnits(vendors[maxCombinedVendor].getIndustrialOxygenUnits() - (quantity - vendors[maxCombinedVendor].getMedicalOxygenUnits()));
				vendors[maxCombinedVendor].setMedicalOxygenUnits(0); // used all
			}

			consumer.incrementAvailableOxygen(quantity);
			return 0;//BookingStatus::SUCCESSFUL;
		}

		return 2;//BookingStatus::OXYGEN_NOT_AVAILABLE;

	}

};