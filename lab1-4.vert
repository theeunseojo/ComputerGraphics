#version 150

in vec3 in_Position;

in vec3 inNormal;
out vec3 exColor;
in vec3 inColor;

void main(void)
{
	
	const vec3 light = vec3(0.58,0.58,0.58);
	float shade;
	shade = dot(normalize(inNormal),light);
	shade = max(shade,0);
	//exColor = vec3(shade);
	exColor = inColor;
	gl_Position = vec4(in_Position,1.0);

}