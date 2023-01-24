#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;

uniform mat4 MODEL;
uniform mat4 PROJECTION;

void main()
{
    gl_Position = PROJECTION * MODEL * vec4(aPos, 1.0);
}