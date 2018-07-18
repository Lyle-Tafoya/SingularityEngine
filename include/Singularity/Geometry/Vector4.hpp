#ifndef _SINGULARITY_VECTOR4_HPP
#define _SINGULARITY_VECTOR4_HPP

#include <Singularity/Geometry/Vector2.hpp>
#include <Singularity/Geometry/Vector3.hpp>

namespace Singularity::Geometry
{
  class Vector2;
  class Vector3;

  /// Representation of a 4-dimensional point/vector
  class Vector4
  {
  public:
    /// Position on the x-axis
    float x;

    /// Position on the y-axis
    float y;

    /// Position on the z-axis
    float z;

    /// Position on the w-axis
    float w;

    /// Generate a 4-dimensional vector given x,y,z,w coordinates
    Vector4(float x=0, float y=0, float z=0, float w=0) : x(x), y(y), z(z), w(w) {};

    /// Calculate the x,y,z,w values of a vector with a magnitude of 1
    void Normalize();

    /// Set the x,y,z,w coordinates of this vector
    void Set(float x, float y, float z, float w);

    /// Add 2 vectors
    Vector4 operator+(Vector4 const &v) const;

    void operator+=(Vector4 const &v);

    /// Subract 2 vectors
    Vector4 operator-(Vector4 const &v) const;

    void operator-=(Vector4 const &v);

    /// Multiply 2 vectors
    Vector4 operator*(float number) const;

    void operator*=(float number);

    /// Divide 2 vectors
    Vector4 operator/(float number) const;

    void operator/=(float number);

    /// Convert a Vector 2 to a Vector4
    void operator=(Vector2 const &v2);

    /// Convert a Vector 3 to a Vector4
    void operator=(Vector3 const &v3);

    /// Determine whether 2 vectors are approximately equal
    bool operator==(Vector4 const &v) const;

    /// One on every axis - Vector(1, 1, 1, 1)
    static inline Vector4 One() { return Vector4(1,1,1,1); }

    /// Zero on every axis - Vector(0, 0, 0, 0)
    static inline Vector4 Zero() { return Vector4(0,0,0,0); }

    /// Distance between pointA and pointB
    static float Distance(Vector4 const& pointA, Vector4 const& pointB);
  };
}

#endif
