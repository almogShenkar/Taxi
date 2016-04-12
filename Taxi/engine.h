#ifndef ENGINE
#define ENGINE
#include "mystring.h"
#include <fstream>

class Engine{

public:
	Engine(char* status, int power, double version):status(status),power(power),version(version){
		cout << "Ctor Engine" << endl;
	};
	~Engine(){ cout << "Dtor Engine" << endl; status.~Mystring(); };
	void setPower(int power);
	int getPower();
	void printMe();
	void printMe(ofstream &mystream);
	
private:
	Mystring status;
	int power;
	double version;
};

#endif