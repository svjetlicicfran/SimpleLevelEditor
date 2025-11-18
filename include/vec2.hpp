#pragma once
#include <raylib.h>

class Vec2 : public Vector2 {
public:
    Vec2(float x = 0, float y = 0) : Vector2{x, y} {}
    Vec2(const Vector2& v) : Vector2{v} {}
    //operator Vector2() const { return Vector2{this->x, this->y}; }

    Vec2 operator+(const Vec2& rhs) const { return Vec2{x + rhs.x, y + rhs.y}; }
    Vec2 operator-(const Vec2& rhs) const { return Vec2{x - rhs.x, y - rhs.y}; }
    Vec2 operator*(float s) const { return Vec2{x * s, y * s}; }
    Vec2 operator/(float s) const { return Vec2{x / s, y / s}; }
    Vec2& operator+=(const Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
    Vec2& operator-=(const Vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
    Vec2& operator*=(float s) { x *= s; y *= s; return *this; }
    Vec2& operator/=(float s) { x /= s; y /= s; return *this; }
};
