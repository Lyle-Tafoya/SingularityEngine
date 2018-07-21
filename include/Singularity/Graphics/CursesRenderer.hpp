#ifndef SINGULARITY_CURSES_RENDERER_
#define SINGULARITY_CURSES_RENDERER_

#include <string>
#include <unordered_map>
#include <Singularity/Component.hpp>

namespace Singularity
{
  class CursesRenderer : public Component
  {
    static std::unordered_map<size_t, CursesRenderer *> drawables;

  public:
    /// Generate a CursesRenderer Component
    CursesRenderer() { CursesRenderer::drawables[GetInstanceId()] = this; }

    ~CursesRenderer() override { CursesRenderer::drawables.erase(GetInstanceId()); }

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
