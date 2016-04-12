#ifndef MYSTRING
#define MYSTRING
#include <iostream>
#include <fstream>
using namespace std;
class Mystring
{
public:
	Mystring();
	Mystring(const char* str);
	~Mystring();
	int Length();	
	void printMe();
	void printMe(ostream& mystream);

	Mystring& operator+(const char* str)
	{
		Mystring* temp = new Mystring();
		temp->_length = strlen(str) + strlen(this->_string);
		temp->_size = temp->_length + 1;
		temp->_string = new char[temp->_size];
		strcpy_s(temp->_string, temp->_size, this->_string);
		strcat_s(temp->_string, temp->_size, str);
		return (Mystring&)*temp;
	}

	Mystring& operator=(const Mystring& str)
	{
		if (this != &str)
		{
			this->_length = str._length;
			this->_size = str._size;
			this->_string = new char[this->_size];

			strcpy_s(this->_string, this->_size, str._string);
		}

		return *this;
	}

private:
	int _size;
	int _length;
	char* _string;
};
#endif