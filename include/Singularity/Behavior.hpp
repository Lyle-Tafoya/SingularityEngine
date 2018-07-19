#ifndef SINGULARITY_BEHAVIOR_HPP_
#define SINGULARITY_BEHAVIOR_HPP_

#include <unordered_map>
#include <vector>
#include <Singularity/Component.hpp>

namespace Singularity
{
  /// A type of component which can be disabled/enabled
  class Behavior : public Component
  {
    static std::unordered_map<size_t, Behavior *> behaviors;
    static std::vector<Behavior *> pendingBehaviors;

    static void Destroy(Behavior *behavior);

    bool enabled;

    virtual void LateUpdate() {};
    virtual void OnEnable() {};
    virtual void OnDisable() {};
    virtual void OnDestroy() {};
    virtual void Start() {};
    virtual void Update() {};

  public:
    Behavior();

    ~Behavior() override;

    /// Disable this Behavior
    void Disable();

    /// Enable this Behavior
    void Enable();

    /// Determine whether this Behavior is enabled
    inline bool IsEnabled() { return enabled; }

    /// Update all enabled Behavior objects
    static void UpdateAll();
  };
}

#endif
