// driver code to test circle.cpp manually.
#include <iostream>
#include "../include/circle.h"
using namespace std;

int main() {

    double x1, y1, x2, y2;
	cout << "please enter location of first point.\n" << "x:" ;
	cin >> x1;
	cout << "y:";
	cin >> y1;
	cout << "please enter location of second point.\n" << "x:" ;
	cin >> x2;
	cout << "y:";
	cin >> y2;
	cout << " the radius between (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is equal to: " << radius(x1, y1, x2, y2) << endl;
	cout << " the circumference of the circle defined by (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is equal to: " << circumference(radius(x1, y1, x2, y2)) << endl;
	cout << " the area of the circle defined by (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is equal to: " << area(radius(x1, y1, x2, y2)) << " = 13" << endl;

    return 0;
}