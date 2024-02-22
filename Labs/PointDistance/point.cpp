#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    closestPoint = this;
    closestPoint->x = X;
    closestPoint->y = Y;
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
    nearestPoint = nullptr;
    return nullptr;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    for(int i = 0; i < arrSize; i++) {
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
    newNearestPoint = nullptr;
}

double points::Point::distPoints(Point& point)
{
    double distance;
    *this = point;
    distance = sqrt((pow((nearestPoint->x - point.getX()), 2)) + (pow((nearestPoint->y - point.getY()), 2)));
    return distance;
}