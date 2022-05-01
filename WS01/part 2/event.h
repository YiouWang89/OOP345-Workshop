#pragma once
// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-1-21
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_

extern unsigned int g_sysClock;

namespace sdds {
	class Event {
		char* description;
		size_t StarTime;
	public:
		Event();
		Event(Event& fil);
		Event& operator=(const Event&);
		void display();
		void set();
		void set(char* desc);
		~Event();
	};
}
#endif // !SDDS_EVENT_H_
