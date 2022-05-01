// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-09
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds {
	Car::Car(std::istream& in)
	{
		string tag, temp, condition;
		getline(in, temp);
		tag = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		tag.erase(0, tag.find_first_not_of(" "));
		tag.erase(tag.find_last_not_of(" ") + 1);
		if (tag == "C" || tag == "c") {
			m_maker = temp.substr(0, temp.find(','));
			temp.erase(0, temp.find(',') + 1);
			m_maker.erase(0, m_maker.find_first_not_of(" "));
			m_maker.erase(m_maker.find_last_not_of(" ") + 1);

			condition = temp.substr(0, temp.find(','));
			temp.erase(0, temp.find(',') + 1);
			condition.erase(0, condition.find_first_not_of(" "));
			condition.erase(condition.find_last_not_of(" ") + 1);
			if (condition == "n" || condition == "N")
				m_condition = "new";
			if (condition == "u" || condition == "U")
				m_condition = "used";
			if (condition == "b" || condition == "B")
				m_condition = "broken";

		m_topSpeed = stod(temp.substr(0, temp.find('\n')));
		}
	}
	std::string Car::condition() const
	{
		return m_condition;
	}
	double Car::topSpeed() const
	{
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << setw(10) << right << m_maker << " | " << setw(6) << left << m_condition
			<< " | " << setw(6) << fixed << setprecision(2)
			<< m_topSpeed << " |" << endl;
	}
}
