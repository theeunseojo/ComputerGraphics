#version 150

in vec2 texCoord;
in vec3 exColor;
in vec3 fragNormal;

out vec4 out_Color;
// 2-2
uniform sampler2D texUnit;


void main(void)
{	
	float a = sin(texCoord.s*30)/2+0.5;
	float b = sin(texCoord.t*30)/2+0.5;
	
	vec3 light = vec3(0.58,0.58,0.58);
	float shade;
	shade = dot(normalize(fragNormal),light);
	shade = clamp(shade,0,1);
    out_Color = texture(texUnit,texCoord) * shade;
}
