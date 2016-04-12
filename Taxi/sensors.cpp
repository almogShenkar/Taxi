#include "sensors.h"


Sensors::Sensors(char **sensors){
	cout << "Ctor Sensors" << endl;
	sensorsArray = new Mystring[sizeof(sensors)];
	int i=sizeof(sensors);
	int k = 0;
	while (k<i)
	{
		sensorsArray[k].operator=(sensors[k]);
		++k;
	}
}

void Sensors::printMe(){
	int i = 0;
	cout << "sensors:";
	while (i < (sizeof(sensorsArray)))
	{

		sensorsArray[i].printMe();
		cout << ",";
		++i;
	}
	cout << endl;

}

void Sensors::printMe(ofstream &mystream){
	int i = 0;
	while (i < (sizeof(sensorsArray)))
	{
		sensorsArray[i].printMe(mystream);
		mystream << ",";
		++i;
	}
	mystream << endl;
}







