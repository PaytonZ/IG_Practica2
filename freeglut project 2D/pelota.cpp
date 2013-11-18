#include "pelota.h"
#include <cmath>
#include <iostream>

	void pelota::pintar()
	{
		glBegin(GL_POINTS);

			glVertex2d(centro.x,centro.y);

		glEnd();

		glBegin(GL_LINE_LOOP);
			for (int i=0; i<SEGMENTOS_CIRCULO; i++)
				glVertex2d(circulo[i]->x,circulo[i]->y);
		glEnd();
			
	}
	

	void pelota::rebote(PV2D* normal){

		
		direccion = direccion + *normal*2.0;
		direccion = direccion.normalizarVector();
	}

	void pelota::avanzar(const GLdouble &avance)
	{

		centro = centro + (direccion * avance);
		for(int i=0; i < SEGMENTOS_CIRCULO; i++ )
		{
			*circulo[i]= *circulo[i] + (direccion * avance);
		}
	}