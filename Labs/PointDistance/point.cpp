#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    closestPoint = this;
}
//Destructor
points::Point::~Point()
{
    delete this;
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
    return nullptr;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    return nullptr;
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

}

double points::Point::distPoints(Point& point)
{
    return 0.0;
}