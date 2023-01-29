#include "Model.h"

Model::Model(std::string name)
{
    m_name = name;
}


void Model::LoadModel(const std::string& path)
{
    
    Assimp::Importer importer;
    
    const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_FixInfacingNormals);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << '\n';
        exit(EXIT_FAILURE);
    }

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]]; 
        m_mesh.push_back(processMesh(mesh, scene));			
    }
  
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
} 

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    

    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        glm::vec3 vector;
        Vertex vertex;
    
        vector.x = mesh->mVertices[i].x/2;
        vector.y = mesh->mVertices[i].y/2;
        vector.z = mesh->mVertices[i].z/2;
        vertex.Position = vector;

        if (mesh->HasNormals())
        {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.Normal = vector;
        }

        vertices.push_back(vertex);
    }
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);        
    }
    

    return Mesh(vertices, indices, GL_STATIC_DRAW);
}  