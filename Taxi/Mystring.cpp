#include "mystring.h"
	
Mystring::Mystring()
	{
		cout << "Mystring default Ctor" << endl;
		this->_length = 0;
		this->_size = 0;
		this->_string = NULL;
	}
Mystring::Mystring(const char* str)
	{
		cout << "Mystring copy Ctor" << endl;
		this->_length = strlen(str);
		this->_size = this->_length + 1;
		this->_string = new char[this->_size];

		strcpy_s(this->_string, this->_size, str);
	}
Mystring::~Mystring()
	{
		cout << "Mystring Dtor" << endl;
		if (this->_string != NULL)
		{
			delete[] this->_string;
			this->_string = NULL;
		}
	}

void Mystring::printMe(){
		cout << _string;
	}


void Mystring::printMe(ostream& mystream){
		mystream << _string;
	}


