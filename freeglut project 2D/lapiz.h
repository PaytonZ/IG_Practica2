/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


#ifndef LAPIZ_H
#define LAPIZ_H
#include "PV2D.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
class lapiz
{
public:

	lapiz(){
		pos.x=0.0;
		pos.y=0.0;
		dir=0.0;
	}
	lapiz(PV2D p,GLdouble d): pos(p), dir(d) {}
	PV2D pos; 
	GLdouble dir;
	void moveTo(PV2D,bool);
	void turnTo(GLdouble);
	void forward(GLdouble,bool);






};


#endif // !PUNTO_H
