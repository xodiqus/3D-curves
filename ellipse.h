#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"
#include <array>

namespace Exercise {

class Ellipse : public Curve
{
    std::array<double, 2> m_radii;

public:
    Ellipse(double radius_x = 0, double radius_y = 0);

    Point At(double t) const noexcept override;

    std::vector<double> Radii() const override;
};

}

#endif // ELLIPSE_H
