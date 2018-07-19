#include <Singularity/Component.hpp>
#include <Singularity/Entity.hpp>

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
