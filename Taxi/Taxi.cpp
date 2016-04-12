#include "Taxi.h"



Taxi::Taxi(int id, char* Estatus, int Epower, double Eversion, int Wheels[8], double Brain,char* Sensors[]):
id(id), km(0), engine(Estatus, Epower, Eversion), wheels(Wheels), brain(Brain), sensors(Sensors), passenger(0)
{
	cout << "Ctor default Taxi" << endl;
};




void Taxi::printMe(ofstream &mystream){
	mystream << "id:" << id << ",km:" << km << ",Engine: ";
	engine.printMe(mystream);
	mystream << endl;
	wheels.printMe(mystream);
	brain.printMe(mystream);
	sensors.printMe(mystream);
};

void Taxi::printMe(){
	cout << "id:"<<id <<",km:"<< km<<",Engine:";
	engine.printMe();
	cout << endl;
	wheels.printMe();
	brain.printMe();
	sensors.printMe();
}


void Taxi::goAhead(int km){ this->km += km; }
void Taxi::goBack(int km){ this->km += km; }
void Taxi::turnRight(int radius){ this->wheels.setRadius(radius); }
void Taxi::turnLeft(int radius){ this->wheels.setRadius(radius); }
void Taxi::pickPassenger(){
	++passenger; 
	cout << "================================================================================" << endl;
	cout << passenger << "  is in the taxi right now" << endl<< endl;
	cout << "================================================================================" << endl << endl;
};
void Taxi::dropPassenger(){
	if (passenger)
	--passenger;
	cout << "================================================================================" << endl;
	cout << passenger << "  is in the taxi right now" << endl<< endl;
	cout << "================================================================================" << endl << endl;
};