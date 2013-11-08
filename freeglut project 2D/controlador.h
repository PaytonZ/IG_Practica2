/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


#pragma once
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class controlador
{
public:

	static void key(unsigned char, int, int);
	static void key(int, int, int);
	static void key (int,int,int,int);
	
};
#endif