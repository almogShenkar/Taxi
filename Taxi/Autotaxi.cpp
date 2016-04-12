#include "Autotaxi.h"


Autotaxi::~Autotaxi(){
	cout << "Dtor Autotaxi" << endl;
	t1->~Taxi();
}


Autotaxi::Autotaxi(char*Fbirt, char*Fcommand, char*Fresult){
	cout << "Ctor Autotaxi" << endl;
	ifstream Fbirth(Fbirt);
	ifstream Fcommands(Fcommand);
	ofstream Fresults(Fresult);
	if (!Fbirth || !Fcommands || !Fresults)
	{
		cout << "Error files" << endl;
		cerr << "Error files";
		exit(1);
	}
	int size = 0;
	char**Vals=readBirth(Fbirth,size);
	CreateTaxi(Vals,size);
	readRunCmnds(Fcommands);
	t1->printMe(Fresults);
	Fbirth.close();
	Fcommands.close();
	Fresults.close();
}



char** Autotaxi::readBirth(ifstream &Fbirth,int &size){
	int id, km, power, radius1, radius2, radius3, radius4, thick1, thick2, thick3, thick4;
	double Eversion, Bversion;
	char**Values;
	char **ValuesTemp;
	Values = new char*[14];
	char*c;
	for (int i = 0; i < 14; ++i)
		Values[i] = new char[200];
	int j = 0;
	char line[200];
	while (Fbirth.getline(line, 200))
	{		
		if (line[0] == '#') continue;
		c = strtok(line, ",");		
		while (c)
		{
			if (j >= 13)					//if there are some sensors dynamiclly allocate each 1 at time
			{
				ValuesTemp = new char*[j + 1];
				for (int k = 0; k < j + 1; k++)
				{
					ValuesTemp[k] = new char[200];
					if (k<j)
						strcpy(ValuesTemp[k], Values[k]);
				}
				delete[]Values;
				Values = ValuesTemp;
			}
			strcpy(Values[j], c);
			c = strtok(NULL, ",");
			j++;
		}
	}
	size = j;
	return Values;
}


void Autotaxi::CreateTaxi(char**Values, int size)
{

	int id = atoi(Values[0]);
	int km = 0;
	char* Estatus = Values[1];
	int power = atoi(Values[2]);
	double Eversion = atof(Values[3]);
	int wheels[8];
	for (int k = 0; k < 8; k++)
		wheels[k] = atoi(Values[4 + k]);
	double Bversion = atof(Values[12]);
	int i = 0;
	char **sensors = new char*[sizeof(size - 12)];
	while (i <sizeof(size - 13))
	{
		sensors[i] = Values[i+13];
		++i;
	}
	t1=new Taxi(id,Estatus,power,Eversion,wheels,Bversion,sensors);
}


void runCmnd(Taxi *t1,int cmndNo, int cmndVal = 0){

		  cmndNo == 1 ? t1->goAhead(cmndVal)
		: cmndNo == 2 ? t1->goBack(cmndVal)
		: cmndNo == 3 ? t1->turnLeft(cmndVal)
		: cmndNo == 4 ? t1->turnRight(cmndVal)
		: cmndNo == 5 ? t1->pickPassenger()
		: cmndNo == 6 ? t1->dropPassenger()
		: 0;

};


void Autotaxi::readRunCmnds(ifstream &Fcommands){
	char line[200];
	char *cmndNo,*cmndVal;
	while (Fcommands.getline(line, 200))
	{
		if (line[0] == '#') continue;
		cmndNo = strtok(line, ",");
		cmndVal = strtok(NULL, ",");
		if (!cmndNo) strcat(cmndVal, line);
		if (cmndNo && cmndVal)
			runCmnd(t1,atoi(cmndNo), atoi(cmndVal));
		else
			if (cmndNo)
				runCmnd(t1,atoi(cmndNo));
	}
};


Autotaxi ::Autotaxi (){
	ifstream Fbirth("birth.txt");
	int size;
	char**vals;
	vals=readBirth(Fbirth, size);
	CreateTaxi(vals, size);
	cout << "enter command,value #=stop" << endl;
	system("cls");
	cout << "================================================================================" << endl;
	cout << endl << endl << "What would you like to do?" << endl << endl;
	cout << "1) Go forward" << endl;
	cout << "2) Go backward" << endl;
	cout << "3) Turn right" << endl;
	cout << "4) Turn left" << endl;
	cout << "5) Pick passenger" << endl;
	cout << "6) Drop passenger" << endl;
	cout << "================================================================================" << endl << endl;
	cout << "Please Select An Option" << endl;
	int cmndNo,cmndVal;
	cin >> cmndNo;
	system("cls");
	if (cmndNo == 5 || cmndNo == 6)
	{
		if (cmndNo == 5)t1->pickPassenger();
		if (cmndNo == 6)t1->dropPassenger();
	}
	else
	{
		cout << "================================================================================" << endl;
		cout << "Enter value: " << endl;
		cout << "================================================================================" << endl << endl;
		cin >> cmndVal;
		switch (cmndNo)
		{
		case 1:{t1->goAhead(cmndVal); break; }
		case 2:{t1->goBack(cmndVal); break; }
		case 3:{t1->turnRight(cmndVal); break; }				
		case 4:{t1->turnLeft(cmndVal); break; }					
		}
	}
	cout << "================================================================================" << endl << endl;
	t1->printMe();
	cout << "================================================================================" << endl << endl;
	Fbirth.close();
}



