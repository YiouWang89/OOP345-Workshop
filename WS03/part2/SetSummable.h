// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-2-07
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_SETSUMMABLE_H_
#define SDDS_SETSUMMABLE_H_
#include"Set.h"
namespace sdds {
	template <unsigned int N, typename T>
	class SetSummable: public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (accumulator.isCompatibleWith(this->get(i)))
					accumulator += this->get(i);
			}
			return accumulator;
		};

	};
}
#endif // !SDDS_SETSUMMABLE_H_

