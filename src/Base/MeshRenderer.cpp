#include <experimental/filesystem>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <Singularity/Graphics/MeshRenderer.hpp>
#include <Singularity/Geometry/Vector3.hpp>

namespace Singularity::Graphics
{
  std::unordered_map<std::string, aiScene const *> MeshRenderer::sceneCache;
  std::unordered_map<size_t, MeshRenderer *> MeshRenderer::drawables;

  MeshRenderer::MeshRenderer()
  {
    MeshRenderer::drawables[GetInstanceId()] = this;
  }

  MeshRenderer::~MeshRenderer()
  {
    for(Mesh *mesh : meshes)
    {
      for(Geometry::Vector3 *vertice : mesh->vertices)
      {
        delete vertice;
      }
      delete mesh;
    }
    drawables.erase(GetInstanceId());
  }

  void MeshRenderer::LoadFromCache(std::string const &sceneName)
  {
    aiScene const *scene = MeshRenderer::sceneCache[sceneName];
    for(size_t meshNum = 0; meshNum < scene->mNumMeshes; ++meshNum)
    {
      aiMesh const *mesh = scene->mMeshes[meshNum];
      Mesh *internalMesh = new Mesh();
      for(size_t verticeNum = 0; verticeNum < mesh->mNumVertices; ++verticeNum)
      {
        aiVector3D const &vertice = mesh->mVertices[verticeNum];
        internalMesh->vertices.push_back(new Geometry::Vector3(vertice.x, vertice.y, vertice.z));
      }
      for(size_t faceNum = 0; faceNum < mesh->mNumFaces; ++faceNum)
      {
        aiFace const &face = mesh->mFaces[faceNum];
        std::vector<unsigned int> *indices = new std::vector<unsigned int>();
        for(size_t indexNum = 0; indexNum < face.mNumIndices; ++indexNum)
        {
          indices->push_back(face.mIndices[indexNum]);
        }
        internalMesh->faceIndices.push_back(indices);
      }
      meshes.push_back(internalMesh);
    }
  }

  void MeshRenderer::LoadFromFile(std::string const &filePath)
  {
    MeshRenderer::CacheFromFile(filePath);
    std::experimental::filesystem::path filesystemPath(filePath);
    LoadFromCache(filesystemPath.stem().string());
  }

  void MeshRenderer::CacheFromFile(std::string const &filePath)
  {
    Assimp::Importer importer;
    unsigned int flags = aiProcess_Triangulate|aiProcess_SortByPType;
    importer.ReadFile(filePath, flags);
    aiScene const *scene = importer.GetOrphanedScene();
    std::experimental::filesystem::path filesystemPath(filePath);
    sceneCache[filesystemPath.stem().string()] = scene;
  }
}
