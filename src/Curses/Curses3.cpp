#include <cmath>
#include <limits>
#include <ncurses.h>
#include <assimp/scene.h>
#include <Singularity/Engine.hpp>
#include <Singularity/Entity.hpp>
#include <Singularity/Geometry/Vector3.hpp>
#include <Singularity/Graphics/Curses3.hpp>
#include <Singularity/Graphics/MeshRenderer.hpp>

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

  bool Curses3::RayTriangleIntersect(
      Geometry::Vector3 const &origin, Geometry::Vector3 const &direction,
      Geometry::Vector3 const &v1, Geometry::Vector3 const &v2, Geometry::Vector3 const &v3,
      float &distance, float &u, float &v)
  {
    Geometry::Vector3 v1v2 = v2 - v1;
    Geometry::Vector3 v1v3 = v3 - v1;
    Geometry::Vector3 pvec = Geometry::Vector3::Cross(direction, v1v3);
    float det = Geometry::Vector3::Dot(v1v2, pvec);

    //if(det < std::numeric_limits<float>::epsilon()) { return false; }

    if(fabs(det) < std::numeric_limits<float>::epsilon()) { return false; }
    float invDet = 1 / det;

    Geometry::Vector3 tvec = origin - v1;
    u = Geometry::Vector3::Dot(tvec, pvec) * invDet;
    if (u < 0 || u > 1) return false;

    Geometry::Vector3 qvec = Geometry::Vector3::Cross(tvec, v1v2);
    v = Geometry::Vector3::Dot(direction, qvec) * invDet;
    if (v < 0 || u + v > 1) return false;

    distance = Geometry::Vector3::Dot(v1v3, qvec) * invDet;

    return true;
  }

  void Curses3::Draw()
  {
    frameTiming[frame++ % 60] = Engine::GetDeltaTime();
    getmaxyx(window, height, width);
    auto drawables = MeshRenderer::GetDrawables();
    float pixelWidth = viewport.scale.x / width;
    float pixelHeight = viewport.scale.y / height;
    Geometry::Vector3 firstPixelCenter(viewport.position.x-viewport.scale.x/2+pixelWidth/2, viewport.position.y-viewport.scale.y/2+pixelHeight/2, viewport.position.z);
    Geometry::Vector3 currentPixel = firstPixelCenter;
    for(int xPixel = 0; xPixel < width; ++xPixel)
    {
      for(int yPixel = 0; yPixel < height; ++yPixel)
      {
        Geometry::Vector3 ray = (camera.position - currentPixel).Normalized();
        for(auto kv : drawables)
        {
          MeshRenderer *drawable = kv.second;
          for(auto *mesh : drawable->meshes)
          {
            for(std::vector<unsigned int> *face : mesh->faceIndices)
            {
              for(size_t indexNum = 0; indexNum < face->size(); indexNum += 3)
              {
                unsigned int i1 = face->at(indexNum);
                unsigned int i2 = face->at(indexNum + 1);
                unsigned int i3 = face->at(indexNum + 2);
                Geometry::Quaternion const &rotation = drawable->entity->transform->rotation;
                Geometry::Vector3 const &position = drawable->entity->transform->position;
                Geometry::Vector3 v1 = rotation * *mesh->vertices[i1] + position;
                Geometry::Vector3 v2 = rotation * *mesh->vertices[i2] + position;
                Geometry::Vector3 v3 = rotation * *mesh->vertices[i3] + position;
                float distance, u, v;
                if(RayTriangleIntersect(camera.position, ray, v1, v2, v3, distance, u, v))
                {
                  mvwaddch(window, yPixel, xPixel, '#' | COLOR_PAIR(1));
                }
              }
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
