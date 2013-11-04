/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "escena.h"
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>


extern int WIDTH, HEIGHT;
escena* escena::AVE = NULL;

GLdouble escena::getxRight() const{
	return xRight;
}
void escena::setxRight(GLdouble new_xRight){
	xRight= new_xRight;
}

GLdouble escena::getyTop() const{
	return yTop;

}

void escena::setyTop(GLdouble new_ytop){
	yTop= new_ytop;
}


GLdouble escena::getxLeft() const{
	return xLeft;
}

void escena::setxLeft(GLdouble new_xleft){

	xLeft=new_xleft;

}

GLdouble escena::getyBot() const{
	return yBot;
}

void escena::setyBot(GLdouble new_ybot )
{
	yBot=new_ybot;
}

punto escena::getCentro()
{
	return punto((xRight+xLeft)/2.0,(yTop+yBot)/2.0);
}	


void __cdecl  escena::resize(int newWidth, int newHeight){

	//Resize Viewport
	WIDTH= newWidth;
	HEIGHT= newHeight;


	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport ( 0, 0, WIDTH, HEIGHT ) ;

	escena *_AVE= getAVEInstance();

	//Resize Scene Visible Area 
	//Se actualiza el área visible de la escena
	//para que su ratio coincida con ratioViewPort

	GLdouble SVAWidth= _AVE->getxRight()- _AVE->getxLeft();

	GLdouble SVAHeight= _AVE->getyTop()-_AVE->getyBot();
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {
		// Increase SVAHeight
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( _AVE->getyBot()+_AVE->getyTop() )/2.0;
		_AVE->setyTop(( yMiddle + newHeight)/2.0);
		_AVE->setyBot ((yMiddle - newHeight)/2.0);
	}
	else {
		//Increase SVAWidth
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ((_AVE->getxLeft()+_AVE->getxRight() )/2.0);
		_AVE->setxRight((xMiddle + newWidth)/2.0);
		_AVE->setxLeft(( xMiddle - newWidth)/2.0);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluOrtho2D(_AVE->getxLeft(),_AVE->getxRight(), _AVE->getyBot(),_AVE->getyTop());

}

escena* escena::getAVEInstance()
{       
	if(!AVE) {
		AVE= new escena();
		atexit(escena::_AVE_deleter);
	}
	return AVE;
}

escena* escena::getAVEInstance(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop)
{       
	if (!AVE)

	{
		AVE=new escena(new_xleft,new_yBot, new_xright, new_yTop);
		atexit(escena::_AVE_deleter);
	}
	return AVE;
}
void escena::translacionX(GLdouble incremento){
	xLeft+=incremento;
	xRight+=incremento;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft,xRight,yBot,yTop);
}


void escena::translacionY(GLdouble incremento){
	yTop+=incremento;
	yBot+=incremento;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft,xRight,yBot,yTop);
}

void escena::escalacion(GLdouble factor){

	punto centro=getCentro();
	GLdouble nuevoancho = (xRight - xLeft) / factor;
	GLdouble nuevoalto = (yTop-yBot) / factor ;

	xRight = centro.x + nuevoancho /2.0;
	xLeft = centro.x - nuevoancho /2.0;
	yBot = centro.y - nuevoalto /2.0;
	yTop = centro.y + nuevoalto / 2.0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft,xRight,yBot,yTop);
}




void escena:: draw()
{
	
}

punto escena::dePuertodeVistaaAVE (int x ,int y )
{


	GLdouble escalaAncho= WIDTH / ( xRight - xLeft );

	GLdouble escalaAlto = HEIGHT /( yTop -yBot); 


	return punto( (x/escalaAncho) + xLeft,yTop - (y/escalaAlto)) ;
} 

void escena::escalacionProgresivo(GLdouble factor)
{
	int nIter = 40;
	GLdouble inc= (factor-1) / (GLdouble) nIter ;
	GLdouble ancho= ((xRight-xLeft));
	GLdouble alto = ((yTop-yBot));

	for(int i=0; i < nIter ; i++)
	{

		GLdouble faux = 1 + inc *i;

		GLdouble anchonew = ancho / faux;
		GLdouble altonew = alto / faux;

		punto c= getCentro();
		xLeft= c.x - anchonew / 2.0;
		xRight= c.x + anchonew / 2.0;

		yBot= c.y - altonew / 2.0;
		yTop= c.y + altonew / 2.0;


		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xLeft,xRight,yBot,yTop);

		display();

		Sleep(10);


	}
}


void escena::display()
{
	glClear( GL_COLOR_BUFFER_BIT );


	if(AVE->baldosas) AVE->embaldosar(3);
	else AVE->drawEscene();
	

	glFlush();
	glutSwapBuffers();


}


void escena::embaldosar(int nCols)
{
	GLdouble SVratio = (xRight-xLeft)/ (yTop - yBot);
	GLdouble w = (GLdouble) WIDTH / (GLdouble) nCols;
	GLdouble h = w/SVratio;

	for(GLint c=0; c < nCols ; c++ )
	{

		GLdouble currentH=0;
		while( (currentH+ h)  < HEIGHT)
		{
			glViewport((GLint) (c*w),(GLint) currentH , (GLint) w , (GLint) h);
			drawEscene();
			currentH+=h;
		}
	}
}

void escena::drawEscene()
{
	

}


void escena::activarDesActivarBaldosas(){

	if(baldosas)
	{
		baldosas=false;
		glViewport(0, 0, WIDTH, HEIGHT);
	}
	else
	{
		baldosas=true;
	}
}