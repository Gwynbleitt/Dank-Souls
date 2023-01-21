#include "ebo.h"

ebo::ebo(unsigned int* data, unsigned int size, int usage)
{
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
}

ebo::~ebo()
{
    glDeleteBuffers(1, &m_ID);
}

void ebo::bind() const
{
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void ebo::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}