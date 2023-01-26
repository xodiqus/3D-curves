#ifndef POINT_H
#define POINT_H

#include <ostream>

namespace Exercise {

struct Point {
    double x, y, z;

    Point(double x = 0, double y = 0, double z = 0);

    Point operator- (Point) const;

    Point operator/ (double v) const;
};

std::ostream& operator<< (std::ostream& out, Point p);

}

#endif // POINT_H
