// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-11
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, ConfirmationSender& con)
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (con.m_noCon == 0) {
			os << "There are no confirmations to send!" << endl;
		}
		else
			for (size_t i = 0u; i < con.m_noCon; i++) {
				os << *con.m_res[i];
			}
		os << "--------------------------" << endl;
		return os;
	}
	ConfirmationSender::ConfirmationSender()
	{
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& con)
	{
		*this = con;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& con)
	{
		if (this != &con) {
			delete[] m_res;
			m_noCon = con.m_noCon;
			m_res = new const Reservation* [m_noCon];
			for (size_t i = 0u; i < m_noCon; i++) {
				m_res[i] = con.m_res[i];
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& con)
	{
		*this = move(con);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& con)
	{
		if (this != &con) {
			delete[] m_res;
			m_res = con.m_res;
			con.m_res = nullptr;
			m_noCon = con.m_noCon;
			con.m_noCon = 0u;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool flag = false;
		for (size_t i = 0u; i < m_noCon; i++) {
			if (m_res[i] == &res)
				flag = true;
		}
		if (!flag) {
			const Reservation** temp = nullptr;
				temp = new const Reservation * [m_noCon + 1];
				for (size_t i = 0u; i < m_noCon; i++) {
					temp[i] = m_res[i];
				}
				temp[m_noCon] = &res;
				m_noCon++;
				delete[] m_res;
				m_res = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool flag = false;
		unsigned index;
		for (size_t i = 0u; i < m_noCon; i++) {
			if (m_res[i] == &res) {
				flag = true;
				index = i;
			}	
		}
		if (flag) {
			const Reservation** temp = nullptr;
			if (m_noCon > 0) {
				temp = new const Reservation * [m_noCon - 1];
				for (size_t i = 0; i < m_noCon - 1; i++) {
					if (i < index) {
						temp[i] = m_res[i];
					}
					else {
						temp[i] = m_res[i + 1];
					}
				}
			}
			m_noCon--;
			delete[] m_res;
			m_res = temp;
		}
		
		return *this;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_res;
		m_res = nullptr;
	}
}
