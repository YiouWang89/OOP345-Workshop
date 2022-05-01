#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-25
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif