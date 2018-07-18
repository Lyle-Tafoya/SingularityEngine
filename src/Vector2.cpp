#include <cmath>
#include <Singularity/Geometry/Vector2.hpp>

namespace Singularity::Geometry
{
  Vector2 Vector2::operator+(Vector2 const &v) const
  {
    return Vector2(x + v.x, y + v.y);
  }
  void Vector2::operator+=(Vector2 const &v)
  {
    x += v.x;
    y += v.y;
  }
  Vector2 Vector2::operator-(Vector2 const &v) const
  {
    return Vector2(x - v.x, y - v.y);
  }
  void Vector2::operator-=(Vector2 const &v)
  {
    x -= v.x;
    y -= v.y;
  }
  Vector2 Vector2::operator*(float number) const
  {
    return Vector2(x * number, y * number);
  }
  void Vector2::operator*=(float number)
  {
    x *= number;
    y *= number;
  }
  Vector2 Vector2::operator/(float number) const
  {
    return Vector2(x / number, y / number);
  }
  void Vector2::operator/=(float number)
  {
    x /= number;
    y /= number;
  }
  void Vector2::operator=(Vector3 const &v3)
  {
    x = v3.x;
    y = v3.y;
  }
  void Vector2::operator=(Vector4 const &v4)
  {
    x = v4.x;
    y = v4.y;
  }
  bool Vector2::operator==(Vector2 const &v) const
  {
    return Vector2::Distance(*this, v) < std::numeric_limits<float>::epsilon();
  }

  void Vector2::Set(float x, float y)
  {
    this->x = x;
    this->y = y;
  }

  float Vector2::Distance(Vector2 const& pointA, Vector2 const& pointB)
  {
    Vector2 difference = pointA - pointB;
    return sqrt(difference.x*difference.x + difference.y*difference.y);
  }

  void Vector2::Normalize()
  {
    float length = sqrt(x*x + y*y);
    *this /= length;
  }
}
