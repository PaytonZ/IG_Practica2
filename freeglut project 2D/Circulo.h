#pragma once
#ifndef CIRCULO_H
#define CIRCULO_H

#include "obstaculo.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include<stdlib.h>
#include <stdio.h>

extern const GLdouble EPSILON;

class Circulo :
	public Obstaculo
{
public:
	PV2D* circulo[SEGMENTOS_CIRCULO];


	Circulo(PV2D& _c,GLdouble _radio)
	{
		c= _c;
		radio=_radio;
		
		
		
		GLdouble alfa=360.00/(GLdouble)SEGMENTOS_CIRCULO;
		GLdouble beta= (180.00-alfa)/2;
		GLdouble lado= 2*radio*cos(M_PI*beta/180.00);
		lapiz l(c,0.0);
		l.forward(radio,false);
		circulo[0]= new PV2D(l.pos.x,l.pos.y);
		l.dir=180.00-beta;
		for(int i=1; i < SEGMENTOS_CIRCULO ; i++)
		{
			l.forward(lado,false);
			l.turnTo(alfa);
			circulo[i]= new PV2D(l.pos.x,l.pos.y);
			
		}

		do {
		r=rand()%2;
		g=rand()%2;
		b=rand()%2;
		}while(r!=0 && g !=0 && b!=0);

	}
	~Circulo()
	{
		for(int i=0; i < SEGMENTOS_CIRCULO ; i++)
		{
			delete circulo[i];
		}
		
	}

	Circulo* crearCirculoMasGrande( GLdouble tamExtra);
	virtual void pintar(bool);
	virtual void pintaNormales();
	virtual bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn);

private:
	PV2D c;
	GLdouble radio;
	GLdouble r;
	GLdouble g;
	GLdouble b;
};

#endif