// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <sstream>
#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter = ' ';
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		string token;
		size_t start_pos = next_pos;
		if (more) {
			next_pos = str.find(m_delimiter, start_pos);
			token = str.substr(start_pos, next_pos - start_pos);
			if (token[0] == m_delimiter || str[start_pos] == m_delimiter) {
				more = false;
				throw ("a delimiter is found at next_pos");
			}

			if (next_pos < str.size()) 
				more = true;
			else 
				more = false;
			if (m_widthField < token.size()) 
				m_widthField = token.size();

			next_pos++;
		}
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}