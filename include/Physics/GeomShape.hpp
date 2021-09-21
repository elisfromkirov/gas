#ifndef __GEOM_SHAPES_HPP__
#define __GEOM_SHAPES_HPP__

#include "Vector3.hpp"

struct BoxGeom {
    Vector3<float> center;
    Vector3<float> size;
};

struct SphereGeom {
    Vector3<float> center;
    float          radius;
};

#endif // __GEOM_SHAPES_HPP__
