#ifndef _SINGULARITY_CURSES_HPP
#define _SINGULARITY_CURSES_HPP

#include <ncurses.h>

namespace Singularity::Graphics
{
  /// A managed ncurses instance
  class Curses
  {
    WINDOW *window;
    int width;
    int height;

  public:
    /// Create a Curses object to manage an ncurses instance
    Curses();

    ~Curses();

    /// Retrieve the width of our draw area
    inline int GetWidth() { return width; }

    /// Retrieve the height of our draw area
    inline int GetHeight() { return height; }

    /// Refresh/update the terminal
    void Draw();
  };
}

#endif
