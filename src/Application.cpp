#include "Application.h"

void Application::run()
{

    if(!glfwInit()) exit(EXIT_FAILURE);

    GLFWmonitor* monitor;
    const GLFWvidmode* visual;

    monitor = glfwGetPrimaryMonitor();
    if(!monitor) exit(EXIT_FAILURE);
    visual = glfwGetVideoMode(monitor);

    WIN = glfwCreateWindow(visual->width, visual->height, "Dank Souls",  NULL, NULL);
    if(!WIN) exit(EXIT_FAILURE);

    glfwMakeContextCurrent(WIN);
    glfwSetFramebufferSizeCallback(WIN, s_FB_size_callback);
    glfwSetKeyCallback(WIN, s_KEY_callback);
    glfwSetWindowUserPointer(WIN, this);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) exit(EXIT_FAILURE);
    
    float verticies [] = 
    {
     0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,// top right
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,// bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,// bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 0.0f// top left 
    };

    unsigned int indicies [] =
    {
        0,1,3,
        1,2,3
    };

 

    

    vbo VBO1(verticies, sizeof(verticies), GL_STATIC_DRAW);
    vao VAO1;
    ebo EBO1(indicies, sizeof(indicies), GL_STATIC_DRAW);
    
    VBO1.bind();
    EBO1.bind();
    
    VAO1.push(3, true); 
    VAO1.push(3, false);
    VAO1.flush();

    VBO1.unbind();
    EBO1.unbind();

    Shader shader("../shaders/vertex.vs", "../shaders/fragment.fs");

    //event_loop(VAO1, shader, in * 3);

    Renderer r1;

    while(!glfwWindowShouldClose(WIN))
    {

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

        

        glUseProgram(shader.program);

        VAO1.bind();
        
      
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //std::cout << "debug" << '\n';

        glfwSwapBuffers(WIN);
        glfwPollEvents();
    }

}

Application::~Application()
{

    glfwDestroyWindow(WIN);
    glfwTerminate();
    
    std::cout << "closing" << '\n';
}

/* CALLBACKS */

void Application::s_FB_size_callback(GLFWwindow* window, int width, int height)
{
    Application* copy = static_cast<Application*>(glfwGetWindowUserPointer(window));

    copy->FB_width = width;
    copy->FB_height = height;

    glViewport(0, 0, width, height);

    printf("framebuffer callback\n");
}

void Application::s_KEY_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action==1) switch(key){
        case GLFW_KEY_ESCAPE:
        case GLFW_KEY_Q:
            exit(EXIT_FAILURE);
            break;
        default: break;
    }
}
