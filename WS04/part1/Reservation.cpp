// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-11
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds {
	Reservation::Reservation()
	{
	};
	Reservation::Reservation(const std::string& res)
	{
		string str = res;
		
		m_id = str.substr(0, str.find(':'));
		str.erase(0, str.find(':') + 1);
		m_id.erase(m_id.find_last_not_of(" ") + 1);
		m_id.erase(0, m_id.find_first_not_of(" "));
		
		
		m_name= str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		m_name.erase(m_name.find_last_not_of(" ") + 1);
		m_name.erase(0, m_name.find_first_not_of(" "));

		m_email = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		m_email.erase(m_email.find_last_not_of(" ") + 1);
		m_email.erase(0, m_email.find_first_not_of(" "));

		m_size = stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		m_day = stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		m_hour = stoi(str.substr(0, str.find(',')));
	};

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		int flag = 0;
		string man, email;
		if (res.m_hour >= 6 && res.m_hour <= 9) flag = 1;
		if (res.m_hour >= 11 && res.m_hour <= 15) flag = 2;
		if (res.m_hour >= 17 && res.m_hour <= 21) flag = 3;
		email = "  <" + res.m_email + ">";
		if (res.m_size == 1)
			man = "person";
		else
			man = "people";
		switch (flag) {
		case 1:
			os << "Reservation " << right << setw(10) << res.m_id << ": " << setw(20) << res.m_name << left << setw(26) << email << "Breakfast on day " << res.m_day << " @ " << res.m_hour << ":00" << " for " << res.m_size << " " << man << "." << endl;
			break;
		case 2:
			os << "Reservation " << right << setw(10) << res.m_id << ": " << setw(20) << res.m_name << left << setw(26) << email << "Lunch on day " << res.m_day << " @ " << res.m_hour << ":00" << " for " << res.m_size << " " << man << "." << endl;
			break;
		case 3:
			os << "Reservation " << right << setw(10) << res.m_id << ": " << setw(20) << res.m_name << left << setw(26) << email << "Dinner on day " << res.m_day << " @ " << res.m_hour << ":00" << " for " << res.m_size << " " << man << "." << endl;
			break;
		case 0:
			os << "Reservation " << right << setw(10) << res.m_id << ": " << setw(20) << res.m_name << left << setw(26) << email << "Drinks on day " << res.m_day << " @ " << res.m_hour << ":00" << " for " << res.m_size << " " << man << "." << endl;
			break;
		}

		return os;
	}

}

