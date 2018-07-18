#ifndef SINGULARITY_QUATERNION_HPP_
#define SINGULARITY_QUATERNION_HPP_

#include <Singularity/Geometry/Vector3.hpp>

namespace Singularity::Geometry
{
  /// Objects of this type are used to represent rotational data in 3 spacial dimensions.
  class Quaternion
  {
  public:
    /// Rotation around the vector defined by x,y,z coordinates
    float w;

    /// x-coordinate of orientation vector
    float x;

    /// y-coordinate of orientation vector
    float y;

    /// z-coordinate of orientation vector
    float z;

    /// Generate a Quaternion with given x,y,z,w coordinates
    Quaternion(float x=0, float y=0, float z=0, float w=1) : w(w), x(x), y(y), z(z) {}

    /// Convert this Quaternion to one with the same orientation and a magnitude of 1
    void Normalize();

    /// Returns this Quaternion with a magnitude of 1
    Quaternion Normalized() const;

    /// Set the x,y,z,w values of this Quaternion
    void Set(float x, float y, float z, float w);

    /// Multiply 2 Quaternions
    Quaternion operator*(Quaternion const &q) const;

    /// Multiply a Quaternion and a Vector3
    Vector3 operator*(Vector3 const &v) const;

    /// Generate a Quaternion from a Euler angle represented in degrees
    static Quaternion Euler(float x, float y, float z);

    /// Generate a Quaternion from a Euler angle represented as a Vector3 in degrees
    static Quaternion Euler(Vector3 const &eulerAngles);

    /// Generate a Quaternion from a Euler angle represented in radians
    static Quaternion EulerRadians(float x, float y, float z);

    /// Quaternion with vector magnitude of zero - Quaternion(0,0,0,1)
    static inline Quaternion Identity() { return Quaternion(0,0,0,1); }
  };
}

#endif
