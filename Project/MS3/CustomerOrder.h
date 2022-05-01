// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_CUSTOMERORDER_H_
#define SDDS_CUSTOMERORDER_H_
#include <string>
#include "Station.h"
namespace sdds {
	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };
			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name;
		std::string m_product;
		size_t m_cntItem{ 0u };
		Item** m_lstItem{ nullptr };
		static size_t m_widthield;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&)noexcept;
		CustomerOrder& operator=(CustomerOrder&&)noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_CUSTOMERORDER_H_

