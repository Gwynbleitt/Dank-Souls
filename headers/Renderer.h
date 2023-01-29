#include "Model.h"
#include "Shader.h"
#include "Camera.h"
#include <DS_math.hpp>
#include "Lights.h"

class Renderer
{

    glm::mat4* m_Mprojection;
    
    float m_near, m_far, m_FOV;

public:

    lPoint m_lPoint;

    void
    fb_u(int w, int h), 
    refresh(),
    draw(Mesh& mesh, Shader& shader, glm::mat4& view, glm::mat4& camera);

    Renderer(GLFWwindow& win, float FOV, float n, float f);
    ~Renderer();

};