// Lab 1-1.
// This is the same as the first simple example in the course book,
// but with a few error checks.
// Remember to copy your file to a new on appropriate places during the lab so you keep old results.
// Note that the files "lab1-1.frag", "lab1-1.vert" are required.

#include "GL_utilities.h"
#include "MicroGlut.h"
#include <math.h>

// Globals
// Data would normally be read from files
GLfloat vertices[] = {
    // Base vertices
    -0.5f, -0.5f, -0.5f,  // Base 1
     0.5f, -0.5f, -0.5f,  // Base 2
    -0.5f,  0.5f, -0.5f,  // Base 3

    -0.5f,  0.5f, -0.5f,  
     0.5f,  0.5f, -0.5f,  // Base 4
     0.5f, -0.5f, -0.5f,  

    // Side 1
    -0.5f, -0.5f, -0.5f, 
     0.0f,  0.0f,  0.5f,   // Apex
    -0.5f,  0.5f, -0.5f,  

    // Side 2
    -0.5f, -0.5f, -0.5f,
     0.0f,  0.0f,  0.5f,   // Apex
     0.5f, -0.5f, -0.5f, 

    // Side 3
     0.5f, -0.5f, -0.5f,
     0.0f,  0.0f,  0.5f,   // Apex
     0.5f,  0.5f, -0.5f,  

    // Side 4
     0.5f,  0.5f, -0.5f,
     0.0f,  0.0f,  0.5f,   // Apex
    -0.5f,  0.5f, -0.5f  
};


float colors[] = {
    // Base colors
    0.0f, 1.0f, 0.0f, // Green
    0.0f, 1.0f, 0.0f, 
    0.0f, 1.0f, 0.0f, 

    0.0f, 1.0f, 0.0f, // Green
    0.0f, 1.0f, 0.0f, 
    0.0f, 1.0f, 0.0f, 

    // Side 1 colors
    1.0f, 0.0f, 0.0f, // Red
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    
    // Side 2 colors
    1.0f, 1.0f, 1.0f, // White
    1.0f, 1.0f, 1.0f, 
    1.0f, 1.0f, 1.0f, 
    
    // Side 3 colors
 	1.0f, 0.0f, 1.0f, 
    1.0f, 0.0f, 1.0f, 
    1.0f, 0.0f, 1.0f, 
    
    // Side 4 colors
    1.0f, 1.0f, 0.0f, // Red
    1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
};


GLfloat t = (GLfloat)glutGet(GLUT_ELAPSED_TIME);

// GLfloat rotationMatrix[] = {  cos(t), -sin(t), 0.0f, 0.0f,
//                         sin(t), cos(t), 0.0f, 0.0f,
//                         0.0f, 0.0f, 1.0f, 0.0f,
//                         0.0f, 0.0f, 0.0f, 1.0f };

GLfloat rotationMatrix[] = { 1.0f ,0.0f, 0.0f, 0.0f,
                        0.0f, cos(t), -sin(t), 0.0f, 
                        0.0f, sin(t), cos(t), 0.0f, 
                        0.0f, 0.0f, 0.0f, 1.0f };
// vertex array object
unsigned int vertexArrayObjID;
GLuint program;

void init(void)
{
	// vertex buffer object, used for uploading the geometry
	unsigned int vertexBufferObjID;
	// Reference to shader program

    glutRepeatingTimer(100);
	dumpInfo();

	// GL inits
	glClearColor(0.2,0.2,0.5,0);
	glDisable(GL_DEPTH_TEST);

	printError("GL inits");

	// Load and compile shader
	program = loadShaders("lab1-5.vert", "lab1-5.frag");
	printError("init shader");
	
	// Upload geometry to the GPU:
	
	// Allocate and activate Vertex Array Object
	glGenVertexArrays(1, &vertexArrayObjID);
	glBindVertexArray(vertexArrayObjID);
	// Allocate Vertex Buffer Objects
	glGenBuffers(1, &vertexBufferObjID);
	// VBO for vertex data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID);
	glBufferData(GL_ARRAY_BUFFER, 6*9*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(glGetAttribLocation(program, "in_Position"), 3, GL_FLOAT, GL_FALSE, 0, 0); 
	glEnableVertexAttribArray(glGetAttribLocation(program, "in_Position"));
	// End of upload of geometry

	//upload color shading
	unsigned int colorBufferObjID;
	// 
	glGenBuffers(1,&colorBufferObjID);
	//
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferObjID); 
	glBufferData(GL_ARRAY_BUFFER, 6*9*sizeof(GLfloat), colors, GL_STATIC_DRAW); // Enable the attribute in the shader and specify how the data is formatted 
	glVertexAttribPointer(glGetAttribLocation(program, "inColor"), 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(glGetAttribLocation(program, "inColor"));



	printError("init arrays");
}


void display(void)
{
	printError("pre display");

	// clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glDisable(GL_DEPTH_TEST);
	// glEnable(GL_CULL_FACE);


	glBindVertexArray(vertexArrayObjID);	// Select VAO
	glDrawArrays(GL_TRIANGLES, 0, 18);	// draw object

    GLfloat t = (GLfloat)glutGet(GLUT_ELAPSED_TIME)/1000;

    // GLfloat rotationMatrix[] = {  cos(t), -sin(t), 0.0f, 0.0f,
    //                     sin(t), cos(t), 0.0f, 0.0f,
    //                     0.0f, 0.0f, 1.0f, 0.0f,
    //                     0.0f, 0.0f, 0.0f, 1.0f };

	GLfloat rotationMatrix[] = { 1.0f ,0.0f, 0.0f, 0.0f,
                        0.0f, cos(t), -sin(t), 0.0f, 
                        0.0f, sin(t), cos(t), 0.0f, 
                        0.0f, 0.0f, 0.0f, 1.0f };
    
	glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, rotationMatrix);
	
	glutSwapBuffers();

	printError("display");
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitContextVersion(3, 2);
	glutInitWindowSize(600, 600);
	glutCreateWindow ("GL3 white triangle example");
	glutDisplayFunc(display); 
	init ();
	glutMainLoop();
	return 0;
}

