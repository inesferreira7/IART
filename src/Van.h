#ifndef VAN_H_
#define VAN_H_

#include "Reservation.h"
#include "Graph.h"
#include "Road.h"
#include "Node.h"
#include "ReadFiles.h"
#include <vector>

class Van{
	int capacity;
	int plate;
	int ocupation;
	bool isFull;
	vector<Reservation> res;
public:
	Van(int capacity);

	int getCapacity() const;

	int getPlate() const;

	int getOcupation() const;

	void incOcupation();

	void resetOcupation();

	vector<Reservation> getRes() const;

	void addRes(Reservation res);

	bool is_Full() const;

	void getPath(Graph<Node, Road> &g, GraphViewer *gv) const;
};

#endif
