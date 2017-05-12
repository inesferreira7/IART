#include "Van.h"

static int plate = 0;

/**
 * Van constructor
 */
Van::Van(int capacity){
	this->capacity = capacity;
	this->plate = plate++;
	this->ocupation = 0;
	this->isFull = false;
}

int Van::getCapacity() const {
	return capacity;
}

int Van::getPlate() const {
	return plate;
}

int Van::getOcupation() const {
	return ocupation;
}

void Van::incOcupation(){
	ocupation++;
}

void Van::resetOcupation(){
	this->ocupation = 0;
}

vector<Reservation> Van::getRes() const{
	return res;
}

void Van::addRes(Reservation res){
	this->res.push_back(res);
	if (getRes().size() == capacity){
		isFull = true;
	}
}

bool Van::is_Full() const{
	return isFull;
}

void Van::getPath(Graph<Node, Road> &g, GraphViewer *gv) const{
	Node n1 = g.getVertexSet().at(0)->getInfo();
	g.dijkstraShortestPath(n1);
	vector <Node> dest;
	vector<string> hotels = getLocals();

	for (int i = 0; i < res.size(); i++){
		dest.push_back(findNode(g, res.at(i).getLocal()));
	}

	Node orig = n1;
	Node destin(0,0,0,0,0);

	vector<Vertex<Node, Road> > path;
	cout << hotels.at(0) << endl;

	while(!dest.empty()){
		int minDist = 1000000;
		int j;
		for (int i = 0; i< dest.size(); i++){
			if (minDist >= g.getVertex(dest.at(i))->getDist()){
				minDist = g.getVertex(dest.at(i))->getDist();
				destin = dest.at(i);
				j = i;
			}
		}
		for (int k = 1; k<g.getPath(orig, destin).size(); k++){
			path.push_back(g.getPath(orig, destin).at(k));
		}
		orig = destin;
		g.dijkstraShortestPath(dest.at(j));
		dest.erase(dest.begin()+ j);
	}
	for (int p = 0; p < g.getVertex(n1)->getAdj().size(); p++){
		if (g.getVertex(path.at(0).getInfo())->getInfo().getId() == g.getVertex(n1)->getAdj().at(p).getDest().getInfo().getId()){
			cout <<  g.getVertex(n1)->getAdj().at(p).getInfo().getName() << endl;
			gv->setEdgeColor(g.getVertex(n1)->getAdj().at(p).getInfo().getID(), "green");
			break;
		}
	}

	for (int l = 0; l < path.size() -1 ; l++){
		if(path.at(l).getInfo().getId() >0 && path.at(l).getInfo().getId() < 9){
			bool found = false;
			for (int v = 0; v < res.size(); v++){
				if(res.at(v).getLocal() == path.at(l).getInfo().getId())
					found = true;
			}
			if (found){
				cout << hotels.at(path.at(l).getInfo().getId() - 1) << endl;
				gv->setVertexIcon(path.at(l).getInfo().getId(),"hotel_visit.png");
			}
		}
		for (int p = 0; p < g.getVertex(path.at(l).getInfo())->getAdj().size(); p++){
			if (g.getVertex(path.at(l+1).getInfo())->getInfo().getId() == g.getVertex(path.at(l).getInfo())->getAdj().at(p).getDest().getInfo().getId()){
				cout <<  g.getVertex(path.at(l).getInfo())->getAdj().at(p).getInfo().getName() << endl;
				gv->setEdgeColor(g.getVertex(path.at(l).getInfo())->getAdj().at(p).getInfo().getID(), "green");
				break;
			}
		}
	}

	cout << hotels.at(path.at(path.size() - 1).getInfo().getId() - 1) << endl;
	gv->setVertexIcon(path.at(path.size() - 1).getInfo().getId(),"hotel_visit.png");
	gv->rearrange();

}
