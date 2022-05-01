// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-17
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book()
	{
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_publicCoun;
	}
	const size_t& Book::year() const
	{
		return m_publicY;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		string str = strBook;

		m_author = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		m_author.erase(m_author.find_last_not_of(" ") + 1);
		m_author.erase(0, m_author.find_first_not_of(" "));

		m_title = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		m_title.erase(m_title.find_last_not_of(" ") + 1);
		m_title.erase(0, m_title.find_first_not_of(" "));

		m_publicCoun = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		m_publicCoun.erase(m_publicCoun.find_last_not_of(" ") + 1);
		m_publicCoun.erase(0, m_publicCoun.find_first_not_of(" "));

		m_price = stod(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		m_publicY = stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		m_des = str.substr(0, str.find('\n'));
		m_des.erase(m_des.find_last_not_of(" ") + 1);
		m_des.erase(0, m_des.find_first_not_of(" "));
	}
	

	std::ostream& operator<<(std::ostream& os,const Book& book)
	{
		os << setw(20) << right << book.m_author << " | " << setw(22) << book.m_title << " | "
			<< setw(5) << book.m_publicCoun << " | " << setw(4) << book.m_publicY << " | " << setw(6)
			<< fixed << setprecision(2) << book.m_price << " | " << book.m_des << endl;
		return os;
	}

}
