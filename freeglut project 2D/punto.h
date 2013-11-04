/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#ifndef PUNTO_H
#define PUNTO_H



#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class punto
{
public:

	GLdouble x;
	GLdouble y;
	//Constuctor - destructor
	punto(GLdouble newx , GLdouble newy): x(newx), y(newy){}
	punto(): x(0),y(0){}
	/* Getter setter
	GLdouble x() const;
	GLdouble y() const;
	void x(GLdouble);
	void y(GLdouble);
	*/
	punto& operator = (const punto &p);
	GLdouble distancia(punto);
	bool estaCerca(punto,GLdouble);
	punto generaVector(punto);
	GLdouble productoEscalar (punto);
	punto perpendicularDerecha();

};

#endif // !PUNTO_H
