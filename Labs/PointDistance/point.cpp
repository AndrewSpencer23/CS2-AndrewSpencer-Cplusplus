#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    nearestPoint = closestPoint;
    x = X;
    x = Y;
}
//Destructor
points::Point::~Point()
{
    delete[] nearestPoint;
}

//Getters
int points::Point::getX()
{
    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    for(unsigned long i = 0; i < arrSize; i++) {
        if(this->nearestPoint->distPoints(*nearestPoint) >= pointList[i]->distPoints(*pointList[i])) {
            pointList[i] = getNearestPoint();
            return pointList[i];
        }
    }
    return getNearestPoint();
}

//Setters
void points::Point::setX(int newVal)
{
    this->x = newVal;
}

void points::Point::setY(int newVal)
{
    this->y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    this->nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{   
    point = *getNearestPoint();
    point.x = getX();
    point.y = getY();
    double distance;
    distance = sqrt((pow((this->nearestPoint->x - point.x), 2)) + (pow((this->nearestPoint->y - point.y), 2)));
    return distance;
}