#include  "glad/glad.h"
#include  <GLFW/glfw3.h>

class vbo
{
    unsigned int m_ID;

public:

    vbo(float* data, unsigned int size, int usage);
    ~vbo();

    void bind() const,
    unbind() const;
};