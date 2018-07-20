#include <ncurses.h>
#include <string>
#include <Singularity/Components/CursesRenderer.hpp>
#include <Singularity/Entity.hpp>
#include <Singularity/Geometry/Transform.hpp>
#include <Singularity/Graphics/Curses.hpp>

namespace Singularity::Graphics
{
  Curses::Curses()
  {
    window = initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_BLUE, COLOR_BLACK);
    cbreak();
    noecho();
    nonl();
    intrflush(window, false);
    keypad(window, true);
    curs_set(false);
    getmaxyx(window, height, width);
  }
  Curses::~Curses()
  {
    endwin();
  }

  void Curses::Draw()
  {
    for(auto kv : CursesRenderer::GetDrawables())
    {
      CursesRenderer *drawable = kv.second;
      if(!drawable->IsEnabled()) { continue; }
      Geometry::Vector3 position = drawable->entity->transform->position;
      attron(COLOR_PAIR(drawable->color));
      mvwaddstr(window, position.y, position.x, drawable->text.c_str());
      attroff(COLOR_PAIR(drawable->color));
    }

    wrefresh(window);

    for(auto kv : CursesRenderer::GetDrawables())
    {
      CursesRenderer *drawable = kv.second;
      if(!drawable->IsEnabled()) { continue; }
      Geometry::Vector3 position = drawable->entity->transform->position;
      std::string emptyStr(drawable->text.size(), ' ');
      mvwaddstr(window, position.y, position.x, emptyStr.c_str());
    }
  }
}
