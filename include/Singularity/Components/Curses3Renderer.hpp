#ifndef _SINGULARITY_CURSES3_RENDERER
#define _SINGULARITY_CURSES3_RENDERER

#include <string>
#include <unordered_map>
#include <Singularity/Behavior.hpp>
#include <Singularity/Geometry/Vector3.hpp>

using Singularity::Geometry::Vector3;

namespace Singularity
{
  class Curses3Renderer : public Behavior
  {
    static std::unordered_map<size_t, Curses3Renderer *> drawables;

    void OnDisable()
    {
      Curses3Renderer::drawables.erase(GetInstanceId());
    }
    void OnEnable()
    {
      Curses3Renderer::drawables[GetInstanceId()] = this;
    }

  public:
    Curses3Renderer() { OnEnable(); }
    ~Curses3Renderer() { OnDisable(); }

    std::vector<Vector3> vertices;

    static std::unordered_map<size_t, Curses3Renderer *> const& GetDrawables() { return drawables; }
  };

  std::unordered_map<size_t, Curses3Renderer *> Curses3Renderer::drawables;
}

#endif
