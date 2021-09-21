#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <cstdint>

struct Color {
    float red;
    float green;
    float blue;

    Color& operator+=(const Color& rhs);

    Color& operator*=(const Color& rhs);
    Color& operator*=(float intensity);
};

Color operator+(const Color& lhs, const Color& rhs);

Color operator*(const Color& lhs, const Color& rhs);
Color operator*(const Color& lhs, float rhs);

uint32_t ColorToRGB888(const Color& color);
Color    RGB888ToColor(uint32_t     color);

#endif // __COLOR__HPP__
