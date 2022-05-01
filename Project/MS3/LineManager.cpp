// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Utilities.h"
#include "LineManager.h"
using namespace std;
namespace sdds {
	LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations)
	{
		string temp;
		Utilities util;
		string currentstation, nextstation;
		Workstation* ws = nullptr;
		Workstation* wsNext = nullptr;
		ifstream file(filename);
		if (file) {
			while (!file.eof()) {
				util.setDelimiter('|');
				getline(file, temp);
				bool more = true;
				size_t position = 0u;
				currentstation = util.extractToken(temp, position, more);
				nextstation = more ? (util.extractToken(temp, position, more)) : "";
				ws = *find_if(stations.begin(), stations.end(), [currentstation](Workstation* ws) {
					return ws->getItemName() == currentstation;
					});
				if (!nextstation.empty()) {
					wsNext = *find_if(stations.begin(), stations.end(), [nextstation](Workstation* ws) {
						return ws->getItemName() == nextstation;
						});
				}
				else {
					wsNext = nullptr;
				}
				ws->setNextStation(wsNext);
				activeLine.push_back(ws);
			}
		}
		else
			throw string("Can not open the file" + filename);
		file.close();


		//identifies the first station in the assembly line, stores its address in the m_firstStation attribute

		/*for (size_t i = 0u; i < activeLine.size(); i++) {
			size_t count = 0u;
			for (size_t j = 0u; j < activeLine.size(); j++) {
				if ((activeLine[j]->getNextStation() != nullptr) && (activeLine[i]->getItemName() == activeLine[j]->getNextStation()->getItemName())){
					count++;
					j = activeLine.size();
				}	
			}
			if (count == 0u) {
				m_firstStation = activeLine[i];
				i = activeLine.size();
			}
		};*/

		vector<Workstation*> activeLine1(activeLine);
		m_firstStation = *find_if_not(activeLine1.begin(), activeLine1.end(), [activeLine1](const Workstation* ws1)
			{
				return any_of(activeLine1.begin(), activeLine1.end(), [ws1](const Workstation* ws2) {
					return ws1 == ws2->getNextStation(); });
			});
			

		m_cntCustomerOrder = pending.size();
	}
	void LineManager::linkStations()
	{
		vector<Workstation*> reorder;
		reorder.push_back(m_firstStation);
		for (size_t i = 0u; i < activeLine.size(); i++) {
			for (size_t j = 0u; j < activeLine.size(); j++) {
				if ((reorder[i]->getNextStation() != nullptr) && reorder[i]->getNextStation()->getItemName() == activeLine[j]->getItemName()) {
					reorder.push_back(activeLine[j]);
					j = activeLine.size();
				};
			}
		}
		activeLine = reorder;
		
	}
	bool LineManager::run(std::ostream& os)
	{
		bool filled = false;
		static size_t count = 0u;
		os << "Line Manager Iteration: " << 1+(count++) << endl;
		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}

		for (size_t i = 0u; i < activeLine.size(); i++) {
			activeLine[i]->fill(os);
		}

		for (size_t i = 0u; i < activeLine.size(); i++) {
			activeLine[i]->attemptToMoverOrder();
		}
	
		if (completed.size() == m_cntCustomerOrder)
			filled = true;
		return filled;
	}
	void LineManager::display(std::ostream& os) const
	{
		for_each(activeLine.begin(), activeLine.end(), [](Workstation* ws) {ws->dispaly(cout); });
	}
}
