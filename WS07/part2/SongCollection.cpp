// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-18
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <fstream>
#include "SongCollection.h"

using namespace std;
namespace sdds{
	SongCollection::SongCollection(const std::string filename)
	{
		ifstream file(filename);
		string temp;
		if (file) {
			while (!file.eof())
			{
				Song song;
				getline(file, temp);
				song.m_title = temp.substr(0, 25);
				song.m_artist = temp.substr(25, 25);
				song.m_album = temp.substr(50, 25);
				song.m_year = temp.substr(75, 5);
				song.m_length = stoi(temp.substr(80, 5));
				song.m_price = stod(temp.substr(85, 5));

				song.m_title.erase(0, song.m_title.find_first_not_of(" "));
				song.m_title.erase(song.m_title.find_last_not_of(" ") + 1);

				song.m_artist.erase(0, song.m_artist.find_first_not_of(" "));
				song.m_artist.erase(song.m_artist.find_last_not_of(" ") + 1);

				song.m_album.erase(0, song.m_album.find_first_not_of(" "));
				song.m_album.erase(song.m_album.find_last_not_of(" ") + 1);

				song.m_year.erase(0, song.m_year.find_first_not_of(" "));
				song.m_year.erase(song.m_year.find_last_not_of(" ") + 1);

				m_songs.push_back(song);
			}
		}
		else {
			throw string("Wrong filename!");
		}

		file.close();
	}

	void SongCollection::display(ostream& out) const
	{
		for_each(m_songs.begin(), m_songs.end(), [](const Song song) {cout << song << endl; });
		size_t totle_time = accumulate(m_songs.begin(), m_songs.end(), 0u, [](size_t length, const Song S) {
			return S.m_length + length;
			});
		size_t hour = totle_time / 60 / 60;
		size_t min = totle_time / 60 - hour * 60;
		size_t second = totle_time % 60;
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << '|' << setw(78) << setfill(' ') << "Total Listening Time: " << hour << ':' << min << ':' << second << " |" << endl;

	}

	void SongCollection::sort(const std::string str)
	{
		std::sort(m_songs.begin(), m_songs.end(), [str](Song s1, Song s2) {
			if (str == "title") return s1.m_title < s2.m_title;
			else if (str == "album") return s1.m_album < s2.m_album;
			else return s1.m_length < s2.m_length;
		});
	}

	void SongCollection::cleanAlbum()
	{
		transform(m_songs.begin(), m_songs.end(), m_songs.begin(), [](Song s) {
			if (s.m_album == "[None]") {
				s.m_album.clear();
			}
				return s;
			});
	}

	bool SongCollection::inCollection(const std::string artist) const
	{
		return any_of(m_songs.begin(), m_songs.end(), [artist](const Song s) {
			return s.m_artist == artist;
			});
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string artist) const
	{
		int n = count_if (m_songs.begin(), m_songs.end(), [artist](const Song s) {
			return s.m_artist == artist;
			});
		list<Song> newlist(n);
		copy_if(m_songs.begin(), m_songs.end(), newlist.begin(), [artist](const Song s) {
			return s.m_artist == artist; });
		return newlist;
	}
	
	ostream& operator<<(ostream& out, const Song& theSong)
	{
		
		out << "| " << left << setw(20) << setfill(' ') << theSong.m_title << " | " << setw(15) << theSong.m_artist
			<< " | " << setw(20) << theSong.m_album << " | " << setw(6) << right << theSong.m_year
			<< " | " << int(theSong.m_length / 60) << ":" << setw(2) << setfill('0') << right << theSong.m_length % 60
			<< " | " << fixed << setprecision(2) << theSong.m_price << " |";
		return out;
	}
}
