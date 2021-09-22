#pragma once
#include "Utility.h"
#include "Consumer.h"
#include "Vendor.h"
class BookingStrategy
{
public:
	virtual int bookOxgyen(Consumer& consumer, unordered_map<string, Vendor>& vendors, int quantity) = 0;

};