#ifndef SENSORS
#define SENSORS
#include "mystring.h"
#include <fstream>

class Sensors{

public:
	Sensors(char** sensors);
	~Sensors()
	{
		cout << "Dtor sensors" << endl;
		delete[] sensorsArray; }
	void printMe();
    void printMe(ofstream &mystream);
	//set's not needed for now
	//get's not needed for now

private:
	Mystring* sensorsArray;

};

#endif