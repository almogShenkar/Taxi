#include "brain.h"

double Brain::getVersion(){ return version; }

void Brain::setVersion(double nVersion){ version = nVersion; }

void Brain::printMe(){
	cout << "Brain version: " << version<<endl;
};


void Brain::printMe(ofstream &mystream){
	mystream << "Brain: " << version<<endl;
}
