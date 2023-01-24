#include <glm/glm.hpp>
#include "DS_math.hpp"


class Camera
{

    glm::vec3 u,r,t,  //up right target
    position,
    origin;

public:

    float FOV;

    

    Camera(float FOV);
    ~Camera();
};