#include <limits>
#include <Singularity/Engine.hpp>
#include <Singularity/Components/Curses3Renderer.hpp>
#include <Singularity/Graphics/Curses3.hpp>

namespace Singularity::Graphics
{
  Curses3::Curses3() : frame(0)
  {
    window = initscr();
    InitializeColors();
    cbreak();
    noecho();
    nonl();
    intrflush(window, false);
    keypad(window, true);
    curs_set(false);
    getmaxyx(window, height, width);
    float aspectRatio = width/height;
    viewport.position.Set(0,0,0);
    viewport.scale.Set(aspectRatio, 1, 0);
    camera.position.Set(0, 0, 1);
    viewDistance = 50.f;
  }
  Curses3::~Curses3()
  {
    endwin();
  }

  void Curses3::InitializeColors()
  {
    start_color();
    assume_default_colors(COLOR_BLACK, COLOR_BLACK);
    for(int i = 1; i < COLORS; ++i)
    {
      init_pair(i, i, i);
    }
    init_pair(COLORS, COLOR_WHITE, COLOR_BLACK);
  }

  bool Curses3::RayTriangleIntersect(Vector3 const &origin, Vector3 const &direction, Vector3 const &v1, Vector3 const &v2, Vector3 const &v3, float &distance, float &u, float &v)
  {
    Vector3 v1v2 = v2 - v1;
    Vector3 v1v3 = v3 - v1;
    Vector3 pvec = Vector3::Cross(direction, v1v3);
    float det = Vector3::Dot(v1v2, pvec);

    //if(det < std::numeric_limits<float>::epsilon()) { return false; }

    if(fabs(det) < std::numeric_limits<float>::epsilon()) { return false; }
    float invDet = 1 / det;

    Vector3 tvec = origin - v1;
    u = Vector3::Dot(tvec, pvec) * invDet;
    if (u < 0 || u > 1) return false;

    Vector3 qvec = Vector3::Cross(tvec, v1v2);
    v = Vector3::Dot(direction, qvec) * invDet;
    if (v < 0 || u + v > 1) return false;

    distance = Vector3::Dot(v1v3, qvec) * invDet;

    return true;
  }

  void Curses3::Draw()
  {
    frameTiming[frame++ % 60] = Engine::GetDeltaTime();
    getmaxyx(window, height, width);
    auto drawables = Curses3Renderer::GetDrawables();
    float pixelWidth = viewport.scale.x / width;
    float pixelHeight = viewport.scale.y / height;
    Vector3 firstPixelCenter(viewport.position.x-viewport.scale.x/2+pixelWidth/2, viewport.position.y-viewport.scale.y/2+pixelHeight/2, viewport.position.z);
    Vector3 currentPixel = firstPixelCenter;
    for(int xPixel = 0; xPixel < width; ++xPixel)
    {
      for(int yPixel = 0; yPixel < height; ++yPixel)
      {
        Vector3 ray = (camera.position - currentPixel).Normalized();
        for(auto kv : drawables)
        {
          Curses3Renderer *drawable = kv.second;
          if(!drawable->IsEnabled()) { continue; }
          for(size_t i = 0; i < drawable->vertices.size(); i += 3)
          {
            Quaternion const &rotation = drawable->entity->transform->rotation;
            Vector3 const &position = drawable->entity->transform->position;
            Vector3 const &v1 = rotation * drawable->vertices[i] + position;
            Vector3 const &v2 = rotation * drawable->vertices[i+1] + position;
            Vector3 const &v3 = rotation * drawable->vertices[i+2] + position;
            float distance, u, v;
            if(RayTriangleIntersect(camera.position, ray, v1, v2, v3, distance, u, v))
            {
              mvwaddch(window, yPixel, xPixel, '#' | COLOR_PAIR(1));
            }
          }
        }
        currentPixel.y +=  pixelHeight;
      }
      currentPixel.y = firstPixelCenter.y;
      currentPixel.x += pixelWidth;
    }

    wrefresh(window);
    werase(window);
  }
}
