#include <Singularity/Component.hpp>

namespace Singularity
{
  Component::~Component()
  {
    if(entity != nullptr)
    {
      entity->components.erase(GetInstanceId());
    }
  }
}
