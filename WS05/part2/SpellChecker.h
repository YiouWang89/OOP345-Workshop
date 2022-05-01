// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-20
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <string>
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_noMisspe[6]{ 0u };
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SDDS_SPELLCHECKER_H_


