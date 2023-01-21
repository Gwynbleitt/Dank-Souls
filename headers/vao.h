#include  "glad/glad.h"
#include  <GLFW/glfw3.h>
#include <iostream>
#include <vector>

struct buffer_element
{
    unsigned int nSize, offset;
    bool normalize;

    
};

class vao
{
    
    unsigned int m_ID;
    unsigned int m_stride = 0;
   

    std::vector<buffer_element>* m_vao_buffer;

public:

    vao();
    ~vao();

    //assuming type = GL_FLOAT

    void push(unsigned int nSize, bool normalize),
    flush() const,
    bind() const,
    unbind() const;
    

};