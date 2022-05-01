// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-08
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_
namespace sdds {
	class Racecar:public Car
	{
		double m_booster = 0;
	public:
		Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif // !SDDS_RACECAR_H_

