/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "lapiz.h"
#include "PV2D.h"
#include <cmath>
const int M_PI = 3.1415926535897932384626433832795;




void lapiz::moveTo(PV2D p,bool draw)
{
	if(draw)
	{
		glBegin(GL_LINES);
		glVertex2d(pos.x, pos.y);
		glVertex2d(p.x, p.y);
		glEnd();
	}

	pos=p;

}


void lapiz::turnTo(GLdouble a)
{
	dir+=a;
}
void lapiz::forward(GLdouble dist,bool draw )
{
	PV2D nuevo_punto ;

	nuevo_punto.x= pos.x + dist*cos(M_PI*dir/180.0);
	nuevo_punto.y= pos.y + dist*sin(M_PI*dir/180.0);



	if(draw)
	{
		glClear( GL_COLOR_BUFFER_BIT );
		glBegin(GL_LINES);
		glVertex2d(pos.x, pos.y);
		glVertex2d(nuevo_punto.x, nuevo_punto.y);
		glEnd();
		glFlush();
		glutSwapBuffers();
	}
	pos=nuevo_punto;



}