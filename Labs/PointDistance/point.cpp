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
        if(this->getX() >= pointList[i]->getX()) {
            cout << "DEBUG" << pointList[i]->x;
            pointList[i] = this;
            pointList[i]->x = this->x;
            pointList[i]->y = this->y;
        }
    }
    return this;
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
    nearestPoint->x = newNearestPoint->x;
    nearestPoint->y = newNearestPoint->y;
}

double points::Point::distPoints(Point& point)
{   
    *this = point;
    this->x = point.x;
    this->y = point.y;
    double distance;
    distance = sqrt((pow((nearestPoint->x - point.x), 2)) + (pow((nearestPoint->y - point.y), 2)));
    return distance;
}