// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-09
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_
#include <vector>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
	};
}
#endif // !SDDS_AUTOSHOP_H_

