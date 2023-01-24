#include "Mesh.h"

Mesh::Mesh(float (&v_arr)[], unsigned int nData, unsigned int (&i_arr)[], unsigned int nIndex, int Usage)
{

    m_Mtransfrom = new glm::mat4(1.0f);

    m_vertex_data = v_arr;
    m_indicies  = i_arr;

    m_nData = nData;
    m_nIndex = nIndex;

    m_VBO = new vbo(v_arr, nData*sizeof(float), Usage);
    m_VAO = new vao;
    m_EBO = new ebo(i_arr, nIndex*sizeof(unsigned int), Usage);

    m_VBO->bind();
    m_EBO->bind();
    
    m_VAO->push(3, false); 
    m_VAO->push(3, false);
    m_VAO->flush();

    m_VBO->unbind();
    m_EBO->unbind();
}

Mesh::~Mesh()
{
    delete m_VBO;
    delete m_EBO;
    delete m_VAO;
}