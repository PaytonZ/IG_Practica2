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
	

	}
	


	PV2D x,y,z;
	PV2D normalXY,normalZX,normalYZ;
	

	void pintar();
	void pintaNormales();

};

