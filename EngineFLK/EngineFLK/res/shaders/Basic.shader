#vertex_shader
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_View = mat4(1.0);
uniform mat4 u_Projection = mat4(1.0);

void main()
{
    gl_Position = u_Model * u_View * u_Projection * vec4(position, 1.0f);
    v_TexCoord = texCoord;
}


#fragment_shader
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
    vec4 textureColor = texture(u_Texture, v_TexCoord);
    //color = u_Color;
    color = textureColor * u_Color;
};