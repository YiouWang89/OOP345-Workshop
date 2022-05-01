// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_
#include <vector>
#include "Workstation.h"
namespace sdds {
	class LineManager
	{
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder = 0u;
		Workstation* m_firstStation = nullptr;
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_LINEMANAGER_H_



