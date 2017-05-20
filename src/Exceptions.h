#ifndef SRC_EXCEPTIONS_H_
#define SRC_EXCEPTIONS_H_

#include "Reservation.h"

class DuplicateReservationException{
	Reservation reservation;
public:
	DuplicateReservationException(Reservation r){reservation=r;}
	Reservation getDuplicateReservation(){return reservation;}
};

class InexistentReservationException{
	int id;
public:
	InexistentReservationException(int id){this->id= id ;}
	int getInexistentReservationId(){return id;}
};

class DuplicateVanException{
	Van van;
public:
	DuplicateVanException(Van v){ van= v;}
	Van getDuplicateVan(){ return van;}
};

class InexistentVanException{
	Van van;
public:
	InexistentVanException(Van v){ van= v;}
	Van getInexistentVan(){ return van;}
};

class InexistentPassengerException{
};

#endif /* SRC_EXCEPTIONS_H_ */
