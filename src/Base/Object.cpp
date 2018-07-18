#include <Singularity/Object.hpp>

namespace Singularity
{
  size_t Object::count = 0;
  std::unordered_set<Object *> Object::destroyQueue;

  void Object::Destroy(Object *object)
  {
    destroyQueue.insert(object);
  }

  void Object::ProcessDestroyQueue()
  {
    while(destroyQueue.size() > 0)
    {
      std::unordered_set<Object *> tmp = Object::destroyQueue;
      destroyQueue.clear();
      for(Object *object : tmp)
      {
        delete object;
      }
    }
  }

  Object::Object(std::string const& name) : name(name)
  {
    instanceId = Object::count++;
  }
}
