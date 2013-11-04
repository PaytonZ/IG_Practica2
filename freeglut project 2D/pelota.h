
#ifndef PELOTA_H
#define PELOTA_H

const int SEGMENTOS_CIRCULO=200;

#include "punto.h"
#include "escena.h"

class pelota
{
public:

	punto centro;
	punto direccion;
	GLdouble radio;

	//punto(GLdouble newx , GLdouble newy): x(newx), y(newy){}

	/*
	pelota(){
		centro = punto(50,50);
		radio = 5;
		direccion = punto(1,0);

	}*/

	pelota(){}
	pelota(punto _centro,punto _direccion, GLdouble _radio) : centro(_centro), direccion(_direccion) , radio(_radio){}

	void pintar();
};

#endif