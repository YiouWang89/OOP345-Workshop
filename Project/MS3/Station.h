// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-31
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_
#include <string>
namespace sdds {
    class Station {
        size_t m_id = 0u;
        std::string m_name;
        std::string m_description;
        size_t m_serialNumber;
        size_t m_currentNum;
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string& st);
        const std::string& getItemName() const;
        unsigned int getNextSerialNumber();
        unsigned int getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;

    };
}
#endif // !SDDS_STATION_H_