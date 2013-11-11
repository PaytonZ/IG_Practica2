#pragma once
#include "pelota.h"
#include "PV2D.h"
class Obstaculo
{
public:
	
	virtual bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn)=0;

};

