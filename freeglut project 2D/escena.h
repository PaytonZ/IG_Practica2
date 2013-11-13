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
	Lista<Triangulo*> lista_de_obstaculos_pintar;

	
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
		lateralIzq = new Triangulo(PV2D(xLeft-350,yTop/2),PV2D(xLeft-250,yBot-1000),PV2D(xLeft-250,yTop+1000));
		inferior = new Triangulo(PV2D(xRight/2,yBot-50),PV2D(xRight+1000,yBot),PV2D (xLeft-1000,yBot));
		lateralDch = new Triangulo(PV2D(xRight-250,yBot-1000),PV2D(xRight+350,yTop/2),PV2D(xRight-250,yTop+1000));

		PV2D x (50,50)
		,y (100,50)
		,z (70,100);

		Triangulo* obs1 = new Triangulo (x*4,y*4,z*4);
		Triangulo* obs2 = new Triangulo (PV2D (0,80), PV2D (100,300),PV2D(-100,300) );

		//lista_de_obstaculos.ponDr(superior);
		//lista_de_obstaculos_pintar.ponDr(inferior);
		//lista_de_obstaculos.ponDr(lateralIzq);
		//lista_de_obstaculos.ponDr(lateralDch);

		lista_de_obstaculos_pintar.ponDr(obs1);
		lista_de_obstaculos_pintar.ponDr(obs2);

		//Triangulos obs2
		lista_de_obstaculos.ponDr(obs2->creaTrianguloDerechaInv(balon->radio));
		lista_de_obstaculos.ponDr(obs2->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(obs2->creaTrianguloArriba(balon->radio));

		//Triangulos obs1
		lista_de_obstaculos.ponDr(obs1->creaTrianguloDerecha(balon->radio));
		lista_de_obstaculos.ponDr(obs1->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(obs1->creaTrianguloAbajo(balon->radio));

		//Triangulo superior
		//lista_de_obstaculos.ponDr(superior->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos.ponDr(superior->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(superior->creaTrianguloAbajo(balon->radio));

		// Triangulo inferior
		//lista_de_obstaculos.ponDr(inferior->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos.ponDr(inferior->creaTrianguloIzquierda(balon->radio));
		lista_de_obstaculos.ponDr(inferior->creaTrianguloArriba(balon->radio));

		//Triangulo izquierda
		lista_de_obstaculos.ponDr(lateralIzq->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos.ponDr(lateralIzq->creaTrianguloArriba(balon->radio));
		//lista_de_obstaculos.ponDr(lateralIzq->creaTrianguloAbajo(balon->radio));

		//Triangulo derecha
		lista_de_obstaculos.ponDr(lateralDch->creaTrianguloIzquierda(balon->radio));
		//lista_de_obstaculos.ponDr(lateralDch->creaTrianguloArriba(balon->radio));
		//lista_de_obstaculos.ponDr(lateralDch->creaTrianguloAbajo(balon->radio));
			
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

