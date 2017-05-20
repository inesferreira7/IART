#include "Date.h"

using namespace std;

/**Construtor of class Date
 *
 */
Date:: Date(){}
/**Construtor of class Date
 * @param hour
 * @param minutes
 */
Date:: Date( int hour, int minutes){

	this-> hour= hour;
	this->minutes=minutes;
}
/**Returns the hour
 *
 */
int Date:: getHour() const {
	return hour;
}
/**Modifies the hour
 * @param hour new hour
 */
void Date:: setHour(int hour) {
	this->hour = hour;
}
/**Returns the minutes
 *
 */
int Date:: getMinutes() const {
	return minutes;
}
/**Modifies the minutes
 * @param minutes new minutes
 */
void Date:: setMinutes(int minutes) {
	this->minutes = minutes;
}
