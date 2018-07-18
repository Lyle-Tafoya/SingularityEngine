#ifndef _SINGULARITY_CURSES3_HPP
#define _SINGULARITY_CURSES3_HPP

#include <ncurses.h>
#include <Singularity/Geometry/Transform.hpp>
#include <Singularity/Geometry/Vector3.hpp>
using namespace Singularity::Geometry;

namespace Singularity::Graphics
{
  /// A managed ncurses instance for rendering 3D graphics
  class Curses3
  {
    WINDOW *window;
    int width;
    int height;
    Transform camera;
    Transform viewport;
    float viewDistance;

    void InitializeColors();
    float frameTiming[60];
    size_t frame;

  public:
    /// Create a Curses object to manage an ncurses instance
    Curses3();

    ~Curses3();

    /// Retrieve the width of our draw area
    inline int GetWidth() { return width; }

    /// Retrieve the height of our draw area
    inline int GetHeight() { return height; }

    /// Refresh/update the terminal
    void Draw();

    /// Calculate average framerate
    int Framerate();

    static bool RayTriangleIntersect(Vector3 const &origin, Vector3 const &direction, Vector3 const &v1, Vector3 const &v2, Vector3 const &v3, float &distance, float &u, float &v);
  };
}

#endif
