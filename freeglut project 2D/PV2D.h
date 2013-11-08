/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/
#pragma once
#ifndef PUNTO_H
#define PUNTO_H

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class PV2D
{
public:

	GLdouble x;
	GLdouble y;
	//Constuctor - destructor
	PV2D(GLdouble newx , GLdouble newy): x(newx), y(newy){}
	PV2D(): x(0),y(0){}
	/* Getter setter
	GLdouble x() const;
	GLdouble y() const;
	void x(GLdouble);
	void y(GLdouble);
	*/
	PV2D& operator = (const PV2D &p);
	
	GLdouble distancia(PV2D);
	bool estaCerca(PV2D,GLdouble);
	PV2D generaVector(PV2D);
	GLdouble productoEscalar (PV2D);
	
	PV2D perpendicularDerecha();
	PV2D perpendicularIzquierda();

	PV2D normalizarVector(PV2D vector);
	



};

#endif // !PUNTO_H
