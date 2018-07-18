#include <cmath>
#include <Singularity/Geometry/Quaternion.hpp>

namespace Singularity::Geometry
{
#define RADIAN 0.0174533f
  void Quaternion::Normalize()
  {
    float magnitude = sqrt(x*x + y*y + z*z + w*w);
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
  }

  Quaternion Quaternion::Euler(float x, float y, float z)
  {
    return EulerRadians(x*RADIAN, y*RADIAN, z*RADIAN);
  }

  Quaternion Quaternion::Euler(Vector3 const& eulerAngles)
  {
    return EulerRadians(eulerAngles.x*RADIAN, eulerAngles.y*RADIAN, eulerAngles.z*RADIAN);
  }

  Quaternion Quaternion::EulerRadians(float x, float y, float z)
  {
    float cy = cos(z/2);
    float sy = sin(z/2);
    float cr = cos(x/2);
    float sr = sin(x/2);
    float cp = cos(y/2);
    float sp = sin(y/2);

    return Quaternion(cy*sr*cp - sy*cr*sp, cy*cr*sp + sy*sr*cp, sy*cr*cp - cy*sr*sp, cy*cr*cp + sy*sr*sp);
  }

  Quaternion Quaternion::Normalized() const
  {
    float magnitude = sqrt(x*x + y*y + z*z + w*w);
    return Quaternion(x/magnitude, y/magnitude, z/magnitude, w/magnitude);
  }

  void Quaternion::Set(float x, float y, float z, float w)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
  }

  Quaternion Quaternion::operator*(Quaternion const &q) const
  {
    return Quaternion(w*q.x+x*q.w+y*q.z-z*q.y, w*q.y+y*q.w+z*q.x-x*q.z, w*q.z+z*q.w+x*q.y-y*q.x, w*q.w-x*q.x-y*q.y-z*q.z);
  }

  Vector3 Quaternion::operator*(Vector3 const &v) const
  {
    Vector3 direction = Vector3(x,y,z);
    return Vector3::Cross(direction, Vector3::Cross(direction, v) + v*w) * 2 + v;
  }
}
