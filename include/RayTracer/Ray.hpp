#ifndef __RAY_HPP__
#define __RAY_HPP__

#include "Vector3.hpp"

struct Ray {
    Vector3<float> origin;
    Vector3<float> direction;
};

#endif // __RAY_HPP__
