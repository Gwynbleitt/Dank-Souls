#include "Application.h"

void Application::event_loop(const vao& VAO, const Shader& shader, unsigned int n)
{

    Renderer r1;

    while(!glfwWindowShouldClose(WIN))
    {

        //r1.draw(VAO, shader, n);

        glfwSwapBuffers(WIN);
        glfwPollEvents();
    }

}