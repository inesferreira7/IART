#ifndef SRC_RESERVATION_H_
#define SRC_RESERVATION_H_

#include <iostream>
#include "Date.h"
#include "Passenger.h"

using namespace std;

class Reservation{
private:
	int id;
	Date date;
	Passenger passenger;
	string destination;
public:
	Reservation();
	Reservation(int id, Date date, Passenger passenger, string destination);
	const Date& getArrival() const;
	void setArrival(const Date& arrival);
	const Date& getDate()const;
	void setDate(Date date);
	string getDestination() const;
	void setDestination(const string& destination);
	const Passenger& getPassenger() const;
	void setPassenger(const Passenger& passenger);
	int getPrice() const;
	void setPrice(int price);
	int getId() const;
	bool operator ==(const Reservation &r2){
		if(id == r2.getId())
			return true;
		return false;
	}
	bool operator < (const Reservation &r2)const{
		if(date < r2.getDate()) return true;
		return false;
	}
};

#endif
