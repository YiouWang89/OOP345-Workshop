// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-08
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <sstream>
#include <iostream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptr = nullptr;
		string temp;
		stringstream str;
		getline(in, temp);
		temp.erase(0, temp.find_first_not_of(' '));
		str.str(temp);
		if (!temp.empty()) {
			if (temp[0] == 'c' || temp[0] == 'C')
				ptr = new Car(str);
			else if (temp[0] == 'r' || temp[0] == 'R')
				ptr = new Racecar(str);
			else
				throw char(temp[0]);
		}
		return ptr;
	}
}
