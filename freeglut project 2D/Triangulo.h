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
		normalXY= x.generaVector(y);
		normalXY= normalXY.perpendicularDerecha();

		std::cout << "NORMALXY EN CONSTRUCTOR!!" << normalXY.x << " " << normalXY.y << std::endl;

		normalYZ = y.generaVector(z);
		normalYZ=normalYZ.perpendicularDerecha();

		normalZX = z.generaVector(x);
		normalZX=normalZX.perpendicularDerecha();
	}
	


	PV2D x,y,z;
	PV2D normalXY,normalZX,normalYZ;
	

	void pintar();
	void pintaNormales();

};

