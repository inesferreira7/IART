#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <iostream>

class Date{
private:
	int hour;
	int minutes;
public:
	Date();
	Date(int hour, int minutes);
	int getHour() const;
	void setHour(int hour);
	int getMinutes() const;
	void setMinutes(int minutes);
	friend bool operator ==(const Date &d1, const Date &d2){
		if ((d1.getHour() == d2.getHour()) && (d1.getMinutes() == d2.getMinutes()))
			return true;
		return false;
	}
	bool operator <(const Date &d2) const{
		if((hour != d2.getHour() )&& (minutes != d2.getMinutes()))
			return false;
		return true;
	}
};




#endif
