#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace sdds;
using namespace std;

unsigned int g_sysClock;

Event::Event()
{
	description = nullptr;
	StarTime = 0;
}

sdds::Event::Event(Event& fil)
{
	if (this != &fil) {
		set(fil.description);
		StarTime = fil.StarTime;
	}
}

Event& sdds::Event::operator=(const Event& fil)
{
	if (this != &fil) {
		set(fil.description);
		StarTime = fil.StarTime;
	}
	return *this;
	// TODO: insert return statement here
}

void sdds::Event::display()
{
	static int counter = 0;
	size_t h = StarTime / 60 / 60;
	size_t min = (StarTime - h * 60 * 60) / 60;
	size_t sec = StarTime % 60;
	if (description) {
		cout << setw(2) << setfill(' ') << ++counter << ". " << setfill('0') << setw(2) << h << ":"
			<< setw(2) << min << ":" << setw(2) << sec << " => " << description << endl;
	}
	else {
		cout << setw(2) << setfill(' ') << ++counter << ". " << "| No Event |" << endl;
	}
}

void sdds::Event::set()
{
	description = nullptr;
}

void sdds::Event::set(char* desc)
{

	if (desc) {
		description = new char[strlen(desc) + 1];
		strcpy(description, desc);
		StarTime = g_sysClock;
	}

}

sdds::Event::~Event()
{
	delete[] description;
	description = nullptr;
}
