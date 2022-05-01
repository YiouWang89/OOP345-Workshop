// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-04
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include<iostream>
namespace sdds {
	template<typename V, typename K>
	class Pair {
		V m_value;
		K m_key;
	public:
		Pair() :m_value{ 0 }, m_key {0} {
		};
		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		};
		const V& value() const {
			return m_value;
		};
		const K& key() const {
			return m_key;
		};
		void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		};
		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		};
	};
	
}
#endif// !SDDS_PAIR_H_

