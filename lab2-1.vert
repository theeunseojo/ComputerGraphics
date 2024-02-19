#version 150

in vec3 in_Position;
in vec3 in_Normal;
uniform mat4 rotationMatrix;
out vec3 exColor;
in vec3 inColor;
in vec2 inTexCoord;
out vec2 texCoord;
float shade; 


void main(void)
{
  const vec3 light = vec3(0.6, 0.58, 0.48);
  shade = dot(normalize(in_Normal), light);
  shade = max(shade, 0);
  exColor = vec3(shade); 
  texCoord = inTexCoord;
  gl_Position = rotationMatrix * vec4(in_Position, 1.0);
}