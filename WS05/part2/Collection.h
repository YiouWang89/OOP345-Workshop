// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-02-20
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <string>
#include <stdexcept>
namespace sdds {
	template <typename T>
	class Collection
	{
		std::string m_collection = "";
		T* m_array = nullptr;
		size_t m_size = 0u;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(const std::string& name) {
			m_collection = name;
		};

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		~Collection() {
			delete[] m_array;
			m_array = nullptr;
		};

		const std::string& name() const { return m_collection; };

		size_t size() const { return m_size; };

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		};

		Collection<T>& operator+=(const T& item) {
			bool exsit = false;
			for (size_t i = 0u; i < m_size; i++) {
				if (m_array[i].title() == item.title())
					exsit = true;
			}
			if (!exsit) {
				T* temp = m_array;
				m_array = new T [m_size + 1];
				for (size_t i = 0u; i < m_size; i++) {
					m_array[i] = temp[i];
				}
				m_array[m_size] = item;
				m_size++;
				delete[] temp;
				if (m_observer != nullptr) {
					m_observer(*this, item);
				}
				return *this;
			}
			else {
				return *this;
			}
		};

		T& operator[](size_t idx) const {
			if (idx < 0u || idx >= m_size) {
				std::string erroemess = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(erroemess);
			}
				return m_array[idx];
		};

		T* operator[](const std::string& title) const {
			T* temp = nullptr;
			for (size_t i = 0u; i < m_size; i++)
			{
				if (m_array[i].title() == title)
				{
					temp = &m_array[i];
				}
			}
			return temp;
		};
	};
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0u; i < collection.size(); i++) {
			os << collection[i];
		}
		return os;
	};
}
#endif // !SDDS_COLLECTION_H_


