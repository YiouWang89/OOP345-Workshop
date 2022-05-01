// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-11
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include<string>
#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_

namespace sdds {
	class Reservation
	{
		std::string m_id = "";
		std::string m_name = "";
		std::string m_email = "";
		size_t m_size = 1u;
		size_t m_day = 1u;
		size_t m_hour = 1u;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}
#endif // !SDDS_RESERVATION_H_


