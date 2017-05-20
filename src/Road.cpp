#include "Road.h"

/**
 * Constructor of class Road
 */
Road:: Road(){};

/**
 * Constructor of the class Road
 * @param road_id
 * @param road_name
 * @param is_two_way
 */
Road:: Road(int road_id, string road_name, bool is_two_way) : road_id(road_id),
road_name(road_name), is_two_way(is_two_way), is_obstructed(false){};

/**
 * Checks if Road is two way
 */
bool Road:: isIsTwoWay() const {
	return is_two_way;
}

/**
 * Modifies Road's two way
 * @param isTwoWay new isTwoWay
 */
void Road:: setIsTwoWay(bool isTwoWay) {
	is_two_way = isTwoWay;
}

/**
 * Returns road id
 */
int Road:: getRoadId() const {
	return road_id;
}

/**
 * Modifies road id
 * @param roadId new road_id
 */
void Road:: setRoadId(int roadId) {
	road_id = roadId;
}

/**
 * Checks if road is obstructed
 */
bool Road:: getObstructed() const{ return this->is_obstructed;}
/**
 * Modifies road obstruction
 * @param isObstructed new road obstruction
 */
void Road:: setObstructed(bool isObstructed) {this->is_obstructed = isObstructed;}

/**
 * Returns road name
 */
const string& Road:: getRoadName() const {
	return road_name;
}

/**
 * Modifies road name
 * @param roadName new roadName
 */
void Road:: setRoadName(const string& roadName) {
	road_name = roadName;
}
