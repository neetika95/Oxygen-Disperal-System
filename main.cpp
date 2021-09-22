#include <iostream>
#include "OxygenDisperalSystem.h"
using namespace std;
int main()
{
	cout << "----------- OXYGEN DISPERAL SYSTEM  -----------\n\n";
	OxygenDispersalSystem system = OxygenDispersalSystem::getOxygenDisperalSystem();
	system.registerVendor("V1", "BENGALURU", "KARNATAKA", 100, 100);
	system.registerVendor("V2", "BENGALURU", "KARNATAKA", 0, 220);

	system.registerConsumer("H1", ConsumerType::HOSPITAL, "BENGALURU", "KARNATAKA", 260);
	system.registerConsumer("I1", ConsumerType::INDUSTRY, "BENGALURU", "KARNATAKA", 250);
	system.bookOxygen("H1", 150);
	system.changeFallBackBehavior("KARNATAKA", false);
	system.bookOxygen("H1", 110);
	system.changeFallBackBehavior("KARNATAKA", true);
	system.bookOxygen("H1", 110);
	system.bookOxygen("I1", 70);

	cout << "Show all vendors of KARNATAKA " << endl;
	system.showVendors("KARNATAKA");

	system.bookOxygen("I1", 70);

	cout << "Show all vendors of KARNATAKA " << endl;
	system.showVendors("KARNATAKA");

	cout << "Show all industries " << endl;
	system.showIndustries();
	//system.registerVendor("V1", "BENGALURU", "KARNATAKA",100, 100);
	//system.registerVendor("V2", "MYSURU", "D", 50, 100);
	//system.registerVendor("V3", "NOIDA", "UP", 20,30);

	//system.registerConsumer("H1", ConsumerType::HOSPITAL, "BENGALURU", "KARNATAKA", 150);
	//system.registerConsumer("H2", ConsumerType::HOSPITAL, "BENGALURU", "KARNATAKA", 150);
	//system.registerConsumer("H3", ConsumerType::HOSPITAL, "NOIDA", "UP", 1000);
	//system.registerConsumer("I1", ConsumerType::INDUSTRY, "BENGALURU", "KARNATAKA", 150);
	//system.registerConsumer("I2", ConsumerType::INDUSTRY, "NOIDA", "UP", 150);

	//system.changeFallBackBehavior("KARNATAKA", true); // default true


	//cout << "Booking Oygen for I2 for requirement " << 120 << endl; // industry shouldnt eat up hospital resource
	//system.bookOxygen("I2", 120);
	//cout << "Booking Oygen for H1 for requirement " << 120 << endl; // if fallback false should fail, else suceed
	//system.bookOxygen("H1", 120);
	//cout << "Booking Oygen for I1 for requirement " << 100 << endl;
	//system.bookOxygen("I1", 100);
	//cout << "Booking Oygen for H3 for requirement " << 100 << endl; // no vendor has this much quantity;
	//system.bookOxygen("H3", 220);


	//cout << "Show all vendors of KARNATAKA " << endl;
	//system.showVendors("KARNATAKA");
	//cout << "Show all hospitals BENGALURU " << endl;
	//system.showHospitals("BENGALURU");
	//cout << "Show all vendors of UP " << endl;
	//system.showVendors("UP");
	//cout << "Show all industries " << endl;
	//system.showIndustries();
}