// Workshop 9 - Multi-Threading
// SecureData.cpp

// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2021-03-21
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.


#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		converter(text, key, nbytes, Cryptor());
		auto th = bind(converter, text, key, nbytes, Cryptor());
		thread t1(th);
		thread t2(th);
		thread t3(th);
		thread t4(th);

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			ofstream fi(file, ios::binary);

			if (!fi) {
				throw string("\n***Failed to open file***\n ");
			}
			else {
				fi.write(text, nbytes);
			}
			fi.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		ifstream fi(file, ios::binary);
		if (!fi) {
			throw string("\n***Failed to open file***\n");
		}
		else {
			if (!text) {
				delete[] text;
			}
			fi.seekg(0, ios::beg);

			text = new char[nbytes + 1];
			fi.read(text, nbytes);
			text[nbytes] = '\0';
		}
		fi.close();


		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
