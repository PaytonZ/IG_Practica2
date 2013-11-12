#include "pelota.h"
#include <cmath>
#include <iostream>

	void pelota::pintar()
	{
		glBegin(GL_POINTS);

			glVertex2d(centro.x,centro.y);

		glEnd();


		glBegin(GL_LINE_LOOP);

		for(int i = 0; i < SEGMENTOS_CIRCULO ; i++) 

	{ 
		GLdouble theta = 2.0 * 3.1415926 * GLdouble(i) / GLdouble(SEGMENTOS_CIRCULO);//get the current angle 

		GLdouble x = radio *  GLdouble(cosf(theta));//calculate the x component 
		GLdouble y = radio *  GLdouble(sinf(theta));//calculate the y component 

		glVertex2d(x + centro.x, y + centro.y);//output vertex 

		}

		glEnd();

		/*glBegin(GL_POLYGON);
			for (int i=0; i<SEGMENTOS_CIRCULO; i++)
				glVertex2d(circulo[i]->x,circulo[i]->y);
		glEnd;*/
			
	}
	

	void pelota::rebote(PV2D* normal){

		
		direccion = direccion + *normal*2.0;
		direccion = direccion.normalizarVector();
	}