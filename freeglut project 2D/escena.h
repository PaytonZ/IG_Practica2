/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/



#pragma once
#ifndef ESCENA_H
#define ESCENA_H


#include "pelota.h"
#include <Windows.h>
#include "PV2D.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Triangulo.h"
#include "Lista.h"





extern int WIDTH, HEIGHT ;



class escena
{

public:

	pelota *balon;
	bool baldosas;
	Lista<Triangulo*> lista_de_obstaculos;

	
	static escena* getAVEInstance();
	static escena* getAVEInstance(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop);

	Triangulo *superior , *lateralIzq, *lateralDch, *inferior;
		
	GLdouble getxRight() const;
	void setxRight(GLdouble);

	GLdouble getxLeft() const;
	void setxLeft(GLdouble);

	GLdouble getyTop() const;
	void  setyTop(GLdouble);

	GLdouble getyBot() const;
	void setyBot(GLdouble);

	PV2D getCentro();

	static	void  __cdecl resize(int newWidth, int newHeight);

	void translacionX(GLdouble);
	void translacionY(GLdouble);
	void escalacion(GLdouble);
	
	void draw();
		
	PV2D dePuertodeVistaaAVE(int,int);

	void escalacionProgresivo(GLdouble);

	static void display();

	void embaldosar(int);

	void drawEscene();

	void activarDesActivarBaldosas();

	void step();
		
private:

	escena() {}
	escena(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop):
		xLeft(new_xleft) , xRight(new_xright) ,  yBot(new_yBot) , yTop(new_yTop) {
		balon=new pelota();
		superior= new Triangulo(PV2D(xLeft-1000,yTop),PV2D(xRight+1000,yTop),PV2D(xRight/2,yTop+50));

		PV2D x (50,50)
		,y (100,50)
		,z (70,100);

		inferior = new Triangulo (x*4,y*4,z*4);

		lista_de_obstaculos.ponDr(superior);
		lista_de_obstaculos.ponDr(inferior);

		
			
	}

	static escena* AVE;
	static void _AVE_deleter() { 
	delete AVE; }
			
	GLdouble xLeft;
	GLdouble xRight;

	GLdouble yBot;
	GLdouble yTop;


};

#endif // !ESCENA_H

