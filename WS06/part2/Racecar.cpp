// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-08
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iomanip>
#include <sstream>
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar()
	{
	}
	Racecar::Racecar(std::istream& in):Car(in)
	{
		string temp;
		getline(in, temp);
		m_booster = stod(temp.substr(0, temp.find('\n')));
	}
	void Racecar::display(std::ostream& out) const
	{
		std::string racecar;
		std::stringstream str_racecar;

		Car::display(str_racecar); 
		racecar = str_racecar.str();
		racecar.erase(racecar.size() - 8);
		out << racecar;
		out << setw(6) << setprecision(2) << fixed << topSpeed();
		out << " |*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}