#ifndef SRC_ROAD_H_
#define SRC_ROAD_H_

#include <string>

using namespace std;

class Road{
	int road_id;
	string road_name;
	bool is_two_way;
	bool is_obstructed;
public:
	Road();
	Road(int road_id, string road_name, bool is_two_way);

	bool isIsTwoWay() const;
	void setIsTwoWay(bool isTwoWay);

	int getRoadId() const;
	void setRoadId(int roadId);

	const string& getRoadName() const;
	void setRoadName(const string& roadName);

	bool getObstructed() const;
	void setObstructed(bool isObstructed);
};

#endif
