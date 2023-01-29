#include "Renderer.h"

Renderer::Renderer(GLFWwindow& win, float FOV, float n, float f)
{
    m_near = n;
    m_far = f;
    m_FOV = FOV;
    m_Mprojection = new glm::mat4(1.0f);

    m_lPoint = 
    {
        glm::vec3(0.0f),
        0.0f
    };
}

void Renderer::fb_u(int w, int h)
{
    glm::projection(*m_Mprojection, m_FOV, (float)w/h, m_near, m_far);
}

Renderer::~Renderer()
{
    delete m_Mprojection;
}

void Renderer::refresh()
{

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    
}

void Renderer::draw(Mesh& mesh, Shader& shader, glm::mat4& view, glm::mat4& camera)
{
    

    glUseProgram(shader.m_ID);
    
    shader.setmat4("MODEL", *(mesh.m_Mtransfrom));
    shader.setmat4("PROJECTION", *m_Mprojection);
    shader.setmat4("VIEW", view);
    shader.setmat4("CAMERA", camera);

    shader.setvec3("lPoint", m_lPoint.Position);

    glBindVertexArray(mesh.m_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.m_EBO);

    glDrawElements(GL_TRIANGLES, mesh.m_indicies.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
}




