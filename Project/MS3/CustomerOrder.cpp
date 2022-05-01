// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthield = 0u;
	CustomerOrder::CustomerOrder()
	{
	}
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util;
		size_t position = 0u;
		bool more = true;
		m_name = util.extractToken(str, position, more);
		m_product = util.extractToken(str, position, more);
		m_cntItem = count(str.begin(), str.end(), util.getDelimiter()) - 1;
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0u; i < m_cntItem; i++) {
			m_lstItem[i] = new Item(util.extractToken(str, position, more));
		}
		m_widthield = max(m_widthield, util.getFieldWidth());
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder)
	{
		throw string("Copy Constructor are not allow");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) noexcept
	{
		*this = move(customerOrder);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& customerOrder)noexcept
	{
		if (this != &customerOrder) {
			for (size_t i = 0u; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_name = customerOrder.m_name;
			m_product = customerOrder.m_product;
			m_cntItem = customerOrder.m_cntItem;
			m_lstItem = customerOrder.m_lstItem;

			customerOrder.m_cntItem = 0u;
			customerOrder.m_product = "";
			customerOrder.m_name = "";
			customerOrder.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool CustomerOrder::isFilled() const
	{
		bool filled = true;
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (!(m_lstItem[i]->m_isFilled))
				filled = false;
		}
		return filled;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = false;
		size_t exist = 0u;
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				exist++;
				if (m_lstItem[i]->m_isFilled) {
					filled = true;
				}
			}
		}
		if (exist == 0u)
			filled = true;
		return filled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() >= 1) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
			}
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled && station.getQuantity() == 0) {
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "] " << endl;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		string status;
		os << setw(5) << setfill(' ') << m_name << " - " << m_product << endl;
		for (size_t i = 0u; i < m_cntItem; i++) {
			
			if (isItemFilled(m_lstItem[i]->m_itemName))
				status = "FILLED";
			else
				status = "TO BE FILLED";
			os << "[" << setw(6) << right << setfill('0') << m_lstItem[i]->m_serialNumber << "] "
				<< setw(m_widthield) << setfill(' ') << left << m_lstItem[i]->m_itemName << " - " << status << endl;
		}
	}
}
