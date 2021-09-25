#vertex_shader
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 u_Transform;

void main()
{
    gl_Position = u_Transform * vec4(aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}


#fragment_shader
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color; //basically a variable

void main()
{
	color = vec4(0.9, 0.4, 0.9, 1.0);
};