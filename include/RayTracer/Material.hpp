#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include "Color.hpp"

struct Material {
    Color ambient_color;

    Color diffuse_color;
    
    Color specular_color;
    float specular;
};

#endif // __MATERIAL_HPP__
