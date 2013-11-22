/********************************************************************************
*																				*
*		Practica 2 IG - Pelota maligna 											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#pragma once
#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "pelota.h"
#include "PV2D.h"
class Obstaculo
{
public:
	
	virtual bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn)=0;
	virtual void pintar(bool)=0;
	virtual void pintaNormales()=0;

};

#endif