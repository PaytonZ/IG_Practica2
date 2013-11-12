/********************************************************************************
*																				*
*		Practica 2 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#pragma once
#ifndef PELOTA_H
#define PELOTA_H

const int SEGMENTOS_CIRCULO=20;
const int M_PI= 3.1415926535897932384626433832795;

#include "PV2D.h"
#include "lapiz.h"
#include <cmath>

class pelota
{
public:

	PV2D centro;
	PV2D direccion;
	GLdouble radio;
	GLdouble velocidad;
	PV2D* circulo[SEGMENTOS_CIRCULO];

	pelota(){
		centro = PV2D(100,350);
		radio = 20;
		direccion = PV2D(1,0).normalizarVector();
		velocidad = 10;
		GLdouble alfa=360/SEGMENTOS_CIRCULO;
		GLdouble beta= (M_PI-alfa)/2;
		GLdouble lado= 2*radio*cos(beta);
		lapiz l(centro,0.0);
		l.forward(radio,false);
		l.dir=beta;
		for(int i=0; i < SEGMENTOS_CIRCULO ; i++)
		{
			l.forward(lado,false);
			l.turnTo(beta);
			circulo[i]= new PV2D(l.pos.x,l.pos.y);
			/*GLdouble angulo = (i * 2*M_PI) / SEGMENTOS_CIRCULO;
			GLdouble x= radio * cos(angulo);
			GLdouble y= radio * sin(angulo);

			l.moveTo(PV2D(centro.x+x,centro.y+y),false);

			circulo[i]= new PV2D(l.pos.x,l.pos.y);*/

		}



	}
	pelota(PV2D _centro,PV2D _direccion, GLdouble _radio) : centro(_centro), direccion(_direccion) , radio(_radio){}

	void pintar();
	//void step();
	void rebote(PV2D* normal);
	void avanzar(const GLdouble &avance);

};

#endif