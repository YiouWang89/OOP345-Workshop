// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-20
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename)
	{
		const char* ch= "Bad file name!";
		std::ifstream file(filename);
		if (!file)
			throw ch;
		else {
			for (size_t i = 0u; i < 6u;) {
				string str;
				getline(file, str);
				m_badWords[i] = str.substr(0, str.find(" "));
				str.erase(0, str.find(" ") + 1);
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(" "));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(" ") + 1);

				m_goodWords[i] = str.substr(0, str.find('\n'));
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(" "));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(" ") + 1);
				i++;
			}
		}
		file.close();
	}
	void SpellChecker::operator()(std::string& text)
	{

		for (size_t i = 0u; i < 6u; i++) {
			int idx = text.find(m_badWords[i]);
			while (idx != -1) {
				text.replace(idx, m_badWords[i].length(), m_goodWords[i]);
				m_noMisspe[i]++;
				idx = text.find(m_badWords[i]);
			}
		}
		
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0u; i < 6; i++) {
			out << right << setw(15) << m_badWords[i] << ": " << m_noMisspe[i] << " replacements" << endl;
		}
	}
}
