#include <Singularity/Entity.hpp>

namespace Singularity
{
  Entity::Entity(std::string const& name) : transform(new Transform)
  {
    this->name = name;
  }

  Entity::~Entity()
  {
    for(auto kv : components)
    {
      Component *component = kv.second;
      component->entity = nullptr;
      Object::Destroy(component);
    }
    delete transform;
  }

  void Entity::AddComponent(Component *component)
  {
    component->entity = this;
    components[component->GetInstanceId()] = component;
  }
}
