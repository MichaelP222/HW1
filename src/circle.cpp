// implement circle.cpp functions here.
#include "../include/circle.h"
#include <iostream>
#include <numbers>

using namespace std;

double radius(double x1, double y1, double x2, double y2) {
    double d;
    d = sqrt(pow((x2-x1), 2)+pow((y2-y1), 2));
    return d;
}

double circumference(double rad) {
    double cir = 2 * rad * M_PI;
    return cir;
}

double area(double rad) {
    double area1 = M_PI * pow(rad, 2);
    return area1;
}