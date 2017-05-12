#include "Transfer.h"

Transfer::Transfer() {
}

/**
 * Returns vector with all the reservations
 */
vector<Reservation> Transfer::getReservations() {
	return reservations;
}

/**
 * Returns vector with all the vans
 */
vector<Van> Transfer::getVans() {
	return vans;
}

/**
 * Adds a new reservation to the Transfer
 */
void Transfer::addReservation(Reservation r) {
	reservations.push_back(r);
}

/**
 * Adds a van to the Transfer
 */
void Transfer::addVan(Van v) {
	vans.push_back(v);
}

/**
 * Reads and loads the graph info
 */
/*void Transfer::loadGraph() {
	hotels = getHotels();

	gv = new GraphViewer(600, 600, false);
	gv->createWindow(700, 700);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");
	gv->defineEdgeCurved(false);

	readNodes(g, gv);
	readEdges(g, gv);

	for(unsigned int h=0; h<hotels.size(); h++){
		gv->setVertexLabel(h+1, hotels.at(h));
		if(h!=0){
			gv->setVertexIcon(h+1,"hotel.png");
		} else {
			gv->setVertexIcon(h+1,"airport.png");
		}
	}

	gv->rearrange();
}
*/
/**
 * Auxiliar function
 * Returns the ID of the nodes
 */
/*void Transfer::showNodeID() {
	for (unsigned int i = 0; i < g.getVertexSet().size(); i++) {
		if (g.getVertexSet().at(i)->getAdj().size() != 0)
			cout << g.getVertexSet().at(i)->getAdj().at(0).getWeight() << endl;
	}
}

/**
 * loads the reservations
 */
/*void Transfer::loadReservations() {
	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("reservas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::string line;

	unsigned long nif = 0;
	string name;
	string dateh;
	string datem;
	int dest;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;
		int hour, min;

		std::stringstream s(line);
		std::getline(linestream, name, ';'); // read up-to the first ; (discard ;).

		std::getline(s, data, ';');
		s >> nif;
		std::getline(linestream, data, ';');
		linestream >> hour;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> min;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> dest;

		Person p1(name, nif);
		Date d(hour, min);
		Reservation r(p1, d, dest);
		reservations.push_back(r);

	}

	sort(reservations.begin(), reservations.end());

	inFile.close();
}

/**
 * loads the vans
 */
/*void Transfer::loadVans() {
	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("vans.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	int cap;
	std::string line;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);

		linestream >> cap;

		Van v(cap);
		vans.push_back(v);
	}

	inFile.close();

	vector<Reservation> temp = reservations;
	unsigned int l = 0;
	while (!temp.empty() && l < vans.size()) {
		int i = 0;
		while (i < vans.at(l).getCapacity() && !temp.empty()) {
			int j = 0;
			for (unsigned int k = 0; k < vans.at(l).getRes().size(); k++) {
				if (exceedsTime(vans.at(l).getRes().at(k),
						temp.at(0))) {
					j++;
				}
			}
			if (j == 0) {
				vans.at(l).addRes(temp.at(0));
				temp.erase(temp.begin());
				i++;
			} else
				break;
		}
		l++;
	}
}

/**
 * Shows the passengers each van will transport and the time they will leave the airport
 */
/*void Transfer::transportClient() {

	//Date out = reservations.at(reservations.size() - 1).getArrivalDate();
	string clients;
	string reservation;
	vector<int> hotVisited;
	vector <string> hotels = getHotels();
	boolean write =true;
	for (unsigned int i = 0; i < this->vans.size(); i++) {
		if (vans.at(i).getRes().size() == 0)
			break;
		Date out = vans.at(i).getRes().at( vans.at(i).getRes().size() - 1).getArrivalDate();
		cout << endl << endl << "Carrinha " << vans.at(i).getId() << ": Hora de partida: " << out.getHour() << ":" << out.getMin() << "h" << endl;
		cout  << endl << "Clientes transportados:" << endl;
		stringstream ss;
		ss << vans.at(i).getId();
		clients += ss.str()+ "{";
		reservation += ss.str() + "{;";
		for (unsigned int j = 0; j < vans.at(i).getRes().size(); j++) {
			cout << endl << vans.at(i).getRes().at(j).getResponsible().getName() << "   ---------->   "  << hotels.at(vans.at(i).getRes().at(j).getDestination()-1);
			for(unsigned int x=0; x<hotVisited.size(); x++){
				if(hotVisited[x]==vans.at(i).getRes().at(j).getDestination()-1){
					write=false;
				}
			}
			if(write){
				hotVisited.push_back(vans.at(i).getRes().at(j).getDestination()-1);
				reservation += hotels.at(vans.at(i).getRes().at(j).getDestination()-1) + "; ";
			}
			clients += vans.at(i).getRes().at(j).getResponsible().getName() + "; ";
			write=true;

		}
		clients += "}";
		reservation.erase(reservation.length()-1);
		reservation += "}";
		hotVisited.clear();
	}
	cout << endl << endl << endl;
	//vans.at(0).getPath(g);

	ofstream myfile;

	myfile.open ("clients.txt");
	myfile << clients;
	myfile.close();

	myfile.open ("reservation.txt");
	myfile << reservation;
	myfile.close();

}

/**
 * Shows the path of each van
 */
/*void Transfer::showPath(){
	for (unsigned int i =0 ; i< vans.size(); i++){
		cout << "Percurso da carrinha " << vans.at(i).getId() << endl << endl;
		vans.at(i).getPath(g, gv);
		cout << endl << endl;
		getchar();
		for(unsigned int j=0;j<g.getVertexSet().size()*2; j++){
			gv->setEdgeColor(j+1, "blue");
		}
		for(unsigned int h=0; h<hotels.size(); h++){
			gv->setVertexLabel(h+1, hotels.at(h));
			if(h!=0){
				gv->setVertexIcon(h+1,"hotel.png");
			}
		}

		gv->rearrange();

	}
	cout << endl << endl;
}
