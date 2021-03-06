#ifndef SINGULARITY_TRANSFORM_HPP_
#define SINGULARITY_TRANSFORM_HPP_

#include <Singularity/Component.hpp>
#include <Singularity/Geometry/Quaternion.hpp>
#include <Singularity/Geometry/Vector3.hpp>

namespace Singularity::Geometry
{
  /// Used to store and manipulate position, rotation, and scale of an Entity.
  class Transform : public Component
  {
  public:
    /// The parent of this Transform
    Transform *parent;

    /// The position of this Transform
    Vector3 position;

    /// The scale of this Transform
    Vector3 scale;

    /// The rotation of this transform
    Quaternion rotation;

    /// Rotate a Vector3 given Euler angle values
    void Rotate(Vector3 const &eulerAngles);
  };
}

#endif
