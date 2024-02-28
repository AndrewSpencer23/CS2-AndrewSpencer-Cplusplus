#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    this->nearestPoint = closestPoint;
    this->x = X;
    this->y = Y;
}
//Destructor
points::Point::~Point()
{
    delete[] this;
}

//Getters
int points::Point::getX()
{
    return this->x;
}

int points::Point::getY()
{
    return this->y;
}

points::Point* points::Point::getNearestPoint()
{
    return this->nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    for(unsigned long i = 0; i < arrSize; i++) {
        if(this->nearestPoint->distPoints(*nearestPoint) >= pointList[i]->distPoints(*pointList[i])) {
            this->nearestPoint = pointList[i];
            return pointList[i];
            continue;
        }
    }
    return this->nearestPoint;
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
    *this = point;
    double distance;
    distance = sqrt((pow((nearestPoint->getX() - point.getX()), 2)) + (pow((nearestPoint->getY() - point.getY()), 2)));
    return distance;
}