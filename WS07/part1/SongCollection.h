// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-18
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_SONGCOLLECTION_H_
#define SDDS_SONGCOLLECTION_H_
#include <string>
#include <vector>
namespace sdds {
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price = 0.0;
		std::string m_year;
		size_t m_length = 0u;
	};
	class SongCollection
	{
		std::vector<Song> m_songs;
	public:
		SongCollection(const std::string filename);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H_
