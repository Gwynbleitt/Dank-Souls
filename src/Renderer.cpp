#include "Renderer.h"

void Renderer::draw(const vao& VAO, const Shader& shader, unsigned int n)
{

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    

    glUseProgram(shader.program);

    VAO.bind();
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    std::cout << "debug" << '\n';
    //VAO.unbind();
} 