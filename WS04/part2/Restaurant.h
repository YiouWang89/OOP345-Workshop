// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-11
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_
#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
		Reservation* m_rev{ nullptr };
		unsigned m_noRev = 0u;
		static unsigned CALL_CNT;
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		Restaurant (const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant (Restaurant&&);
		Restaurant& operator= (Restaurant&&);
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest);
		~Restaurant();
	};
}
#endif // !SDDS_RESTAURANT_H_




