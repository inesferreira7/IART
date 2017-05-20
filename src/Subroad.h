#ifndef SRC_SUBROAD_H_
#define SRC_SUBROAD_H_

using namespace std;

class Subroad{
	int road_id;
	int node1_id;
	int node2_id;
public:
	Subroad(int road_id, int node1_id, int node2_id);

	int getNode1Id() const;
	void setNode1Id(int node1Id);

	int getNode2Id() const;
	void setNode2Id(int node2Id);

	int getRoadId() const;
	void setRoadId(int roadId);
};




#endif
