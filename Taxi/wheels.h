#ifndef WHEELS
#define WHEELS
#include "wheel.h"
#include <fstream>

class Wheels{

public:
	Wheels(int wheels[8]);
	~Wheels(){ cout << "Dtor Wheels" << endl; }
	void setRadius(int radius);
	int getRadius();
	void printMe();
	void printMe(ofstream &mystream);
private:
	Wheel fr;
	Wheel fl;
	Wheel rr;
	Wheel rl;
};

#endif