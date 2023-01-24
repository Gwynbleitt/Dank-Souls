#include <stdio.h>
#include <math.h>

#pragma once

#define  PI  (float) 3.1415

namespace glm
{

    /* TRANSFORM */

    inline void translate(mat4& M, glm::vec3 v)
    {
        M[3][0] -= v[0];
        M[3][1] -= v[1];
        M[3][2] -= v[2];
        
    }

    inline void rotate(mat4& M, glm::vec3 r)
    {
        
    }

    inline void projection(mat4& M, float FOV,  float ratio, float n, float f)
    {

        float 
        t = n * tanf(FOV/2),
        r = t * ratio;

        M[0][0] =  n/r;
        M[1][1] =  n/t;

        M[2][2] = (-f-n)/(f-n);
        M[3][2] = (-2*f*n)/(f-n);

        M[3][3] = 0;
        M[2][3] = -1;
    }

    



    /* PRINT */

    template <typename mat>

    inline void printm(const mat& matrix, unsigned int nMat)
    {
        for(int y = 0; y < nMat; y++)
        {
            for(int x = 0; x < nMat; x++)
            {
                std::cout << matrix[x][y];

                if(x < nMat-1) printf("%c",',');
            }
            std::cout << '\n';
        }
    }

    template <typename vec>

    inline void printv(const vec& vector, unsigned int nVec)
    {
        for(int x = 0; x < nVec; x++)
        {
            std::cout << vector[x];
            
            if(x < nVec-1) printf("%c",',');
        }

        std::cout << '\n';
    }
}

