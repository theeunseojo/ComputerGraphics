# set this variable to the director in which you saved the common files
commondir = ../common/

all : lab2-1 lab2-2 lab2-3 lab2-4 lab2-5

lab2-1 : lab2-1.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c
	gcc -Wall -o lab2-1 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab2-1.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

lab2-2 : lab2-2.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c
	gcc -Wall -o lab2-2 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab2-2.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

lab2-3 : lab2-3.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c 
	gcc -Wall -o lab2-3 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab2-3.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

lab2-4 : lab2-4.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c 
	gcc -Wall -o lab2-4 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab2-4.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

lab2-5 : lab2-5.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c 
	gcc -Wall -o lab2-5 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab2-5.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

clean :
	rm lab2-1 lab2-2 lab2-3 lab2-4 lab2-5
