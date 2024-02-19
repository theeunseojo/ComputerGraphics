#version 150

in vec3 exColor;
out vec4 out_Color;
in vec2 texCoord;

void main(void)
{
	float a = sin(texCoord.s*30)/2+0.5;
    float b = sin(texCoord.t*30)/2+0.5;
	out_Color = vec4(a,b,1.0,0.0);
}
