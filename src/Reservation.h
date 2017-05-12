#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <string>
#include "Date.h"

using namespace std;

class Reservation{
	string clientName;
	Date arrivalDate;
	int local;

public:
	Reservation(string clientName, Date arrivalDate, int local);
	string getClientName() const;
	Date getArrivalDate() const;
	int getLocal() const;
	bool operator <(const Reservation r1) const;
};

#endif
