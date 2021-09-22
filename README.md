# Oxygen-Disperal-System
Oxygen Dispersal System
Description:
The Government of India is starting an Oxygen Dispersal System. In this Service, Hospitals and Industries can book Oxygen from vendors all across the country.
Features:
Oxygen Vendors provide 2 kinds of Oxygen - Industrial and Medical.
These vendors are present all across the country. Only one vendor can be present in a city. Assume that city names are unique all across the country.
There are 2 kinds of consumers who can book oxygen - Hospitals and Industries.
A consumer can place an order as many times as possible but that order should never exceed its remaining capacity otherwise the order will not be executed.
If none of the vendors are having enough medical oxygen for fulfillment, then Hospitals can take Industrial oxygen but not vice versa.
When a booking is made, order should be placed with the single vendor with the highest available oxygen of consumer type.
Government should be able to check all the available vendors with their capacity sorted in decreasing order of sum of oxygen.
Citizens from Government Portal should be able to check all the hospitals in their city with their available capacity sorted in decreasing order.
Government should be able to check all the industries with their requirements sorted in decreasing order.
Requirements:
Register a Vendor:
registerVendor(city, state, medicalOxygenCapacity, industrialOxygenCapacity) 

Register a Consumer:
registerConsumer(consumerId, consumerType  ,city, state, maximum requirement)

A Consumer should be able to book with a given quantity of oxygen:
bookOxygen(consumerId, quantity)
If a hospital makes an order and none of the Vendors are having enough available medical oxygen then available capacity will be medical + industrial and the vendor with highest summation capacity would be chosen. Medical capacity will be prioritised over medical+industrial.
If an industry makes an order it can just be ordered from Industrial capacity.

Show all Vendors in a state.
showAllvendors(state)
Show all the Vendors of the state sorted by decreasing order of their available total oxygen.


Show all Hospitals for a city.
showHospitals(city) 
Show all the hospitals of that city sorted by decreasing order of their available oxygen.

Bonus:
Show All Industries
showIndustries() - Show all the Industries of that country sorted by decreasing order of their total required oxygen.
bookOxygenPreferState(id, requirement)
While making an order 1st prefer a vendor with highest current available capacity in the same state as consumer and then the capacity of the vendor.
Booking logic can be customized at state level for Hospitals whether fallback to industry oxygen is required or not.



Sample Test Case:
All the inputs here are just indicating the high level inputs that function should accept. You are free to model entities as per your choice.
registerVendor(‘Bengaluru’, ‘Karnataka’, 100, 100)
registerVendor(Mysuru, ‘Karnataka’, 50, 100)
registerConsumer(‘H1’, ‘Hospital’, ‘Bengaluru’, ‘‘Karnataka’, 150)
registerConsumer(‘H2’, ‘Hospital’, ‘Bengaluru’, ‘‘Karnataka’, 150)
registerConsumer(‘I1’, Industry, ‘Bengaluru’, ‘‘Karnataka’, 150)
bookOxygen(‘H1’, 120)
Medical oxygen purchased successfully from Bengaluru Vendor, H1 can order more 30L oxygen.
bookOxygen(‘I1’, 100)
Industrial oxygen purchased successfully from Mysuru Vendor, I1 can order more 50L oxygen.
showVendors(‘Karnataka’)
Bengaluru, 0, 80
Mysuru, 50, 0
showHospitals(‘Bengaluru):
H1, Bengaluru, Karnataka, 120(available capacity in hospital)
H2, Bengaluru, Karnataka, 0
Bonus: showIndustries():
I1, Bengaluru, Karnataka, 50
