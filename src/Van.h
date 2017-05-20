#ifndef SRC_VAN_H_
#define SRC_VAN_H_

#include <iostream>
#include "Reservation.h"
#include <vector>

using namespace std;

class Van{
private:
	string lPlate;
	int nPassengers;
	vector <vector<Reservation> > reservations;
	vector<Date> dates;
	vector<vector<string> > trips;
public:
	Van();
	Van(string lPlate, int nPassengers);
	string getLPlate() const;
	void setLPlate(const string& lPlate);
	int getPassengers() const;
	void setPassengers(int nPassengers);
	const vector<Date> & getD() const ;
	void setD(const vector<Date>& d);
	const vector<vector<Reservation> >& getReservations() const;
	void setReservations(const vector<vector<Reservation> >& reservations);
	bool operator ==(const Van &v2){
			if(lPlate == v2.getLPlate())
				return true;
			return false;
		}
	void addDate(Date &d);
	void addReservations(vector<Reservation> r);
	void setSortedTrips(vector<string> trip);
	vector<vector<string> > getTrips() const;
};


#endif
