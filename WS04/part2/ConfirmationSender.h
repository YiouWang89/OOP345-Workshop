// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-11
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender
	{
		const sdds::Reservation** m_res{ nullptr };
		unsigned m_noCon = 0u;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream&, ConfirmationSender&);
		~ConfirmationSender();
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H_



