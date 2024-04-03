#version 150

in vec3 in_Position;
in vec3 in_Normal;
uniform mat4 rotationMatrix;
out vec3 exColor;
in vec3 inColor;
float shade; 

in vec2 inTexCoord;
out vec2 texCoord;

uniform mat4 projectionMatrix;
uniform mat4 transformMat;

uniform mat4 lookatMat;


void main(void)
{
  const vec3 light = vec3(0.58, 0.58, 0.58);
  shade = dot(normalize(in_Normal), light);
  shade = max(shade, 0);
  exColor = vec3(shade); 
  texCoord = inTexCoord;
  gl_Position = projectionMatrix* lookatMat * transformMat * vec4(in_Position, 1.0);
}