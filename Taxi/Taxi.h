#ifndef TAXI
#define TAXI
#include <iostream>
#include "mystring.h"
#include "engine.h"
#include "wheels.h"
#include "brain.h"
#include "sensors.h"



class Taxi{

public:
	Taxi(int id,char* Estatus,int Epower,double Eversion,int Wheels[8],double Brain,char* Sensors[]);
	~Taxi(){ cout << "Dtor Taxi" << endl; };
	void printMe(ofstream &stream);
	void printMe();
	void goAhead(int km);
	void goBack(int km);
	void turnRight(int radius);	//on turn only front wheels radius changed!
	void turnLeft(int radius);	//on turn only front wheels radius changed!
	void pickPassenger();
	void dropPassenger();
	//set's not needed for now
	//get's not needed for now
private:

	int id;
	int km;
	Engine engine;
	Wheels wheels;
	Brain brain;
	Sensors sensors;
	int passenger;
};

#endif