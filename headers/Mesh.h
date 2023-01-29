#include <vector>
#include "vertex.h"
#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

struct Texture
{
    unsigned int id;
    std::string type;
};

class Mesh
{
public:

    std::vector<Vertex> m_verex_data;
    std::vector<Texture> m_texture_data;
    std::vector<unsigned int> m_indicies;

    glm::mat4* m_Mtransfrom;

    unsigned int m_VAO, m_EBO, m_VBO;

    Mesh(std::vector<Vertex> verticies, std::vector<unsigned int> indicies, int Usage);


};