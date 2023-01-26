#include "ellipse.h"

#include <cmath>

namespace Exercise {

Ellipse::Ellipse(double rx, double ry)
    : m_radii { rx, ry }
{

}

Point Ellipse::At(double t) const noexcept
{
    return {
        m_radii[0] * std::cos(t),
        m_radii[1] * std::sin(t),
        0
    };
}

std::vector<double> Ellipse::Radii() const
{
    return { m_radii[0], m_radii[1] };
}

}
