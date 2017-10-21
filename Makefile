CC = mingw32-g++

INC = -I$(GLFW)\include -I$(GLEW)\include 
LIBS = -lglfw3 -lglew -lgdi32 -lopengl32  
LIB_DIR = -L..\opengl-practice


Game: main.o
	$(CC) $(LIB_DIR) main.o -o Game $(LIBS)
	
main.o: main.cpp
	$(CC) $(INC) -c main.cpp
	
clean:
	-rm -f *.o *.exe