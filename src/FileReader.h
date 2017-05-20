#ifndef SRC_FILEREADER_H_
#define SRC_FILEREADER_H_

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>


#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "Subroad.h"
#include "Point.h"
#include "AirShuttle.h"

using namespace std;

void loadGraph(Graph<Node,Road> & g);
Node findNode(Graph<Node,Road> & g, int node_id);
Road findRoad(vector<Road> r, int road_id);
void readNodes(Graph<Node,Road> & g);
vector<Road> readRoads();
void readSubRoads(Graph<Node,Road> &g, vector<Road> roads);
void readReservations(AirShuttle &airShuttle);
void readVans(AirShuttle &airShuttle);

#endif
