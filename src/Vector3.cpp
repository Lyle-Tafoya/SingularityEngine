#include <algorithm>
#include <cmath>
#include <limits>
#include <Singularity/Geometry/Vector3.hpp>

namespace Singularity::Geometry
{
  Vector3 Vector3::operator+(Vector3 const &v) const
  {
    return Vector3(x + v.x, y + v.y, z + v.z);
  }
  void Vector3::operator+=(Vector3 const &v)
  {
    x += v.x;
    y += v.y;
    z += v.z;
  }
  Vector3 Vector3::operator-(Vector3 const &v) const
  {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }
  void Vector3::operator-=(Vector3 const &v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;
  }
  Vector3 Vector3::operator*(float number) const
  {
    return Vector3(x * number, y * number, z * number);
  }
  void Vector3::operator*=(float number)
  {
    x *= number;
    y *= number;
    z *= number;
  }
  Vector3 Vector3::operator/(float number) const
  {
    return Vector3(x / number, y / number, z / number);
  }
  void Vector3::operator/=(float number)
  {
    x /= number;
    y /= number;
    z /= number;
  }
  void Vector3::operator=(Vector2 const &v2)
  {
    x = v2.x;
    y = v2.y;
    z = 0;
  }
  void Vector3::operator=(Vector4 const &v4)
  {
    x = v4.x;
    y = v4.y;
    z = v4.z;
  }
  bool Vector3::operator==(Vector3 const &v) const
  {
    return fabs(Vector3::Distance(*this, v)) < std::numeric_limits<float>::epsilon();
  }

  Vector3 Vector3::Cross(Vector3 const &v1, Vector3 const &v2)
  {
    return Vector3(v1.y*v2.z-v2.y*v1.z, -(v1.x*v2.z-v2.x*v1.z), v1.x*v2.y-v2.x*v1.y);
  }

  float Vector3::Distance(Vector3 const &pointA, Vector3 const &pointB)
  {
    return (pointB-pointA).Magnitude();
  }

  float Vector3::Dot(Vector3 const &v1, Vector3 const &v2)
  {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
  }

  Vector3 Vector3::LerpUnclamped(Vector3 const &v1, Vector3 const &v2, float t)
  {
    return v1 + (v2-v1)*t;
  }

  Vector3 Vector3::Lerp(Vector3 const &v1, Vector3 const &v2, float t)
  {
    t = std::clamp<float>(t, 0.f, 1.f);
    return v1 + (v2-v1)*t;
  }

  float Vector3::Magnitude() const
  {
    return sqrt(x*x + y*y + z*z);
  }

  void Vector3::Normalize()
  {
    *this /= Magnitude();
  }

  Vector3 Vector3::Normalized() const
  {
    return *this / Magnitude();
  }

  void Vector3::Set(float x, float y, float z)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }
}
