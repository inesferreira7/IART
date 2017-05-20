#include "FileReader.h"
#include "graphviewer.h"

#define NODES 			"nodes.txt"
#define ROADS 			"roads.txt"
#define SUBROADS 		"subroads.txt"
#define RESERVATIONS 	"Reservations.txt"
#define VANS 			"Vans.txt"

Graph<Node,Road> g;
GraphViewer *gv;

/**Loads file data to graph and initializes GraphViewer pointer
 * @param g graph being load
 */
void loadGraph(Graph<Node,Road> &g){

	gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineEdgeDashed(false);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	readNodes(g);
	vector<Road> roads = readRoads();
	readSubRoads(g,roads);

	gv->rearrange();
}
/**Finds a node with a certain ID in a graph
 * @param g graph being searched
 * @param node_id ID of node
 */
Node findNode(Graph<Node,Road> & g, int node_id){
	for(int i = 0; i < g.getNumVertex(); i++){
		if(node_id == g.getVertexSet()[i]->getInfo().getNodeId())
			return g.getVertexSet()[i]->getInfo();
	}
	return Node(-1,Point(0,0),Point(0,0), "");
}
/**Finds a Road in a vector of Roads by it's ID
 * @param r vector of Roads
 * @param road_id ID of the road being searched
 */
Road findRoad(vector<Road> r, int road_id){
	for(unsigned int i = 0; i < r.size(); i++){
		if(road_id == r[i].getRoadId()) return r[i];
	}
	return Road(-1,"",false);
}

/**Reads all nodes from file and loads them to the graph
 * @param g graph to load the nodes
 */
void readNodes(Graph<Node,Road> & g){
	ifstream infile;
	string line;
	infile.open(NODES);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		unsigned int node_id;
		double x, y, x_r, y_r;
		string nome = "";

		linestream >> node_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> x;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> y;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> x_r;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> y_r;
		getline(linestream, data, ';');
		linestream >> nome;

		Node n(node_id, Point(x,y), Point(x_r,y_r), nome);

		g.addVertex(n);
		gv->addNode(node_id,x,y);
		gv->setVertexLabel(node_id,n.getHotelName());
		if(nome != ""){
			gv->setVertexIcon(node_id,"hotel.png");
		}
		if(node_id == 1){
			gv->setVertexIcon(node_id,"aero.png");
		}
	}

	infile.close();
}

/**Reads all roads from file
 */
vector<Road> readRoads(){
	ifstream infile;
	vector<Road> roads;
	string line;
	int road_id;
	string road_name, is_two_way;
	infile.open(ROADS);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> road_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> road_name;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> is_two_way;

		if(is_two_way == "False") roads.push_back(Road(road_id,road_name,false));
		else roads.push_back(Road(road_id,road_name,true));
	}

	infile.close();
	return roads;
}

/**Reads all subroads from file
 * @param g graph to load the subroads
 * @param roads vector of Roads
 */
void readSubRoads(Graph<Node,Road> &g, vector<Road> roads){
	ifstream infile;
	string line;
	int road_id, node1_id, node2_id;
	infile.open(SUBROADS);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> road_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> node1_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> node2_id;

		Node node_1 = findNode(g,node1_id);
		Node node_2 = findNode(g,node2_id);
		Point d1 = node_1.getPointDegree();
		Point d2 = node_2.getPointDegree();

		double distance = sqrt(pow((d1.getX() - d2.getX()),2) + pow((d1.getY() - d2.getY()),2));

		Road r = findRoad(roads, road_id);

		if(r.isIsTwoWay()){
			g.addEdge(node_1,node_2,r,distance);
			g.addEdge(node_2,node_1,r,distance);
			gv->addEdge(road_id,node1_id,node2_id,EdgeType::UNDIRECTED);
		}else{
			g.addEdge(node_1,node_2,r,distance);
			gv->addEdge(road_id,node1_id,node2_id,EdgeType::UNDIRECTED);
		}

	}

	infile.close();
}

/**Reads all reservations from a file and loads them to the airShuttle
 *
 */
void readReservations(AirShuttle &airShuttle){
	ifstream infile;
	string line;
	infile.open(RESERVATIONS);
	int id,Hour, Min, Day;
	string name, destination,nif;
	vector <Reservation> res;

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> id;
		getline(linestream, data, ';');
		getline(linestream, name, ';');
		getline(linestream, nif, ';');
		linestream >> Hour;
		getline(linestream, data, ';');
		linestream >> Min;
		getline(linestream, destination, ';');
		linestream >> destination;

		Passenger p= Passenger(name,nif);
		Date d= Date(Hour, Min);
		Reservation r= Reservation(id,d,p,destination);
		res.push_back(r);
	}

	sort(res.begin(),res.end());
	airShuttle.setReservations(res);
	infile.close();
}
/**Reads all vans from a file and loads them to the airShuttle
 *
 */
void readVans(AirShuttle &airShuttle){
	ifstream infile;
	string line;
	infile.open(VANS);

	while(getline(infile,line)){
		stringstream linestream(line);
		stringstream linestream2(line);
		string data;
		string lp;
		int cap;

		getline(linestream, lp, ';');  // read up-to the first ; (discard ;).
		getline(linestream2, data, ';');
		linestream2 >> cap;

		Van v= Van(lp,cap);
		airShuttle.addVan(v);
	}
	infile.close();
}
