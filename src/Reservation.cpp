#include "Reservation.h"

using namespace std;
/**Construtor of class Reservation
 *
 */
Reservation:: Reservation(){}
/**Construtor of class Reservation
 * @param id Reservation's ID
 * @param date Date of reservation
 * @param passenger Passenger of reservations
 * @destination Passenger's destination
 */
Reservation:: Reservation(int id,Date date, Passenger passenger, string destination){
	this->id= id;
	this->date=date;
	this->passenger= passenger;
	this->destination=destination;
}
/**Returns the date of reservation
 *
 */
const Date& Reservation:: getDate()const {
	return date;
}
/**Modifies the date of reservation
 *
 */
void Reservation:: setDate(Date date) {
	this->date = date;
}
/**Return the destination
 *
 */
string Reservation:: getDestination() const {
	return destination;
}
/**Modifies the destination
 *
 */
void Reservation:: setDestination(const string& destinantion) {
	this->destination = destination;
}
/**Returns the passenger
 *
 */
const Passenger& Reservation:: getPassenger() const {
	return passenger;
}
/**Modifies the reservation passenger
 *
 */
void Reservation:: setPassenger(const Passenger& passenger) {
	this->passenger = passenger;
}
/**Returns the ID of the reservstion
 *
 */
int Reservation:: getId() const{
	return id;
}
