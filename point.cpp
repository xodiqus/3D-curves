#include "point.h"

#include <ostream>

namespace Exercise {

Point::Point(double _x, double _y, double _z)
    : x(_x), y(_y), z(_z)
{

}

Point Point::operator- (Point p) const
{
    return {
        x - p.x,
        y - p.y,
        z - p.z
    };
}

Point Point::operator/ (double t) const
{
    return {
        x / t,
        y / t,
        z / t
    };
}

std::ostream &operator<<(std::ostream &out, Point p)
{
    return out << "(" << p.x << "," << p.y << "," << p.z << ")";
}

}
