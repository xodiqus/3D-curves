#include "circle.h"

#include <cmath>

namespace Exercise {

Circle::Circle(double r)
    : m_radius(r)
{

}

Point Circle::At(double t) const noexcept
{
    return {
        m_radius * std::cos(t),
        m_radius * std::sin(t),
        0
    };
}

Point Circle::Derivative(double t) const noexcept
{
    return {
        m_radius * -std::sin(t),
        m_radius *  std::cos(t),
        0
    };
}

std::vector<double> Circle::Radii() const
{
    return { m_radius };
}

}
