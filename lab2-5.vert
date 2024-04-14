#version 150

in vec3 in_Position;
in vec3 in_Normal;
in vec2 inTexCoord;


out vec3 fragNormal;
out vec2 texCoord;


uniform mat4 projectionMatrix;
uniform mat4 transformMat;
uniform mat4 lookatMat;


void main(void)
{

  mat3 normalMatrix = mat3(transformMat);
  fragNormal = normalize(normalMatrix * in_Normal);
  gl_Position = projectionMatrix* lookatMat * transformMat * vec4(in_Position, 1.0);
 
  
  texCoord = inTexCoord;
}