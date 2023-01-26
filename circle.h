#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

namespace Exercise {

class Circle : public Curve
{
    double m_radius;

public:
    Circle(double radius = 0);

    std::vector<double> Radii() const override;

    Point At(double t) const noexcept override;

    Point Derivative(double t) const noexcept override;
};

}

#endif // CIRCLE_H
