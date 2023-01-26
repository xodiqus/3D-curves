#ifndef CURVE_H
#define CURVE_H

#include <vector>

#include "point.h"

namespace Exercise {

class Curve
{
public:
    virtual ~Curve() {}
    Curve() noexcept {}

    virtual std::vector<double> Radii() const = 0;

    virtual Point At(double t) const noexcept = 0;

    // If there is no override implementation then it computes with the numerical method.
    virtual Point Derivative(double t) const noexcept;
};

}

#endif // CURVE_H
