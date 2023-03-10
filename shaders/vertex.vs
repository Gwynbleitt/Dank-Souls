#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aNormal;

uniform mat4 MODEL;
uniform mat4 PROJECTION;
uniform mat4 VIEW;
uniform mat4 CAMERA;

uniform vec3 lPoint;

out vec3 color;

float dot(vec3 a, vec3 b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

void main()
{
    gl_Position = PROJECTION * VIEW * CAMERA * MODEL * vec4(aPos, 1.0);

    color = vec3(dot(aNormal, lPoint)*0.3 + 0.5);
}