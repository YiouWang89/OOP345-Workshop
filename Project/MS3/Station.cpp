// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iomanip>
#include <iostream>
#include "Station.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	size_t Station::m_widthField = 0u;
	size_t Station::id_generator = 0u;


	Station::Station(const string& st)
	{
		Utilities util;
		size_t position = 0u;
		bool more = true;
		m_name = util.extractToken(st, position, more);
		m_serialNumber = stoi(util.extractToken(st, position, more));
		m_currentNum = stoi(util.extractToken(st, position, more));
		if (m_widthField < util.getFieldWidth())
			m_widthField = util.getFieldWidth();
		m_description = util.extractToken(st, position, more);
		id_generator++;
		m_id = id_generator;
	}

	const std::string& Station::getItemName() const
	{
		return m_name;
	}

	unsigned int Station::getNextSerialNumber()
	{
		size_t serialNum = m_serialNumber;
		m_serialNumber++;
		return serialNum;
	}

	unsigned int Station::getQuantity() const
	{
		return m_currentNum;
	}

	void Station::updateQuantity()
	{
		m_currentNum > 0 ? m_currentNum-- : m_currentNum;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		if (!full) {
			os << "[" << setw(3) << setfill('0') << right << m_id << "] "
				<< "Item: " << left << setw(m_widthField) << setfill(' ') << m_name
				<< " [" << setw(6) << setfill('0') << right << m_serialNumber << "]";
		}
		else {
			os << "[" << setw(3) << setfill('0') << right << m_id << "] "
				<< "Item: " << left << setw(m_widthField) << setfill(' ') << m_name
				<< " [" << setw(6) << setfill('0') << right << m_serialNumber << "] "
				<< "Quantity: " << left << setfill(' ') << setw(m_widthField) << m_currentNum
				<< " Description: " << m_description;
		}
		os << endl;
	}
}

