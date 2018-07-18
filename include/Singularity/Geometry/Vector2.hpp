#ifndef SINGULARITY_VECTOR2_HPP_
#define SINGULARITY_VECTOR2_HPP_

#include <Singularity/Geometry/Vector3.hpp>
#include <Singularity/Geometry/Vector4.hpp>

namespace Singularity::Geometry
{
  class Vector3;
  class Vector4;

  /// Representation of a 2-dimensional point/vector
  class Vector2
  {
  public:
    /// Position on the x-axis
    float x;

    /// Position on the y-axis
    float y;

    /// Generate a 2-dimensional vector given x,y coordinates
    Vector2(float x=0, float y=0) : x(x), y(y) {};

    /// calculate the x,y,z values of a vector with a magnitude of 1
    void Normalize();

    /// Set the x,y coordinates of this vector
    void Set(float x, float y);

    /// Add 2 vectors
    Vector2 operator+(Vector2 const &v) const;

    void operator+=(Vector2 const &v);

    /// Subtract 2 vectors
    Vector2 operator-(Vector2 const &v) const;

    void operator-=(Vector2 const &v);

    /// Multiply 2 vectors
    Vector2 operator*(float number) const;

    void operator*=(float number);

    /// Divide 2 vectors
    Vector2 operator/(float number) const;

    void operator/=(float number);

    /// Convert a Vector3 to a Vector2
    void operator=(Vector3 const &v3);

    /// Convert a Vector4 to a Vector2
    void operator=(Vector4 const &v4);

    /// Determine whether 2 vectors are approximately equal
    bool operator==(Vector2 const &v) const;

    /// Backwards on the y-axis
    static inline Vector2 Down() { return Vector2(0,-1); }

    /// Backwards on the x-axis
    static inline Vector2 Left() { return Vector2(-1,0); }

    /// Forwards on the x-axis
    static inline Vector2 Right() { return Vector2(1,0); }

    /// Forwards on the y-axis
    static inline Vector2 Up() { return Vector2(0,1); }

    /// Distsance between pointA and pointB
    static float Distance(Vector2 const& pointA, Vector2 const& pointB);

  };
}

#endif
