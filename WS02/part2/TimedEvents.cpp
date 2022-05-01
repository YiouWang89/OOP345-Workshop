// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-1-26
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.


#include<iomanip>
#include "TimedEvents.h"

namespace sdds {
	sdds::TimedEvents::TimedEvents()
	{
		eventNo = 0u;
		startClock();
		stopClock();
	}

	void sdds::TimedEvents::startClock()
	{
		startT = std::chrono::steady_clock::now();
	}

	void sdds::TimedEvents::stopClock()
	{
		endT = std::chrono::steady_clock::now();
	}

	void sdds::TimedEvents::addEvent(const char* nameEvent)
	{
		if (eventNo < maxEvent) {
			Event[eventNo].eventName = nameEvent;
			Event[eventNo].uniTime = "nanoseconds";
			Event[eventNo].durEvent = std::chrono::duration_cast<std::chrono::nanoseconds>(endT - startT);
			eventNo++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& TimE)
	{
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (unsigned int i = 0u; i < TimE.eventNo; i++) {
			os << std::setw(21) << std::left << TimE.Event[i].eventName << " ";
			os << std::setw(13) << std::right << TimE.Event[i].durEvent.count() << " " << TimE.Event[i].uniTime << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}