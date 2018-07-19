#ifndef SINGULARITY_ENTITY_HPP_
#define SINGULARITY_ENTITY_HPP_

#include <string>
#include <vector>
#include <unordered_map>
#include <Singularity/Component.hpp>
#include <Singularity/Object.hpp>
#include <Singularity/Geometry/Transform.hpp>

namespace Singularity
{
  class Component;

  /// An object of this type does nothing on it's own, but can have behavior added via Component objects
  class Entity : public Object
  {
    std::unordered_map<size_t, Component *> components;

  public:
    /// The Transform attached to this Entity
    Geometry::Transform *transform;

    /// Create a new Entity with a given name
    Entity(std::string const& name="");

    ~Entity() override;

    /// Add a Component to this Entity
    void AddComponent(Component *component);

    /// Return a Component attached to this entity of type ComponentType
    template<class ComponentType> ComponentType * GetComponent()
    {
      for(auto kv : components)
      {
        Component *component = kv.second;
        if(ComponentType *c = dynamic_cast<ComponentType *>(component))
        {
          return c;
        }
      }
      return nullptr;
    }

    /// Return a std::vector of Components attached to this entity of type ComponentType
    template<class ComponentType> std::vector<ComponentType *> GetComponents()
    {
      std::vector<ComponentType *> results;
      for(auto kv : components)
      {
        Component *component = kv.second;
        if(ComponentType *c = dynamic_cast<ComponentType *>(component))
        {
          results.push_back(c);
        }
      }
      return results;
    }

    friend class Component;
  };
}

#endif
