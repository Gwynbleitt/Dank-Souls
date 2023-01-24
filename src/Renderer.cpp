#include "Renderer.h"

Renderer::Renderer(GLFWwindow& win, float n, float f)
{

    int w, h;

    m_near = n;
    m_far = f;

    glfwGetFramebufferSize(&win, &w, &h);

    m_Mprojection = new glm::mat4(1.0f);

    glm::projection(*m_Mprojection, PI, w/h, n, f);

    glm::printm<glm::mat4>(*m_Mprojection, 4);

    //shader.setmat4("PROJECTION", *m_Mprojection);
}

void Renderer::fb_u(int w, int h)
{
    glm::projection(*m_Mprojection, )
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

void Renderer::draw(Mesh& mesh, Shader& shader)
{

    glUseProgram(shader.m_ID);

    shader.setmat4("MODEL", *(mesh.m_Mtransfrom));
    shader.setmat4("PROJECTION", *m_Mprojection);

    mesh.m_VAO->bind();
    
    glDrawElements(GL_TRIANGLES, mesh.m_nIndex, GL_UNSIGNED_INT, 0);
    
    mesh.m_VAO->unbind();
}




