#vertex_shader
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 aColor;

out vec4 v_Color;

uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_View = mat4(1.0);
uniform mat4 u_Projection = mat4(1.0);

void main()
{
    gl_Position = u_Model * u_View * u_Projection * vec4(position, 1.0f);
    v_Color = aColor;
}


#fragment_shader
#version 330 core

out vec4 FragColor;
in vec4 v_Color;

void main()
{
    FragColor = v_Color;
};