#include "Node.h"

using namespace std;

/**
 * Node constructor
 */
Node::Node(unsigned long ID, double lat_deg, double lon_deg, double lat_rad, double lon_rad){
	this->ID = ID;
	this->lat_deg = lat_deg;
	this->lon_deg = lon_deg;
	this->lat_rad = lat_rad;
	this->lon_rad = lon_rad;
}

unsigned long Node::getId() const {
	return ID;
}

double Node::getLatDeg() const {
	return lat_deg;
}

double Node::getLatRad() const {
	return lat_rad;
}

double Node::getLonDeg() const {
	return lon_deg;
}

double Node::getLonRad() const {
	return lon_rad;
}

bool Node::operator ==(const Node &n1) const{
	return (ID == n1.getId());
}

bool Node::operator !=(const Node &n1) const{
	return (ID != n1.getId());
}
