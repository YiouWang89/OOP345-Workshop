// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-09
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car:public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed = 0;
	public:
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H_