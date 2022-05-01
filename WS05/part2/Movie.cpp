// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-20
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds{
	Movie::Movie()
	{
	}
	const std::string& Movie::title() const
	{
		return m_movtitle;
	}
	Movie::Movie(const std::string& strMovie)
	{
		string str = strMovie;

		m_movtitle = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		m_movtitle.erase(m_movtitle.find_last_not_of(" ") + 1);
		m_movtitle.erase(0, m_movtitle.find_first_not_of(" "));

		m_movY = stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		m_movdes = str.substr(0, str.find('\n'));
		m_movdes.erase(0, m_movdes.find_first_not_of(" "));
		m_movdes.erase(m_movdes.find_last_not_of(" ") + 1);
	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << setw(40) << movie.m_movtitle << " | " << setw(4) << movie.m_movY << " | " << movie.m_movdes << std::endl;
		return os;
	}
}