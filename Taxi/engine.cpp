#include "engine.h"

void Engine::setPower(int power){ this->power = power;}


void Engine::printMe(){
	status.printMe();
	cout << "," << power << "," << version;
};

void Engine::printMe(ofstream &mystream)
{
	status.printMe(mystream);
	mystream << ","<<power << "," << version << " ";
}

int Engine::getPower(){ return power; }