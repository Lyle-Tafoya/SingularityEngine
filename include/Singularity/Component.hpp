#ifndef SINGULARITY_COMPONENT_HPP_
#define SINGULARITY_COMPONENT_HPP_

#include <Singularity/Entity.hpp>
#include <Singularity/Object.hpp>

namespace Singularity
{
  class Entity;

  /// A component is something which provides functionality and/or data to an Entity
  class Component : public Object
  {
  public:
    virtual ~Component();

    /// The Entity this component is attached to.
    Entity *entity;
  };
}

#endif
