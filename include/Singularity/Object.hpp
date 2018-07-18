#ifndef _SINGULARITY_OBJECT_HPP
#define _SINGULARITY_OBJECT_HPP

#include <string>
#include <unordered_set>

namespace Singularity
{
  class Object
  {
    size_t instanceId;

    static size_t count;
    static std::unordered_set<Object *> destroyQueue;

  public:
    /// Generate an Object with a given name
    Object(std::string const& name="");

    virtual ~Object() = default;

    /// Return the instanceId of this Object. Each object is guaranteed to have a unique instanceId
    inline size_t GetInstanceId() const { return instanceId; }

    /// The name of this object
    std::string name;

    /// Queue an object to be deleted
    static void Destroy(Object *object);

    /// Cleanup and delete objects in delete queue
    static void ProcessDestroyQueue();
  };
}

#endif
