#ifndef AutoTaxi
#define AutoTaxi
#include <fstream>
#include <string>
#include "Taxi.h"
											// Autotaxi is the main object contain
using namespace std;

class Autotaxi{

public:
	Autotaxi(char*Fbirth, char*Fcommands, char*Fresult);
	Autotaxi ();
	char** readBirth(ifstream &Fbirth,int &size);
	void CreateTaxi(char**Values, int size);
	~Autotaxi();
	void readRunCmnds(ifstream &Fcommands);
	void printMe();

	private:
		Taxi* t1;
};

#endif