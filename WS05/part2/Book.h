// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-17
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include<string>
#include "SpellChecker.h"
namespace sdds {
	
	class Book
	{
		std::string m_author = "";
		std::string m_title = "";
		std::string m_publicCoun = "";
		size_t m_publicY = 0u;
		double m_price = 0;
		std::string m_des = "";
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream&, const Book&);
		
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_des);
		}
	};
	
		
}
#endif // !SDDS_BOOK_H_



