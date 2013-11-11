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
	

	//Sobrecarga de operadores
	PV2D& operator = (const PV2D &p);
	PV2D& operator * (const GLdouble &p);
	PV2D& operator * (const PV2D &p);
	PV2D& operator + (const PV2D &p);
	PV2D& operator - (const PV2D &p);
	PV2D& operator / (const GLdouble &p);


	GLdouble distancia(const PV2D &punto);
	bool estaCerca(const PV2D&,const GLdouble&);
	PV2D generaVector(const PV2D& punto);
	//GLdouble productoEscalar (const PV2D &vector);
	
	//Operaciones con vectores
	PV2D perpendicularDerecha();
	PV2D perpendicularIzquierda();
	PV2D perpendicularDerechaNormalizado();
	PV2D perpendicularIzquierdaNormalizado();

	GLdouble productoEscalar(const PV2D &p);

	PV2D normalizarVector();
	
	GLdouble moduloVector ();


};

#endif // !PUNTO_H
