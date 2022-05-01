// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-27
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include <string>
namespace sdds {
    class Utilities {
        size_t m_widthField = 1u;
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}
#endif // !SDDS_UTILITIES_H_
