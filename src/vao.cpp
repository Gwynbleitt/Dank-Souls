#include "vao.h"

vao::vao()
{
    glGenVertexArrays(1, &m_ID);
    bind();

    m_vao_buffer = new std::vector<buffer_element>;
}

vao::~vao()
{
    glDeleteVertexArrays(1, &m_ID);

    delete m_vao_buffer;
}

void vao::push(unsigned int nSize, bool normalize)
{
    
    m_vao_buffer->push_back({nSize, m_stride, normalize});
    m_stride += nSize;
}

void vao::flush() const
{
    bind();
    
    for(int i = 0; i < m_vao_buffer->size(); i++)
    {

        glVertexAttribPointer(
            i, 
            (*m_vao_buffer)[i].nSize, 
            GL_FLOAT, 
            (*m_vao_buffer)[i].normalize, 
            m_stride * sizeof(float), 
            (void*) ((*m_vao_buffer)[i].offset*sizeof(float))
        );

        glEnableVertexAttribArray(i);
    }

    unbind();
    
    m_vao_buffer->clear();
}

void vao::bind() const
{
    glBindVertexArray(m_ID);
}
void vao::unbind() const
{
    glBindVertexArray(0);
}