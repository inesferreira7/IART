#include "Reservation.h"

/**
 * Reservation constructor
 */
Reservation::Reservation(string clientName, Date arrivalDate, int local){
	this->clientName = clientName;
	this->arrivalDate = arrivalDate;
	this->local = local;
}

string Reservation::getClientName() const{
	return clientName;
}

Date Reservation::getArrivalDate() const{
	return arrivalDate;
}

int Reservation::getLocal() const{
	return local;
}

bool Reservation::operator <(const Reservation r1) const{
	return arrivalDate < r1.getArrivalDate();
}
