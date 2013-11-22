/********************************************************************************
*																				*
*		Practica 2 IG - Pelota maligna 											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#pragma once
#ifndef PELOTA_H
#define PELOTA_H

const int SEGMENTOS_CIRCULO=200;
const double M_PI= 3.1415926535897932384626433832795;

#include "PV2D.h"
#include "lapiz.h"
#include <cmath>
#include<stdlib.h>
#include <stdio.h>

class pelota
{
public:

	PV2D centro;
	PV2D direccion;
	GLdouble radio;
	GLdouble velocidad;
	PV2D* circulo[SEGMENTOS_CIRCULO];

	pelota(){
		centro = PV2D(50,350);
		radio = 20;
		direccion = PV2D(rand()%3,rand()%3).normalizarVector();
		velocidad = 10;
		GLdouble alfa=360.00/(GLdouble)SEGMENTOS_CIRCULO;
		GLdouble beta= (180.00-alfa)/2;
		GLdouble lado= 2*radio*cos(M_PI*beta/180.00);
		lapiz l(centro,0.0);
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
		r=rand()%240;
		g=rand()%240;
		b=rand()%240;
		}while(r==255 && g ==255  && b==255);
	}


	pelota(PV2D _centro,PV2D _direccion, GLdouble _radio) : centro(_centro), direccion(_direccion) , radio(_radio){}
	~pelota()
	{
		for(int i=0; i < SEGMENTOS_CIRCULO ; i++)
		{
			delete circulo[i];
		}
	}

	void pintar(bool);
	void rebote(PV2D* normal);
	void avanzar(const GLdouble &avance);

private:
	GLubyte r;
	GLubyte g;
	GLubyte b;

};

#endif