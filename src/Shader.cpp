#include "Shader.h"

std::string Shader::read_shader(const std::string& path){
    std::string line, tmp = "";
    std::ifstream file;
    file.open( path );
    if(file.is_open()){
        while(getline(file,line)){
            tmp.append(line);
            tmp.append("\n");
        }
       file.close();
    } else printf("FAILED TO READ SHADER\n");
    return tmp;
}

bool Shader::SHADER_ERROR_CHECK(unsigned int id, bool type){
    int success;

    if(type) glGetProgramiv(id, GL_LINK_STATUS, &success);
    else     glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(id, 512, NULL, log);
        if(type) printf("SHADER PROGRAM LINKING ERROR\n%s\n",log);
        else     printf("SHADER COMPILATION ERROR\n%s\n",log);
    }
    return success ? true : false;
}

Shader::Shader(const std::string& vs_path, const std::string& fs_path){

     
    unsigned int vertexshader, fragmentshader;

    std::string tmp = read_shader(vs_path);
    const char* shadersrc = tmp.c_str();

    vertexshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexshader, 1, &shadersrc, NULL);
    glCompileShader(vertexshader);

    tmp = read_shader(fs_path);
    shadersrc = tmp.c_str();

    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &shadersrc, NULL);
    glCompileShader(fragmentshader);

    if(!(SHADER_ERROR_CHECK(vertexshader,SHADER)&&SHADER_ERROR_CHECK(fragmentshader,SHADER))) exit(EXIT_FAILURE);

    std::cout << "SHADERS_COMPILED\n";

    program = glCreateProgram();
    glAttachShader(program, vertexshader);
    glAttachShader(program, fragmentshader);
    glLinkProgram(program);

    if(!SHADER_ERROR_CHECK(program, SHADER_PROGRAM) ) exit(EXIT_FAILURE);
    printf("SHADER_PROGRAM_LINKED\n");

    glDeleteShader(vertexshader);
    glDeleteShader(fragmentshader);

}

void Shader::use()
{
    glUseProgram(program);
}

Shader::~Shader(){
    glDeleteProgram(program);
}