#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class Model
{

    
    std::string m_dir;
    
public:

    std::string m_name;
    std::vector<Mesh> m_mesh;

    void LoadModel(const std::string& path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    Model(std::string name);
};