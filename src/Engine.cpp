#include <Singularity/Behavior.hpp>
#include <Singularity/Engine.hpp>
#include <Singularity/Entity.hpp>

namespace Singularity
{
  float Engine::deltaTime;
  std::chrono::high_resolution_clock::time_point Engine::lastUpdate = std::chrono::high_resolution_clock::now();

  void Engine::UpdateDeltaTime()
  {
    std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float>(currentTime-lastUpdate).count();
    lastUpdate = currentTime;
  }

  void Engine::Run()
  {
    while(true)
    {
      UpdateDeltaTime();
      Behavior::UpdateAll();
      Entity::ProcessDestroyQueue();
      Behavior::ProcessDestroyQueue();
    }
  }

}
