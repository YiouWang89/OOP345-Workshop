// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-21
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		for (size_t i = 0u; i < desc.size(); i++) {
			for (size_t j = 0u; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* pro = new Product(desc[i].desc, price[j].price);
					pro->validate();
					priceList += pro;
					delete pro;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		for (size_t i = 0u; i < desc.size(); i++) {
			for (size_t j = 0u; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					unique_ptr<Product> pro(new Product(desc[i].desc, price[j].price));
					pro->validate();
					priceList += pro;
				}
			}
		}
		return priceList;
	}
}
