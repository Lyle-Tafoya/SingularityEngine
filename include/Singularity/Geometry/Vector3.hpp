#ifndef _SINGULARITY_VECTOR3_HPP
#define _SINGULARITY_VECTOR3_HPP

#include <cmath>
#include <Singularity/Geometry/Vector2.hpp>
#include <Singularity/Geometry/Vector4.hpp>

namespace Singularity::Geometry
{
  class Vector2;
  class Vector4;

  /// Representation of a 3-dimensional point/vector
  class Vector3
  {
  public:
    /// Position on the x-axis
    float x;

    /// Position on the y-axis
    float y;

    /// Position on the z-axis
    float z;

    /// Generate a 3-dimensional vector given x,y,z coordinates
    Vector3(float x=0, float y=0, float z=0) : x(x), y(y), z(z) {}

    /// Determine the distance between 0,0,0 and x,y,z
    float Magnitude() const;

    /// Set the magnitude of this vector to 1
    void Normalize();

    /// Return this vector with a magnitude of 1
    Vector3 Normalized() const;

    /// Set the x,y,z coordinates of this vector
    void Set(float x, float y, float z);

    Vector3 operator+(Vector3 const &v) const;

    void operator+=(Vector3 const &v);

    Vector3 operator-(Vector3 const &v) const;

    void operator-=(Vector3 const &v);

    Vector3 operator*(float number) const;

    void operator*=(float number);

    Vector3 operator/(float number) const;

    void operator/=(float number);

    /// Convert a Vector2 to a Vector3
    void operator=(Vector2 const &v2);

    /// Convert a Vector4 to a Vector3
    void operator=(Vector4 const &v4);

    /// Check if 2 vectors are approximately equal to each other
    bool operator==(Vector3 const &v) const;

    /// Backwards on the z-axis - Vector3(0, 0, -1)
    static inline Vector3 Back() { return Vector3(0,0,-1); }

    /// Cross product of 2 vectors
    static Vector3 Cross(Vector3 const &v1, Vector3 const &v2);

    /// Dot product of 2 vectors
    static float Dot(Vector3 const &v1, Vector3 const &v2);

    /// Distance between pointA and pointB
    static float Distance(Vector3 const &pointA, Vector3 const &pointB);

    /// Backwards on the y-axis - Vector3(0, -1, 0)
    static inline Vector3 Down() { return Vector3(0,-1,0); }

    /// Forwards on the z-axis - Vector3(0, 0, 1)
    static inline Vector3 Forward() { return Vector3(0,0,1); }

    /// Forwards on the x-axis - Vector3(1, 0, 0)
    static inline Vector3 Left() { return Vector3(-1,0,0); }

    static Vector3 Lerp(Vector3 const &v1, Vector3 const &v2, float t);

    /// Interpolate between 2 vectors
    static Vector3 LerpUnclamped(Vector3 const &v1, Vector3 const &v2, float t);

    /// One on every axis - Vector(1, 1, 1)
    static inline Vector3 One() { return Vector3(1,1,1); }

    /// Backwards on the x-axis - Vector3(-1, 0, 0)
    static inline Vector3 Right() { return Vector3(1,0,0); }

    /// Up on the y-axis - Vector3(0, 1, 0)
    static inline Vector3 Up() { return Vector3(0,1,0); }

    /// Zero on every axis - Vector(0, 0, 0)
    static inline Vector3 Zero() { return Vector3(0,0,0); }
  };
}

#endif
