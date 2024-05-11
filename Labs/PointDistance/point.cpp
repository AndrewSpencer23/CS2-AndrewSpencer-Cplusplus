#include "point.h"
#include <cmath>

// Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    setX(X);
    setY(Y);
    setNearestPoint(closestPoint);
}

// Destructor
points::Point::~Point()
{

}

// Getters
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
    float smallestDistance = 1e9;
    Point* closestPoint = nullptr;

    for(unsigned long i = 0; i < arrSize; i++) {
        if(distPoints(*pointList[i]) < smallestDistance) {
            smallestDistance = distPoints(*pointList[i]);
            closestPoint = pointList[i];
        }
    }
    return closestPoint;
}

// Setters
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
    distance = sqrt(pow(point.getX() - x, 2) + pow(point.getY() - y, 2));
    return distance;
}