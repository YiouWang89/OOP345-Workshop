// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-2-04
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
namespace sdds {
	template <unsigned int N, typename T>
	class Set {
		T ele[N];
		unsigned int NoEle = 0u;
	public:
		size_t size() const {
			return NoEle;
		}
		const T& get(size_t idx) const {
			return ele[idx];
		}
		void operator+=(const T& item) {
			if (NoEle < N) {
				ele[NoEle] = item;
				NoEle++;
			};
		}
	};
}
#endif