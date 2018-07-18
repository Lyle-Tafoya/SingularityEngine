#include <Singularity/Behavior.hpp>

namespace Singularity
{
  std::unordered_map<size_t, Behavior *> Behavior::behaviors;
  std::vector<Behavior *> Behavior::pendingBehaviors;

  void Behavior::UpdateAll()
  {
    for(size_t i=0; i < pendingBehaviors.size(); ++i)
    {
      Behavior *behavior = pendingBehaviors[i];
      if(!behavior->IsEnabled()) { continue; }
      behaviors[behavior->GetInstanceId()] = behavior;
      pendingBehaviors.erase(pendingBehaviors.begin() + i--);
      behavior->Start();
    }

    for(auto kv : behaviors)
    {
      Behavior *behavior = kv.second;
      if(!behavior->IsEnabled()) { continue; }
      behavior->Update();
    }
    for(auto kv : behaviors)
    {
      Behavior *behavior = kv.second;
      if(!behavior->IsEnabled()) { continue; }
      behavior->LateUpdate();
    }
  }

  Behavior::~Behavior()
  {
    behaviors.erase(GetInstanceId());
  }

  Behavior::Behavior() : enabled(false)
  {
    pendingBehaviors.push_back(this);
  }

  void Behavior::Disable()
  {
    enabled = false;
    OnDisable();
  }

  void Behavior::Enable()
  {
    enabled = true;
    OnEnable();
  }
}
