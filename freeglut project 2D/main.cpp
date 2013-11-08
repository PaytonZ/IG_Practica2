/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/
#include "pelota.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <iostream>
#include "escena.h"
#include "controlador.h"



// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 1000, HEIGHT= 500;


// Scene visible area size
GLdouble xLeft= 0.0, xRight= 500.0, yBot= 0.0, yTop= 250.0;



void intitGL(){

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.50,0.40,0.05); 

	glPointSize(4.0);
	glLineWidth(2.0);

	// Viewport
	glViewport(0, 0, WIDTH, HEIGHT);

	// Model transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Scene Visible Area
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	escena *escena_principal= escena::getAVEInstance();
	gluOrtho2D(escena_principal->getxLeft(), escena_principal->getxRight(), escena_principal->getyBot(), escena_principal->getyTop()); 
}





void inicio()
{
	std::cout<< "Starting ..." << std::endl;
	std::cout << "- IG Practica 2 - Pelota Maligna :@ " << std::endl 
		<< "Los controles de esta aplicacion son los siguientes : " << std::endl
		<< "--------------------------------------"<< std::endl 
		<< "+ / -   -  Zooms de la Escena "<< std::endl
		<< "Flechas - Exploracion de la escena" << std::endl
		<< "O / P - zoom progresivo de la escena "<< std::endl
		<< "--------------------------------------"<< std::endl ;
	
}


int main(int argc, char *argv[]){


	inicio();
	
	


	//Inicializacion de mi AVE implementada con singleton
	escena::getAVEInstance(xLeft,yBot,xRight,yTop);

	int my_window; //my window's identifier

	
	//Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
	glutInit(&argc, argv);

	//Window construction
	my_window = glutCreateWindow( "IG Practica 2 - Pelota Maligna :@" );

	//Callback registration
	glutReshapeFunc(escena::resize);
	glutKeyboardFunc(controlador::key);
	glutMouseFunc(controlador::key);
	glutSpecialFunc(controlador::key);
	glutDisplayFunc(escena::display);

	//OpenGL basic setting
	intitGL();

	
	// Freeglut's main loop can be stopped executing (**)
	//while ( continue_in_main_loop )
	//  glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ) ;

	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 

	//Liberacion de punteros.
	//escena::getAVEInstance()->arbol_pitagoras->liberarArbol();

	// We would never reach this point using classic glut
	system("PAUSE"); 

	return 0;
}
