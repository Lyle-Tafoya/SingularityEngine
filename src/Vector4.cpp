#include <cmath>
#include <Singularity/Geometry/Vector4.hpp>

namespace Singularity::Geometry
{
  Vector4 Vector4::operator+(Vector4 const &v) const
  {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
  }
  void Vector4::operator+=(Vector4 const &v)
  {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
  }
  Vector4 Vector4::operator-(Vector4 const &v) const
  {
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
  }
  void Vector4::operator-=(Vector4 const &v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
  }
  Vector4 Vector4::operator*(float number) const
  {
    return Vector4(x * number, y * number, z * number, w * number);
  }
  void Vector4::operator*=(float number)
  {
    x *= number;
    y *= number;
    z *= number;
    w *= number;
  }
  Vector4 Vector4::operator/(float number) const
  {
    return Vector4(x / number, y / number, z / number, w / number);
  }
  void Vector4::operator/=(float number)
  {
    x /= number;
    y /= number;
    z /= number;
    w /= number;
  }
  void Vector4::operator=(Vector2 const &v2)
  {
    x = v2.x;
    y = v2.y;
    z = 0;
    w = 0;
  }
  void Vector4::operator=(Vector3 const &v3)
  {
    x = v3.x;
    y = v3.y;
    z = v3.z;
    w = 0;
  }
  bool Vector4::operator==(Vector4 const &v) const
  {
    return Vector4::Distance(*this, v) < std::numeric_limits<float>::epsilon();
  }

  void Vector4::Set(float x, float y, float z, float w)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
  }

  float Vector4::Distance(Vector4 const& pointA, Vector4 const& pointB)
  {
    Vector4 difference = pointA - pointB;
    return sqrt(difference.x*difference.x + difference.y*difference.y + difference.z*difference.z + difference.w*difference.w);
  }

  void Vector4::Normalize()
  {
    float length = sqrt(x*x + y*y + z*z + w*w);
    *this /= length;
  }
}
