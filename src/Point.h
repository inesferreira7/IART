#ifndef SRC_POINT_H_
#define SRC_POINT_H_

class Point{
	double x,y;
public:
	Point();
	Point(double x, double y);

	double getX() const;
	void setX(double x);

	double getY() const;
	void setY(double y);

	void operator=(const Point &p1){
		this->x = p1.getX();
		this->y = p1.getY();
	}
};



#endif
