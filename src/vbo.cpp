#include "vbo.h"

vbo::vbo(float* data, unsigned int size, int usage)
{
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

vbo::~vbo()
{
    glDeleteBuffers(1, &m_ID);
}

void vbo::bind() const
{
   glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void vbo::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}