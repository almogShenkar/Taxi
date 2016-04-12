#include "Autotaxi.h"



int main(){	
	int select;
	do
	{
		system("cls");
		cout << "================================================================================" << endl;
		cout << "Welcome to Autotaxi!" << endl << endl << endl;
		cout << "1) Run autotically from file" << endl;
		cout << "2) Insert command" << endl;
		cout << "0) Exit" << endl;
		cout << "================================================================================" << endl << endl;
		cout << "Please Select An Option" << endl;
		cin >> select;
		cout << "input";
		
		if (select == 1)
			Autotaxi t1("birth.txt","simulation.txt","results.txt");
		if (select == 2)
			Autotaxi();
		system("pause");
	}
	while (select != 0);
}