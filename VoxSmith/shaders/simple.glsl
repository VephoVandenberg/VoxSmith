#shader VERTEX

#version 430 core

layout (location = 0) in vec3 in_pos;

void main()
{
    gl_Position = vec4(in_pos, 1.0f);
}

#shader GEOMETRY
#shader FRAGMENT

#version 430 core

out vec4 o_color;

void main()
{
    o_color = vec4(0.4f, 1.0f, 0.2f, 1.0f);
}