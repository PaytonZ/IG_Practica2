#pragma once
#include "obstaculo.h"
class Circulo :
	public Obstaculo
{
public:

	Circulo(PV2D& _c,GLdouble _radio)
	{
		c=_c;
		radio=_radio;
	}
	~Circulo(void);

	Circulo* crearCirculoMasGrande( GLdouble tamExtra);
	virtual void pintar();
	virtual void pintaNormales();
	virtual bool interseccion(pelota *p,double &tIn ,PV2D*& normalIn);

private:
	PV2D c;
	GLdouble radio;
};

