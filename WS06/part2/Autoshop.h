// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-08
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_
#include <list>
#include <vector>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif // !SDDS_AUTOSHOP_H_

