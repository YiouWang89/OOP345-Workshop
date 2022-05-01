// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-20
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <string>
namespace sdds {
	class Movie
	{
		std::string m_movtitle = "";
		size_t m_movY = 0u;
		std::string m_movdes = "";
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_movtitle);
			spellChecker(m_movdes);
		}
		friend std::ostream& operator << (std::ostream&,const Movie&);
	};
}
#endif // !SDDS_MOVIE_H_



