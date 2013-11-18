#include "Circulo.h"

#include <iostream>



Circulo::~Circulo(void)
{
}

void Circulo::pintar()
{
	glBegin(GL_POINTS);

			glVertex2d(c.x,c.y);

		glEnd();


		glBegin(GL_LINE_LOOP);

		for(int i = 0; i < SEGMENTOS_CIRCULO ; i++) 

	{ 
		GLdouble theta = 2.0 * 3.1415926 * GLdouble(i) / GLdouble(SEGMENTOS_CIRCULO);//get the current angle 

		GLdouble x = radio *  GLdouble(cosf(theta));//calculate the x component 
		GLdouble y = radio *  GLdouble(sinf(theta));//calculate the y component 

		glVertex2d(x + c.x, y + c.y);//output vertex 

		}

		glEnd();
}

bool Circulo:: interseccion(pelota *p,double &tIn ,PV2D*& normalIn)
{
	GLdouble A=p->direccion.productoEscalar(p->direccion);
	PV2D CP = c.generaVector(p->centro);
	GLdouble B= 2*(CP.productoEscalar(p->direccion));
	GLdouble C= CP.productoEscalar(CP)-radio*radio;
	GLdouble disc= B*B -4*A*C;


	if (disc<0)
		return false;
	else if (disc==0)
	{
		tIn=-B/(2*A);
	}
	else 
	{
		GLdouble t1= (-B-sqrt(disc))/2*A;
		GLdouble t2= (-B+sqrt(disc))/2*A;
		if (t1>t2)
			tIn=t2;
		else
			tIn=t1;
	}

	PV2D puntoIn= p->centro + p->direccion*tIn; //Punto donde intersecan
	normalIn= new PV2D (c.generaVector(puntoIn).x,c.generaVector(puntoIn).y) ;
	return true;
}

void Circulo::pintaNormales()
{

}

Circulo* Circulo:: crearCirculoMasGrande( GLdouble tamExtra)
{
	return new Circulo (c,radio+tamExtra);
}
