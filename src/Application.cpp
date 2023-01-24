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
     0.5f,  0.5f,  0.5,     1.0f, 0.0f, 0.0f,// top right
     0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,// bottom right
    -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,// bottom left
    -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,// top left 
     0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,// top right
     0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,// bottom right
    -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,// bottom left
    -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f // top left 
    };

    unsigned int indicies [] =
    {
        0,1,3,
        1,2,3,

        4,5,7,
        5,6,7,

        0,4,1,
        1,4,5,

        3,7,6,
        2,3,6,

        0,3,7,
        4,7,1,

        1,2,6,
        5,6,1
    };
    

    /*Mesh* square = new Mesh(verticies_a, sizeof(verticies_a)/sizeof(float), indicies_a, sizeof(indicies_a)/sizeof(unsigned int), GL_STATIC_DRAW);
    Mesh* tris = new Mesh(verticies_b, sizeof(verticies_b)/sizeof(float), indicies_b, sizeof(indicies_b)/sizeof(float), GL_STATIC_DRAW);
    */

    Mesh Player(verticies, sizeof(verticies)/sizeof(float), indicies, sizeof(indicies)/sizeof(unsigned int), GL_DYNAMIC_DRAW);
    
    Shader shader("../shaders/vertex.vs", "../shaders/fragment.fs");

    Renderer r1 (*WIN);
    

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    /* EVENT LOOP */

    const float speed = 0.1f;
    
    while(!glfwWindowShouldClose(WIN))
    {

        /*  PROCESS INPUT */

        
        if(glfwGetKey(WIN, GLFW_KEY_A) == GLFW_PRESS) glm::translate(*(Player.m_Mtransfrom),glm::vec3(-speed,0.f,0.f));
        if(glfwGetKey(WIN, GLFW_KEY_W) == GLFW_PRESS) glm::translate(*(Player.m_Mtransfrom),glm::vec3(0.f,0.f,speed));
        if(glfwGetKey(WIN, GLFW_KEY_S) == GLFW_PRESS) glm::translate(*(Player.m_Mtransfrom),glm::vec3(0.f,0.f,-speed));
        if(glfwGetKey(WIN, GLFW_KEY_D) == GLFW_PRESS) glm::translate(*(Player.m_Mtransfrom),glm::vec3(speed,0.f,0.f));
        
        /* RENDER */

        r1.refresh();

        r1.draw(Player, shader);

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
