// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-07
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_PAIRSUMMABLE_H_
#define SDDS_PAIRSUMMABLE_H_

#include "Pair.h"
namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t min_file_w;
	public:
		PairSummable() :Pair<V, K>(){};
		PairSummable(const K& key, const V& value = initial) :Pair<V, K>(key, value){
			if (key.size() > min_file_w)
				min_file_w = key.size();
		};
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return this->key() == b.key() ? true : false;
		};
		PairSummable& operator+=(const PairSummable<V, K>& pairsumm) {
			return *this = PairSummable(pairsumm.key(), (this->value() + pairsumm.value()));;
		};
		void display(std::ostream& os) const {
			os << std::left << std::setw(min_file_w);
			Pair<V, K>::display(os);
			os << std::right;
		};
	};
	
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& pairsumm) {
		if (this->value().size() == 0) {
			*this = PairSummable(pairsumm.key(), (pairsumm.value()));
		}
		else {
			*this = PairSummable(pairsumm.key(), (this->value() + ", " + pairsumm.value()));
		}
		return *this;
	};

	template<typename V, typename K>
	size_t PairSummable<V, K>::min_file_w = 0u;

	template<typename V, typename K>
	V PairSummable<V, K>::initial;
}

#endif // !SDDS_PAIRSUMMABLE_H_
