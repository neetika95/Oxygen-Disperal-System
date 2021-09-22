#pragma once
#pragma once
#pragma once
#include "BookingStrategy.h"
class BookMaxIndustrial : public BookingStrategy {
public:
	int bookOxgyen(Consumer& consumer, unordered_map<string, Vendor>& vendors, int quantity) {

		if (!consumer.canBeAssignedQuantity(quantity))
			return 1;//BookingStatus::MAX_QUANTITY_EXCEEDED;

		string maxIndustrialVendor = vendors.begin()->first;
		int maxSupplyIndustial = vendors[maxIndustrialVendor].getIndustrialOxygenUnits();

		for (auto& vendor : vendors)
		{
			if (vendor.second.getIndustrialOxygenUnits() > maxSupplyIndustial)
			{
				maxIndustrialVendor = vendor.first;
				maxSupplyIndustial = max(maxSupplyIndustial, vendor.second.getIndustrialOxygenUnits());
			}
		}

		if (maxSupplyIndustial >= quantity)
		{
			vendors[maxIndustrialVendor].setIndustrialOxygenUnits(maxSupplyIndustial - quantity);
			consumer.incrementAvailableOxygen(quantity);
			return 0;// BookingStatus::SUCCESSFUL;
		}

		return 2;// BookingStatus::OXYGEN_NOT_AVAILABLE;

	}

};