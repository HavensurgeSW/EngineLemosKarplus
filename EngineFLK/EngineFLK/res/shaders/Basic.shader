#vertex_shader
#version 330 core

layout(location = 0) in vec4 position;

void main()
{
	gl_Position = position;
};


#fragment_shader
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color; //basically a variable

void main()
{
	color = vec4(0.9, 0.4, 0.9, 1.0);
};