#ifndef SINGULARITY_CURSES3_RENDERER_
#define SINGULARITY_CURSES3_RENDERER_

#include <string>
#include <unordered_map>
#include <Singularity/Behavior.hpp>
#include <Singularity/Geometry/Vector3.hpp>

namespace Singularity
{
  class Curses3Renderer : public Behavior
  {
    static std::unordered_map<size_t, Curses3Renderer *> drawables;

    void OnDisable() override
    {
      Curses3Renderer::drawables.erase(GetInstanceId());
    }
    void OnEnable() override
    {
      Curses3Renderer::drawables[GetInstanceId()] = this;
    }

  public:
    Curses3Renderer() { OnEnable(); }
    ~Curses3Renderer() override { OnDisable(); }

    std::vector<Geometry::Vector3> vertices;

    static std::unordered_map<size_t, Curses3Renderer *> const& GetDrawables() { return drawables; }
  };

  std::unordered_map<size_t, Curses3Renderer *> Curses3Renderer::drawables;
}

#endif
