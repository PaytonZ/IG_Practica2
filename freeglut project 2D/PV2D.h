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
	
	PV2D& operator = (const PV2D &p);
	
	GLdouble distancia(PV2D punto);
	bool estaCerca(PV2D,GLdouble);
	PV2D generaVector(PV2D punto);
	GLdouble productoEscalar (PV2D vector);
	
	PV2D perpendicularDerecha();
	PV2D perpendicularIzquierda();

	PV2D normalizarVector();

	PV2D sumaPuntoVector(PV2D vector);
	
	PV2D sumaVectores(PV2D vector);

	PV2D restaVectores( PV2D vector);

	PV2D multiplicaVectorNumero( GLint numero);

	GLdouble moduloVector ();


};

#endif // !PUNTO_H
