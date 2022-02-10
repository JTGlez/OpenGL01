/*
* Laboratorio de Computación gráfica e interacción Humano-Computadora
* 01 - Configuración de OpenGL
* Based on: https://www.glfw.org/documentation.html
*/

/*Bibliotecas o headers estándar de C*/
#include <stdlib.h>
#include <stdio.h>

/*Establece propiedades de una ventana gráfica activa.*/
#include <GLFW/glfw3.h>

/*Bibliotecas o headers estándar de C++*/
#include <iostream>
#include <sstream>

/*Permite crear etiquetados de funciones y usar las funciones asociadas a la etiqueta std.

Con namespace std:
cout << "Hola mundo"

Sin namespace std:
std::cout << "Hola mundo" */
using namespace std;


int main(void) {

	/*BEGIN OpenGL Inicialization*/

	GLFWwindow* window;

	/* Initialize the library. Request resources from the OS to display graphics. If there's not
	available resources, the program ends. */
	if (!glfwInit())
		return -1;

	/* Maximize window */
	// glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

	/* Transparent framebuffer */
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

	/* Create a windowed mode window and its OpenGL context.
	Window of 640x480 called "Hello World". Aditional pointers of locations and resources.
	Returns a pointer that redirects to the window, but if there's not pointer retured, the
	program ends. */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Define the window position in screen coordinates */
	// glfwSetWindowPos(window, 50, 50);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/*END OpenGL Inicialization*/

	/* Graphics device information */
	cout << "> Version: " << glGetString(GL_VERSION) << endl;
	cout << "> Vendor: " << glGetString(GL_VENDOR) << endl;
	cout << "> Renderer: " << glGetString(GL_RENDERER) << endl;
	cout << "> Supported Extensions: " << glGetString(GL_EXTENSIONS) << endl;

	/*Drawing Loop*/

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here. Clean buffer: it cleans and draws.*/
		glClear(GL_COLOR_BUFFER_BIT);

		/* Change the background Color. Alpha defines window's transparency.*/
		glClearColor(0.4f, 0.0f, 0.4, 1.0f);
		//            R     G     B   Alpha

		/* Swap front and back buffers. Buffers stores an array of pixels with their properties. */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	/*Ends the program and returns memory.*/
	glfwTerminate();
	return 0;
}