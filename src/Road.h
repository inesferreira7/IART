#ifndef ROAD_H_
#define  ROAD_H_

#include <string>

using namespace std;

class Road{
	unsigned long ID;
	string name;
	bool two_way;
	bool acessible;
public:
	Road(unsigned long ID, string name, bool two_way);
	unsigned long getID() const;
	bool is_two_way() const;
	string getName() const;
	void block();
	bool getState() const;
	bool operator ==(const Road r1) const;
};


#endif
