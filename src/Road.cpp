#include "Road.h"

/**
 * Road constructor
 */
Road::Road(unsigned long ID, string name, bool two_way){
	this->ID = ID;
	this->name = name;
	this->two_way = two_way;
	this->acessible = true;
}

unsigned long Road::getID() const{
	return ID;
}

string Road::getName() const{
	return name;
}
void Road::block(){
	this->acessible = false;
}

bool Road::getState() const{
	return acessible;
}

bool Road::is_two_way() const{
	return two_way;
}

bool Road::operator ==(const Road r1) const{
	return ID == r1.getID();
}
