#ifndef SINGULARITY_ENGINE_HPP_
#define SINGULARITY_ENGINE_HPP_

#include <chrono>

namespace Singularity
{
  /// Manages the main loop and time-related functionality
  class Engine
  {
    static float deltaTime;
    static std::chrono::high_resolution_clock::time_point lastUpdate;

  public:
    /// Start the main loop
    void Run();

    /// Retrieve the last calculated deltaTime value
    static inline float GetDeltaTime() { return deltaTime; }

    /// Calculate the elapsed time since this method was last run
    static void UpdateDeltaTime();
  };
}

#endif
