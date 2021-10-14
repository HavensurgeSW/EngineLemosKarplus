#vertex_shader
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_View = mat4(1.0);
uniform mat4 u_Projection = mat4(1.0);

void main()
{
    gl_Position = u_Model * u_View * u_Projection * vec4(aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}


#fragment_shader
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color; //basically a variable

void main()
{
    color = u_Color;
};