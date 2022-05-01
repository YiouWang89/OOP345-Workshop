// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-08
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Autoshop.h"
using namespace std;
namespace sdds {
	Autoshop::Autoshop()
	{
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end();i++) {
			(*i)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop()
	{
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			delete (*i);
		}
	}
}