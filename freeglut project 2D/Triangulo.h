

#pragma once
#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "obstaculo.h"
#include "PV2D.h"
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include<stdlib.h>
#include <stdio.h>

extern const GLdouble EPSILON;

class Triangulo :
	public Obstaculo
{
public:
	//Anotacion
	/*        z
			  /\
			 /	\        
			/____\
		   x      y
	*/

	Triangulo(PV2D& _x,PV2D& _y,PV2D& _z): x(_x) ,y(_y) ,z(_z)
	{
		normalXY= x.generaVector(y).perpendicularDerechaNormalizado();
		normalYZ = y.generaVector(z).perpendicularDerechaNormalizado();
		normalZX = z.generaVector(x).perpendicularDerechaNormalizado();

		baricentro = (x + y + z) /3 ;


		normalCentroaX=baricentro.generaVector(x);
		normalCentroaY=baricentro.generaVector(y);
		normalCentroaZ=baricentro.generaVector(z);
		do {
		r=rand()%2;
		g=rand()%2;
		b=rand()%2;
		}while(r!=0 && g !=0 && b!=0);
	

	}
	
	
	
	PV2D x,y,z;
	PV2D normalXY,normalZX,normalYZ;
	PV2D normalCentroaX, normalCentroaY, normalCentroaZ;
	PV2D baricentro;

	Triangulo* creaTrianguloArriba(GLdouble radio);
	Triangulo* creaTrianguloAbajo(GLdouble radio);
	Triangulo* creaTrianguloDerecha(GLdouble radio);
	Triangulo* creaTrianguloDerechaInv(GLdouble radio);
	Triangulo* creaTrianguloIzquierda(GLdouble radio);
	virtual void pintar(bool);
	virtual void pintaNormales();
	virtual	bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn);
	
private:

	GLdouble r;
	GLdouble g;
	GLdouble b;
};

#endif