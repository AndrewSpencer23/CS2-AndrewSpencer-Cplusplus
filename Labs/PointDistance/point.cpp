#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    X = closestPoint->x;
    Y = closestPoint->y;
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
    int xGet = 0;
    this->x = xGet;
    return xGet;
}

int points::Point::getY()
{
    int yGet = 0;
    this->x = yGet;
    return yGet;
}

points::Point* points::Point::getNearestPoint()
{
    nearestPoint = nullptr;
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
    newNearestPoint = nullptr;
}

double points::Point::distPoints(Point& point)
{
    return 0.0;
}