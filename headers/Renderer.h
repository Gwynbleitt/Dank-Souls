#include "Mesh.h"
#include "Shader.h"
#include <DS_math.hpp>

class Renderer
{

    glm::mat4* m_Mprojection;

    float m_near, m_far;

public:

    void
    fb_u(int w, int h), 
    refresh(),
    draw(Mesh& mesh, Shader& shader);

    Renderer(GLFWwindow& win, float n, float f);
    ~Renderer();

};