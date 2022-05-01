// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-11
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#include "Restaurant.h"
using namespace std;
namespace sdds {
	unsigned CALL_CNT = 1u;
	Restaurant::Restaurant()
	{
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_noRev = cnt;
		m_rev = new Reservation[cnt];
		for (unsigned i = 0u; i < cnt; i++) {
			m_rev[i] = *reservations[i];
		}
	}
	size_t Restaurant::size() const
	{
		return m_noRev;
	}
	Restaurant::Restaurant(const Restaurant& rest)
	{
		*this = rest;
	}
	Restaurant& Restaurant::operator=(const Restaurant& rest)
	{
		if (this != &rest) {
			delete[] m_rev;
			m_noRev = rest.m_noRev;
			m_rev = new Reservation[m_noRev];
			for (size_t i = 0u; i < m_noRev; i++) {
				m_rev[i] = rest.m_rev[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& rest)
	{
		*this = move(rest);
	}
	Restaurant& Restaurant::operator=(Restaurant&& rest)
	{
		if (this != &rest) {
			delete[] m_rev;
			m_rev = rest.m_rev;
			rest.m_rev = nullptr;
			m_noRev = rest.m_noRev;
			rest.m_noRev = 0u;
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		delete[] m_rev;
		m_rev = nullptr;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& rest)
	{
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << CALL_CNT++ << ")" << endl;
		os << "--------------------------" << endl;
		if (rest.size() == 0)
			os << "This restaurant is empty!" << endl;
		else {
			for (size_t i = 0u; i < rest.size(); i++) {
				os << rest.m_rev[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}
}

