#include "Passenger.h"

using namespace std;
/**Construtor of class Passenger
 *
 */
Passenger:: Passenger(){}
/**Construtor of class Passenger
 * @param name passenger's name
 * @param nif passenger's NIF
 */
Passenger:: Passenger(string name, string nif){
	this->name=name;
	this->nif=nif;
}
/**Returns passenger's name
 *
 */
string Passenger:: getName() const {
	return name;
}
/**Modifies passenger's name
 *
 */
void Passenger:: setName(const string name) {
	this->name = name;
}
/**Returns passenger's NIF
 *
 */
string Passenger:: getNif() const {
	return nif;
}
/**Modifies passengers's NIF
 *
 */
void Passenger:: setNif(string nif) {
	this->nif = nif;
}
