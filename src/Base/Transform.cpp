#include <Singularity/Geometry/Transform.hpp>

namespace Singularity::Geometry
{
  void Transform::Rotate(Vector3 const &eulerAngles)
  {
    Quaternion rotationB = Quaternion::Euler(eulerAngles.x, eulerAngles.y, eulerAngles.z);
    rotation = rotation * rotationB;
  }
}
