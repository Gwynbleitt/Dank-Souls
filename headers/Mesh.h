#include "vao.h"
#include "vbo.h"
#include "ebo.h"

struct Trasnform
{

};

struct vertex
{
    
};

class Mesh
{
public:

    float* m_vertex_data;
    /* vertex postitions [vec3],  vertex normals [vec3] */

    unsigned int* m_indicies;

    unsigned int m_nData, m_nIndex;

    vao* m_VAO;
    vbo* m_VBO;
    ebo* m_EBO;

    Mesh(float (&v_arr)[], unsigned int nData, unsigned int (&i_arr)[], unsigned int nIndex, int Usage);
    ~Mesh();


};