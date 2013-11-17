#pragma once
#include "obstaculo.h"
#include "PV2D.h"
#include <iostream>

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
	virtual void pintar();
	virtual void pintaNormales();
	virtual	bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn);
	

};

