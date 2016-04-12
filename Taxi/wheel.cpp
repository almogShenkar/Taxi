#include "wheel.h"

void  Wheel::setRadius(int radius){
	this->radius = radius;
};

int Wheel::getRadius(){
	return radius;
};

void Wheel::printMe(ofstream &mystream){
	mystream << '(' << radius << "," << thick << ')' << endl;
}

void Wheel::printMe(){
	cout << '('<<radius<<","<<thick<<')'<<endl;
};