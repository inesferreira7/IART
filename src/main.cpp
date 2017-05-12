#include "Transfer.h"
#include "readFiles.h"
//#include "matcher.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>


using namespace std;


int mainMenu(Transfer a1);

/**
 * Menu of the vans
 */
int VansMenu(Transfer a1){
	system("cls");

	cout << "List of Vans:" << endl;

	a1.transportClient();
	getchar();

	mainMenu(a1);
	return 0;
}

/**
 * Menu of the reservations
 */
int ReservationsMenu(Transfer a1){
	system("cls");
	vector<string> hotels = getLocals();

	cout << setw(8) << "Name" << setw(15) << "NIF" << setw(20) << "ArrivalDate" << setw(30) << "Destination" << endl << endl;


	for (int i = 0; i < a1.getReservations().size(); i++){
		cout << setw(10) << a1.getReservations().at(i).getClientName();
		cout << setw(12) << a1.getReservations().at(i).getArrivalDate().getHour() << ":" << a1.getReservations().at(i).getArrivalDate().getMin() <<
				"h";
		cout << setw(35) << hotels.at(a1.getReservations().at(i).getLocal() - 1) << endl;
	}

	getchar();
	mainMenu(a1);

	return 0;
}


double Cli_ExatSearch(Transfer a1){
	system("cls");
	string cli;
	cin.ignore(1000, '\n');

	cout << "Write the name of the desired client: ";
	getline(cin, cli);
	cout << endl;

	clock_t begin = clock();

	//numStringMatching("clients.txt", cli);

	clock_t end = clock();

	double elapsed_time = double(end-begin) / CLOCKS_PER_SEC;

	return elapsed_time;
}

double Cli_AproxSearch(Transfer a1){
	system("cls");
	string cli;
	cin.ignore(1000, '\n');

	cout << "Write the name of the  desired client: ";
	getline(cin, cli);
	cout << endl;
	string final = cli + ";";
	clock_t begin = clock();


	//numApproximateStringMatching("clients.txt", final);

	clock_t end = clock();

	double elapsed_time = double(end-begin) / CLOCKS_PER_SEC;


	return elapsed_time;
}

double Dest_ExatSearch(Transfer a1){
	system("cls");
	string dest;
	cin.ignore(1000, '\n');

	cout << "Write the name of the desired hotel: ";
	getline(cin, dest);
	cout << endl;

	string final = ";" + dest + ";";

	clock_t begin = clock();

	//numStringMatching("reservation.txt", final);

	clock_t end = clock();

	double elapsed_time = double(end-begin) / CLOCKS_PER_SEC;

	return elapsed_time;
}

double Dest_AproxSearch(Transfer a1){
	system("cls");
	string dest;
	cin.ignore(1000, '\n');

	cout << "Write the name of the desired hotel: ";
	getline(cin, dest);
	cout << endl;

	string final = ";" + dest + ";";

	clock_t begin = clock();

	//numApproximateStringMatching("reservation.txt", final);

	clock_t end = clock();

	double elapsed_time = double(end-begin) / CLOCKS_PER_SEC;

	return elapsed_time;
}

/**
 * Main menu
 */
int mainMenu(Transfer a1){

	int option;
	double res;

	cout << "#################" << endl;
	cout << "#               #" << endl;
	cout << "#  AIR SHUTTLE  #" << endl;
	cout << "#               #" << endl;
	cout << "#################" << endl;

	cout << endl << endl << "1 - Reservations" << endl;
	cout << "2 - Vans" << endl;
	cout << "3 - Transport passengers" << endl;
	cout << "4 - Pesquisa Cliente Exata" << endl;
	cout << "5 - Pesquisa Cliente Aproximada" << endl;
	cout << "6 - Pesquisa Destino Exata" << endl;
	cout << "7 - Pesquisa Destino Aproximada" << endl;
	cout << "8 - Exit" << endl;
	cin >> option;
	switch (option){
	case 1:
		ReservationsMenu(a1);
		break;
	case 2:
		VansMenu(a1);
		break;
	case 3:
		getchar();
		a1.showPath();
		mainMenu(a1);
		break;
	case 4:
		res = Cli_ExatSearch(a1);
		getchar();
		cout << endl << res << endl;
		mainMenu(a1);
		break;
	case 5:
		res = Cli_AproxSearch(a1);
		getchar();
		cout << endl << res << endl;
		mainMenu(a1);
		break;
	case 6:
		res = Dest_ExatSearch(a1);
		getchar();
		cout << endl << res << endl;
		mainMenu(a1);
		break;
	case 7:
		res = Dest_AproxSearch(a1);
		getchar();
		cout << endl << res << endl;
		mainMenu(a1);
		break;
	case 8:
		exit(0);
		break;
	}
}

int main(){
	Transfer a1;
	a1.loadGraph();

	a1.loadReservations();
	a1.loadVans();

	mainMenu(a1);


	return 0;
}
