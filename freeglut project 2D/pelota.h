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

const int SEGMENTOS_CIRCULO=200;

#include "PV2D.h"

class pelota
{
public:

	PV2D centro;
	PV2D direccion;
	GLdouble radio;
	GLdouble velocidad;

	//punto(GLdouble newx , GLdouble newy): x(newx), y(newy){}

	/*
	pelota(){
		centro = punto(50,50);
		radio = 5;
		direccion = punto(1,0);

	}*/

	pelota(){
		centro = PV2D(100,350);
		radio = 20;
		direccion = PV2D(1,0).normalizarVector();
		velocidad = 10;

	}
	pelota(PV2D _centro,PV2D _direccion, GLdouble _radio) : centro(_centro), direccion(_direccion) , radio(_radio){}

	void pintar();
	void step();
};

#endif