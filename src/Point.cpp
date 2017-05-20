#include "Point.h"

/**
 * Constructor of class Point
 */
Point:: Point() : x(0), y(0){};
/**
 * Constructor of class Point
 * @param x
 * @param y
 */
Point:: Point(double x, double y) : x(x), y(y){};

/**
 * Returns the x of the Point
 */
double Point:: getX() const { return x;}
/**
 * Modifies the x of the Point
 * @param x new x
 */
void Point:: setX(double x){ this->x = x;}

/**
 * Returns the y of the Point
 */
double Point:: getY() const { return y;}
/**
 * Modifies the y of the Point
 * @param y new y
 */
void Point:: setY(double y){ this->y = y;}
