#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

namespace Exercise {

class Helix : public Curve
{
    double m_radius;

public:
    Helix(double radius = 0);

    std::vector<double> Radii() const override;

    Point At(double t) const noexcept override;
};

}

#endif // HELIX_H
