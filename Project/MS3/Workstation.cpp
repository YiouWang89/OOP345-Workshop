// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#include <utility>
#include "Workstation.h"
using namespace std;
namespace sdds {
	deque<CustomerOrder> pending;
	deque<CustomerOrder> completed;
	deque<CustomerOrder> incomplete;

	Workstation::Workstation(const std::string& name):Station(name)
	{
	}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty()) 
			m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoverOrder()
	{
		bool moved = false;

		if ( !m_orders.empty() && m_orders.front().isItemFilled(getItemName())) {
			if (!m_pNextStation) {
				completed.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
			}
			else {
				m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
				moved = true;
			}
		}
		if (getQuantity() <= 1 && !m_orders.empty()) {
			m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
			m_orders.pop_front();
			moved = true;
			if (!m_pNextStation) {
				incomplete.push_back(m_orders.front());
				m_orders.pop_front();
			}
		}
		return moved;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	const Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::dispaly(std::ostream& os) const
	{
		os << getItemName();
		if (m_pNextStation) {
			os << " --> " << m_pNextStation->getItemName() << endl;
		}
		else {
			os << " --> End of Line" << endl;
		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
	
}
