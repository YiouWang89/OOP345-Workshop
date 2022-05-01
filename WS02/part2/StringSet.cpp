// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-1-26
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include<iostream>
#include<string>
#include<fstream>
#include "StringSet.h"
using namespace std;
namespace sdds {
	StringSet::StringSet()
	{
		
	}
	StringSet::StringSet(const char* fname)
	{
		std::string temp;
		std::ifstream filein(fname);
		if (filein) {
			while (!filein.eof()) {
				if (getline(filein, temp, ' ')) {
					stringNo++;
				}
			}
			filein.close();
			m_string = new std::string[stringNo + 1];
			filein.open(fname);
			for (unsigned int i = 0u; i < stringNo; i++) {
				getline(filein, m_string[i], ' ');
			}
		}
	}
	size_t StringSet::size() const
	{
		return stringNo;
	}
	std::string StringSet::operator[](size_t index)
	{
		std::string temp{};
		if (size()!=0 && index <= size()) {
			temp = m_string[index];
		}
		return temp;
	}
	StringSet::StringSet(const StringSet& src)
	{
		*this = src;
	}
	StringSet& StringSet::operator=(const StringSet& src)
	{
		if (this != &src) {
			delete[] m_string;
			stringNo = src.stringNo;
			m_string = new std::string[stringNo + 1];
			for (unsigned int i = 0u; i < stringNo; i++) {
				m_string[i] = src.m_string[i];
			}
		}
		return *this;
	}
	StringSet::StringSet(StringSet&& src)
	{
		*this = std::move(src);
	}
	StringSet& StringSet::operator=(StringSet&& src)
	{
		if (this != &src) {
			delete[] m_string;
			m_string = src.m_string;
			src.m_string = nullptr;
			stringNo = src.stringNo;
			src.stringNo = 0u;
		}
		return *this;
	}
	StringSet::~StringSet()
	{
		delete[] m_string;
	}
}
