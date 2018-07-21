#ifndef SINGULARITY_MESHRENDERER_HPP_
#define SINGULARITY_MESHRENDERER_HPP_

#include <string>
#include <unordered_map>
#include <Singularity/Behavior.hpp>

struct aiScene;
namespace Singularity::Geometry { class Vector3; }

namespace Singularity::Graphics
{
  class MeshRenderer : public Component
  {
    struct Mesh
    {
      std::vector<Geometry::Vector3 *> vertices;
      std::vector<std::vector<unsigned int> *> faceIndices;
    };

    static std::unordered_map<std::string, aiScene const *> sceneCache;
    static std::unordered_map<size_t, MeshRenderer *> drawables;

  public:

    MeshRenderer();
    ~MeshRenderer() override;

    std::vector<Mesh *> meshes;

    void LoadFromFile(std::string const &filePath);
    void LoadFromCache(std::string const &sceneName);

    static void CacheFromFile(std::string const &filePath);
    static inline std::unordered_map<size_t, MeshRenderer *> const &GetDrawables() { return drawables; }
  };
}
#endif
