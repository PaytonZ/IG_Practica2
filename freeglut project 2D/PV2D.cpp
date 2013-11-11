/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include <cmath>

#include "PV2D.h"

PV2D& PV2D::operator = (const PV2D &p)
{
	if(this!=&p){ 
		this->x = p.x;
		this->y = p.y;
	}
	return *this;
}

PV2D& PV2D::operator * (const GLdouble &p)
{
	return *(new PV2D(p * this->x  ,  p* this->y));

}
PV2D&  PV2D::operator + (const PV2D &p) 
{
	return *(new PV2D( this->x + p.x ,  this->y + p.y));
}
PV2D&  PV2D::operator - (const PV2D &p)
{
	return *( new PV2D( this->x - p.x ,  this->y - p.y));
}

PV2D& PV2D::operator * (const PV2D &p)
{
	return *(new PV2D( this->x *p.x ,  this->y * p.y));
}

GLdouble PV2D::productoEscalar(const PV2D &p)
{
	return (x*p.x+y*p.y);
}

PV2D& PV2D::operator / (const GLdouble &p)
{
	return *(new PV2D ( this->x / p , this->y / p));
}


GLdouble PV2D::distancia(const PV2D &p)
{
	return sqrt(pow((x - p.x),2.0)+
		pow((y - p.y),2.0));
}


bool PV2D ::estaCerca(const PV2D &p, const GLdouble &e)
{
	GLdouble a= pow(x-p.x,2);
	GLdouble b= pow(y-p.y,2);
	GLdouble c= sqrt(a+b);
	return (c<e);


}
PV2D PV2D :: perpendicularDerecha()
{
	return PV2D (y,-x);
}

PV2D PV2D :: perpendicularIzquierda()
{
	return PV2D (-y,x);
}

PV2D PV2D :: perpendicularDerechaNormalizado()
{
	return PV2D (y,-x).normalizarVector();
}

PV2D PV2D :: perpendicularIzquierdaNormalizado()
{
	return PV2D (-y,x).normalizarVector();
}



GLdouble PV2D :: moduloVector()
{
	return sqrt(pow(x,2)+pow(y,2));
}

PV2D PV2D :: normalizarVector()
{
	return PV2D (x*(1/moduloVector()), y*(1/moduloVector()));
}

PV2D PV2D:: generaVector(const PV2D &p)
{
 return PV2D (p.x-x,p.y-y);
}