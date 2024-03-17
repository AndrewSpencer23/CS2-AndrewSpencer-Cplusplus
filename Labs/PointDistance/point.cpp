#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    nearestPoint = closestPoint;
    x = X;
    y = Y;
}
//Destructor
points::Point::~Point()
{
    delete this;
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
        if (pointList[i]->distPoints(*pointList[i]) > pointList[i+1]->distPoints(*pointList[i+1])) {
            
        }
    }
    pointList[0] = nearestPoint;
    return nearestPoint;
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{   
    double distance;
    distance = sqrt((pow((point.getX() - this->getX()), 2)) + (pow((point.getX() - this->getY()), 2)));
    return distance;
}