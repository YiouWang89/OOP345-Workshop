// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-1-26
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_StringSet_H_
#define SDDS_StringSet_H_

namespace sdds {
	class StringSet
	{
		unsigned int stringNo = 0u;
		std::string* m_string = nullptr;
	public:
		StringSet(); 
		StringSet(const char* fname);
		size_t size() const;
		std::string operator[](size_t index);
		StringSet(const StringSet& src);
		StringSet& operator=(const StringSet& src);
		StringSet(StringSet&& src);
		StringSet& operator=(StringSet&& src);
		~StringSet();
	};
}
#endif // !SDDS_StringSet_H_



