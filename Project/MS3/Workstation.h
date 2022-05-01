// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_WORKSTATION_H_
#define SDDS_WORKSTATION_H_
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds {
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation:public Station 
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;
	public:
		Workstation(const std::string&);
		void fill(std::ostream&);
		bool attemptToMoverOrder();
		void setNextStation(Workstation*);
		const Workstation* getNextStation()const;
		void dispaly(std::ostream&)const;
		Workstation& operator+=(CustomerOrder&&);

		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

	};

}
#endif // !SDDS_WORKSTATION_h_


