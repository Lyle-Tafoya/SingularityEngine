#include <Singularity/Entity.hpp>
#include <Singularity/Geometry/Transform.hpp>

namespace Singularity
{
  Entity::Entity(std::string const& name) : Object(name)
  {
    transform = &AddComponent<Geometry::Transform>();
  }

  Entity::~Entity()
  {
    for(auto kv : components)
    {
      Component *component = kv.second;
      component->entity = nullptr;
      Object::Destroy(component);
    }
    Object::Destroy(transform);
  }
}
