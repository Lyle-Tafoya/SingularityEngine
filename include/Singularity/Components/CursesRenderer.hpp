#ifndef _SINGULARITY_CURSES_RENDERER
#define _SINGULARITY_CURSES_RENDERER

#include <string>
#include <unordered_map>
#include <Singularity/Behavior.hpp>

namespace Singularity
{
  class CursesRenderer : public Behavior
  {
    static std::unordered_map<size_t, CursesRenderer *> drawables;

    void OnDisable()
    {
      CursesRenderer::drawables.erase(GetInstanceId());
    }
    void OnEnable()
    {
      CursesRenderer::drawables[GetInstanceId()] = this;
    }

  public:
    /// Generate a CursesRenderer Component
    CursesRenderer() { OnEnable(); }

    ~CursesRenderer() { OnDisable(); }

    /// The text to render to the screen
    std::string text;

    /// The color_pair used to render this text to the screen
    int color;

    /// Obtain an std::unordered_map containing every enabled CursesRenderer Component
    static std::unordered_map<size_t, CursesRenderer *> const& GetDrawables() { return drawables; }
  };

  std::unordered_map<size_t, CursesRenderer *> CursesRenderer::drawables;
}

#endif
