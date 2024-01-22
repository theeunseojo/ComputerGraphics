# set this variable to the director in which you saved the common files
commondir = ../common/

all : lab1-1 lab1-2 lab1-3

lab1-1 : lab1-1.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c
	gcc -Wall -o lab1-1 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab1-1.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

lab1-2 : lab1-2.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c
	gcc -Wall -o lab1-2 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab1-2.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++

lab1-3 : lab1-3.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c
	gcc -Wall -o lab1-3 -I$(commondir) -I../common/Linux -DGL_GLEXT_PROTOTYPES lab1-3.cpp $(commondir)GL_utilities.c $(commondir)LoadTGA.c $(commondir)Linux/MicroGlut.c -lXt -lX11 -lGL -lm -lstdc++


clean :
	rm lab1-1 lab1-2 lab1-3

