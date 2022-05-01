// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-1-26
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_TimedEvent_H_
#define SDDS_TimedEvent_H_
#include<chrono>
namespace sdds {
	const unsigned int maxEvent = 10u;
	class TimedEvents
	{
		unsigned int eventNo;
		std::chrono::steady_clock::time_point startT;
		std::chrono::steady_clock::time_point endT;
		struct {
			std::string eventName{};
			std::string uniTime{};
			std::chrono::steady_clock::duration durEvent;
		}Event[maxEvent];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* nameEvent);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& TimE);
	};
}

#endif // !SDDS_TimedEvent_H_



