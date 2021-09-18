#include <algorithm>
#include <cstdint>

#include "Color.hpp"

Color& Color::operator+=(const Color& rhs) {
    red   = std::min(red   + rhs.red,   1.0f);
    green = std::min(green + rhs.green, 1.0f);
    blue  = std::min(blue  + rhs.blue,  1.0f);

    return *this;    
}

Color& Color::operator*=(const Color& rhs) {
    red   *= rhs.red;
    green *= rhs.green;
    blue  *= rhs.blue;

    return *this;
}

Color& Color::operator*=(float intensity) {
    intensity = std::min(intensity, 1.0f);
    
    red   *= intensity;
    green *= intensity;
    blue  *= intensity;

    return *this;
}

Color operator+(const Color& lhs, const Color& rhs) {
    Color result(lhs);
    result += rhs;
    return result;    
}

Color operator*(const Color& lhs, const Color& rhs) {
    Color result(lhs);
    result *= rhs;
    return result;
}

Color operator*(const Color& lhs, float rhs) {
    Color result(lhs);
    result *= rhs;
    return result;
}

uint32_t ColorToRGB888(const Color& color) {    
    return ((uint32_t)(color.red   * 255.f) << 16ul) +
           ((uint32_t)(color.green * 255.f) <<  8ul) +
           ((uint32_t)(color.blue  * 255.f)      );
}

Color RGB888ToColor(uint32_t color) {
    Color result{0.0, 0.0, 0.0};
    
    result.red   = (float)(color >> 16ul) / 255.f;
    result.green = (float)(color >>  8ul) / 255.f;
    result.blue  = (float)(color        ) / 255.f;

    return result;
}
