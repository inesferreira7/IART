#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include <string>
#include <iostream>

class Subroad;

class Node{
	unsigned long ID;
	double lat_deg;
	double lon_deg;
	double lat_rad;
	double lon_rad;

public:
	Node(unsigned long ID, double lat_deg, double lon_deg, double lat_rad, double lon_rad);
	unsigned long getId() const;
	double getLatDeg() const;
	double getLatRad() const;
	double getLonDeg() const;
	double getLonRad() const;
	bool operator ==(const Node &n1) const;
	bool operator !=(const Node &n1) const;

	friend class Edge;
};

#endif
