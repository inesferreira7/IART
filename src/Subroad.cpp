#include "Subroad.h"

Subroad:: Subroad(int road_id, int node1_id, int node2_id) : road_id(road_id), node1_id(node1_id), node2_id(node2_id){};

int Subroad:: getNode1Id() const {
	return node1_id;
}

void Subroad:: setNode1Id(int node1Id) {
	node1_id = node1Id;
}

int Subroad:: getNode2Id() const {
	return node2_id;
}

void Subroad:: setNode2Id(int node2Id) {
	node2_id = node2Id;
}

int Subroad:: getRoadId() const {
	return road_id;
}

void Subroad:: setRoadId(int roadId) {
	road_id = roadId;
}
