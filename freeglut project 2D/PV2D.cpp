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

PV2D& PV2D::operator * (const int &p)
{
	 this->x *= p;
	 this->y *= p;

	 return *this;
}

PV2D&  PV2D::operator + (const PV2D &p)
{
	this->x +=p.x;
	this->y +=p.y;

	return *this;
}
PV2D&  PV2D::operator - (const PV2D &p)
{
	this->x -=p.x;
	this->y -=p.y;

	return *this;
}

PV2D& PV2D::operator * (const PV2D &p)
{
	this->x *= p.x;
	this->y *= p.y;

	return *this;
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

GLdouble PV2D :: moduloVector()
{
	return sqrt(pow(x,2)+pow(y,2));
}

PV2D PV2D :: normalizarVector()
{
	return PV2D(*this * (1/moduloVector()));


}

PV2D PV2D:: generaVector(const PV2D &p)
{
 return PV2D (p.x-x,p.y-y);
}