#ifndef SHADER_H
#define SHADER_H

#define SHADER 0
#define SHADER_PROGRAM 1
#define GL_GLEXT_PROTOTYPES

#include  "glad/glad.h"
#include  <GLFW/glfw3.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <cstring>
#include  <iostream>
#include  <fstream>

class Shader{

    bool  SHADER_ERROR_CHECK (unsigned int shaderid, bool type);
    std::string read_shader(const std::string& path);

    char log[512];

public:

    unsigned int program;

    void use();

    Shader(const std::string& vs_path, const std::string& fs_path);
    ~Shader();

};

#endif