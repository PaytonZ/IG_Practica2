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
#include "Circulo.h"





extern int WIDTH, HEIGHT ;

extern const unsigned int timer;

class escena
{

public:

	pelota *balon;
	bool baldosas;
	Lista<Obstaculo*> lista_de_obstaculos;
	Lista<Obstaculo*> lista_de_obstaculos_pintar;
	bool penetracion;
	bool interior;
	bool debug;

	
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

	void step(int);

	void cambiarPenetracion();

	void cambiarInterior();

	void cambiarDebug();

	static void stepaux(int);
		
private:

	escena() {}
	escena(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop):
		xLeft(new_xleft) , xRight(new_xright) ,  yBot(new_yBot) , yTop(new_yTop) {
		penetracion=true;
		interior=true;
		debug=false;
		balon=new pelota();
		superior= new Triangulo(PV2D(xLeft-1000,yTop),PV2D(xRight+1000,yTop),PV2D(xRight/2,yTop+50));
		lateralIzq = new Triangulo(PV2D(xLeft-350,yTop/2),PV2D(xLeft-250,yBot-1000),PV2D(xLeft-250,yTop+1000));
		inferior = new Triangulo(PV2D(xRight/2,yBot-50),PV2D(xRight+1000,yBot),PV2D (xLeft-1000,yBot));
		lateralDch = new Triangulo(PV2D(xRight-250,yBot-1000),PV2D(xRight+350,yTop/2),PV2D(xRight-250,yTop+1000));

		PV2D x (50,10)
		,y (100,10)
		,z (70,60);

		Triangulo* obs1 = new Triangulo (x*4,y*4,z*4);
		Triangulo* obs2 = new Triangulo (PV2D (0,80), PV2D (100,300),PV2D(-100,300) );
		Triangulo* obs5= new Triangulo (PV2D (500,50), PV2D (600,170),PV2D(400,170) );


		Circulo* obs3 = new Circulo (PV2D (-100,yTop-30), 50);
		Circulo* obs4 = new Circulo (PV2D (200,yBot+300), 35);
		Circulo* obs6 = new Circulo (PV2D (xRight-350,yTop-135), 65);

		lista_de_obstaculos_pintar.ponDr(superior);
		lista_de_obstaculos_pintar.ponDr(inferior);
		lista_de_obstaculos_pintar.ponDr(lateralIzq);
		lista_de_obstaculos_pintar.ponDr(lateralDch);

		lista_de_obstaculos_pintar.ponDr(obs1);
		lista_de_obstaculos_pintar.ponDr(obs2);
		lista_de_obstaculos_pintar.ponDr(obs3);
		lista_de_obstaculos_pintar.ponDr(obs5);

		//Circulo obs4
		lista_de_obstaculos.ponDr(obs4->crearCirculoMasGrande(balon->radio));
		lista_de_obstaculos_pintar.ponDr(obs4);

		//Intersecion obs3
		lista_de_obstaculos.ponDr(obs3->crearCirculoMasGrande(balon->radio));
		lista_de_obstaculos_pintar.ponDr(obs3);

		//Intersecion obs6
		lista_de_obstaculos.ponDr(obs6->crearCirculoMasGrande(balon->radio));
		lista_de_obstaculos_pintar.ponDr(obs6);

		//Triangulos obs2
		lista_de_obstaculos.ponDr(obs2->creaTrianguloDerechaInv(balon->radio));
		lista_de_obstaculos.ponDr(obs2->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(obs2->creaTrianguloArriba(balon->radio));
		
		//lista_de_obstaculos_pintar.ponDr(obs2->creaTrianguloDerechaInv(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(obs2->creaTrianguloIzquierda(balon->radio));	
		//lista_de_obstaculos_pintar.ponDr(obs2->creaTrianguloArriba(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(new Circulo(obs2->x,balon->radio));
		//lista_de_obstaculos_pintar.ponDr(new Circulo(obs2->y,balon->radio));
		//lista_de_obstaculos_pintar.ponDr(new Circulo(obs2->z,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs2->x,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs2->y,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs2->z,balon->radio));

		//Triangulo obs5
		lista_de_obstaculos.ponDr(obs5->creaTrianguloDerechaInv(balon->radio));
		lista_de_obstaculos.ponDr(obs5->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(obs5->creaTrianguloArriba(balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs5->x,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs5->y,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs5->z,balon->radio));

		/*lista_de_obstaculos_pintar.ponDr(obs5->creaTrianguloDerechaInv(balon->radio));
		lista_de_obstaculos_pintar.ponDr(obs5->creaTrianguloIzquierda(balon->radio));	
		lista_de_obstaculos_pintar.ponDr(obs5->creaTrianguloArriba(balon->radio));
		lista_de_obstaculos_pintar.ponDr(new Circulo(obs5->x,balon->radio));
		lista_de_obstaculos_pintar.ponDr(new Circulo(obs5->y,balon->radio));
		lista_de_obstaculos_pintar.ponDr(new Circulo(obs5->z,balon->radio));*/

		//Triangulos obs1
		lista_de_obstaculos.ponDr(obs1->creaTrianguloDerecha(balon->radio));
		lista_de_obstaculos.ponDr(obs1->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(obs1->creaTrianguloAbajo(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(obs1->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(obs1->creaTrianguloIzquierda(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(obs1->creaTrianguloAbajo(balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs1->x,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs1->y,balon->radio));
		lista_de_obstaculos.ponDr(new Circulo(obs1->z,balon->radio));

		//Triangulo superior
		//lista_de_obstaculos.ponDr(superior->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos.ponDr(superior->creaTrianguloIzquierda(balon->radio));		
		lista_de_obstaculos.ponDr(superior->creaTrianguloAbajo(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(superior->creaTrianguloAbajo(balon->radio));

		// Triangulo inferior
		//lista_de_obstaculos.ponDr(inferior->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos.ponDr(inferior->creaTrianguloIzquierda(balon->radio));
		lista_de_obstaculos.ponDr(inferior->creaTrianguloArriba(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(inferior->creaTrianguloArriba(balon->radio));

		//Triangulo izquierda
		lista_de_obstaculos.ponDr(lateralIzq->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(lateralIzq->creaTrianguloDerecha(balon->radio));
		//lista_de_obstaculos.ponDr(lateralIzq->creaTrianguloArriba(balon->radio));
		//lista_de_obstaculos.ponDr(lateralIzq->creaTrianguloAbajo(balon->radio));

		//Triangulo derecha
		lista_de_obstaculos.ponDr(lateralDch->creaTrianguloIzquierda(balon->radio));
		//lista_de_obstaculos_pintar.ponDr(lateralDch->creaTrianguloIzquierda(balon->radio));
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

