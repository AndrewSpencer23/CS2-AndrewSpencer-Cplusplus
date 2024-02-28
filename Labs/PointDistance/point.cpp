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
        if(pointList[i]->x <= pointList[i+1]->x && pointList[i]->y <= pointList[i+1]->y) {
            pointList[i] = nearestPoint;
            continue;
        }
    }
    return nearestPoint;
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
    this->getNearestPoint() = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    double distance;
    point = *getNearestPoint();
    point.x = getX();
    point.y = getY();
    
    distance = sqrt((pow((nearestPoint->x - point.x), 2)) + (pow((nearestPoint->y - point.y), 2)));
    return distance;
}