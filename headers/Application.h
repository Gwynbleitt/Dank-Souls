#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include "Renderer.h"

#include <assimp/Importer.hpp>


class Application
{

    GLFWwindow* WIN;

public:

    int FB_width, FB_height;

    static void 
    s_FB_size_callback(GLFWwindow* window, int width, int height),
    s_KEY_callback(GLFWwindow* window, int key, int scancode, int action, int mods);    

    void 
    load_mesh(float* verticies, int vn),

    run(const char* path);

   // Application();
    ~Application();

};