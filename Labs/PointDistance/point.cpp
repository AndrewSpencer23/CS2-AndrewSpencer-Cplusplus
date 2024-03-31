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
    float smallestDistance;
    smallestDistance = 1e9;

    Point* closestPoint;

    for(unsigned long i = 0; i < arrSize; i++) {
        double distance = distPoints(*pointList[i]);
        if (distance < smallestDistance) {
            smallestDistance = distance;
            closestPoint = pointList[i];
        }
    }

    return closestPoint;
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