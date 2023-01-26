#include "helix.h"

#include <cmath>

namespace Exercise {

Helix::Helix(double radius)
    : m_radius(radius)
{

}

Point Helix::At(double t) const noexcept
{
    return {
        m_radius * std::cos(t),
        m_radius * std::sin(t),
        t
    };
}

std::vector<double> Helix::Radii() const
{
    return { m_radius };
}

}
