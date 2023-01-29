#include "Mesh.h"
/*
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
}*/

Mesh::Mesh(std::vector<Vertex> verticies, std::vector<unsigned int> indicies, int Usage)
{
    m_Mtransfrom = new glm::mat4(1.0f);

    m_verex_data = verticies;
    m_indicies = indicies;
    
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(Vertex), &verticies[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(unsigned int), &indicies[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)12);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);

    /*

    m_VAO = new vao;
    m_VBO = new vbo(verticies, Usage);
    m_EBO = new ebo(indicies, Usage);

    m_VBO->bind();
    m_EBO->bind();
    
    m_VAO->add(verticies);

    m_VBO->unbind();
    m_EBO->unbind();*/

}