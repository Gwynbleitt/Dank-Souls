#include  "glad/glad.h"
#include  <GLFW/glfw3.h>

class ebo
{
    unsigned int m_ID;

public:

    ebo(unsigned int* data, unsigned int size, int usage);
    ~ebo();

    void bind() const,
    unbind() const;
};