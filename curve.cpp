#include "curve.h"

namespace Exercise {

Point Curve::Derivative(double t) const noexcept
{
    constexpr auto h = 0.000000000001;
    return (At(t + h) - At(t)) / h;
}

}
