#pragma once
#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "pelota.h"
#include "PV2D.h"
class Obstaculo
{
public:
	
	virtual bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn)=0;
	virtual void pintar()=0;
	virtual void pintaNormales()=0;

};

#endif