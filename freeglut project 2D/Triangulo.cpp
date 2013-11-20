/********************************************************************************
*																				*
*		Practica 2 IG - Pelota maligna 											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Triangulo.h"
#include <iostream>

//Anotacion
/*        z
/\
/	\        
/____\
x      y
*/
void Triangulo::pintar()
{
	glBegin(GL_LINE_LOOP);

	glVertex2d(x.x,x.y);
	glVertex2d(y.x,y.y);
	glVertex2d(z.x,z.y);

	glEnd();

}

bool Triangulo::interseccion(pelota *p,double &tIn ,PV2D*& normalIn)
{
	//Paso 1 para cada vertice calcular
	// distancia y proyeccion sobre v y vt
	PV2D* vertices[] = { &x, &y ,&z };
	PV2D* normales[] = {&normalXY, &normalYZ, &normalZX};
	PV2D* normalCentroaP[] = { &normalCentroaX, &normalCentroaY , &normalCentroaZ } ;
	GLdouble distancia[3] , proyecion[3];
	GLdouble sumatorio=0;
	int signo[3];
	int numHits=0;
	GLdouble hit[3];
	PV2D* normalesResultado[3];



	for(int i=0; i < 3 ; i ++)
	{
		PV2D vectorPaR=p->centro.generaVector(*vertices[i]) ;
		distancia[i]= vectorPaR.productoEscalar(p->direccion.perpendicularIzquierdaNormalizado());
		proyecion[i]= vectorPaR.productoEscalar(p->direccion);  

		if(distancia[i] > EPSILON) signo[i]=1;
		else if (abs(distancia[i]) <= EPSILON ) signo[i]=0;
		else signo[i]=-1;

		sumatorio+=signo[i];

	}

	if( abs(sumatorio) == 3) return false;

	//Paso 2 para cada arista pi , ni que interseque con la recta r , calculamos
	// el instance de corte

	for(int i=0; i < 3 ; i++)
	{
		int j = (i+1)%3;
		if((signo[i]*signo[j]) < 0) 
		{
			GLdouble num  = (proyecion[i] * distancia[j]) - (distancia[i] *proyecion[j]);
			GLdouble denom = distancia[j] - distancia[i];
			hit[numHits] = num / denom;
			normalesResultado[numHits] = normales[i];
			numHits++;
		}

	}
	if (numHits < 2 )
	{
		for(int i=0; i < 3 ; i++)
		{
			if(signo[i]==0)
			{
				hit[numHits] = proyecion[i];
				normalesResultado[numHits]= normalCentroaP[i];
				numHits++;
			}
		}
	}
	//Paso 3 para cada vertice pi que este sobre la recta calculamenos el instance corte 

	double min = hit[0];
	int indicemenor=0;

	for(int i=1; i < numHits ; i++)
	{
		if(min > hit[i])
		{
			min = hit[i];
			indicemenor=i;
		}

	}

	tIn = hit[indicemenor];
	normalIn = normalesResultado [indicemenor];

	return true;

}


void Triangulo::pintaNormales()
{
	//Calculo de puntos medios
	PV2D medioZX = PV2D((z.x+x.x) /2 , (z.y+x.y)/2)
		,medioXY = PV2D((x.x+y.x) /2 , (x.y+y.y)/2)
		,medioYZ = PV2D((y.x+z.x) /2 , (y.y+z.y)/2);

	PV2D normalXY10 = normalXY * 10
		,normalZX10 = normalZX * 10
		,normalYZ10 = normalYZ * 10;

	PV2D ZX = medioZX + normalZX10
		,XY = medioXY + normalXY10
		,YZ = medioYZ + normalYZ10	;


	glBegin(GL_LINES);
	glVertex2d(medioXY.x,medioXY.y);
	glVertex2d(XY.x,XY.y);

	glVertex2d(medioZX.x,medioZX.y);
	glVertex2d(ZX.x,ZX.y);

	glVertex2d(medioYZ.x,medioYZ.y);
	glVertex2d(YZ.x,YZ.y);

	glEnd();

	glBegin(GL_POINTS);
	glVertex2d(baricentro.x,baricentro.y);
	glEnd();


}

Triangulo* Triangulo:: creaTrianguloAbajo(GLdouble radio)
{
	PV2D puntoX = PV2D(x.x,x.y-radio);
	PV2D puntoY = PV2D(y.x,y.y-radio);
	PV2D puntoZ = PV2D((x.x+y.x)/2, (x.y+y.y)/2);

	return new Triangulo(puntoX,puntoY,puntoZ);
}

Triangulo* Triangulo:: creaTrianguloDerecha(GLdouble radio)
{
	PV2D puntoX = PV2D((y.x+z.x)/2,(y.y+z.y)/2);
	PV2D puntoY = PV2D(y.x+radio,y.y);
	PV2D puntoZ = PV2D(z.x+radio,z.y);

	return new Triangulo(puntoX,puntoY,puntoZ);
}

Triangulo* Triangulo:: creaTrianguloDerechaInv(GLdouble radio)
{
	PV2D puntoX = PV2D(x.x+radio,x.y);
	PV2D puntoY = PV2D(y.x+radio,y.y);
	PV2D puntoZ = PV2D((y.x+x.x)/2,(y.y+x.y)/2);

	return new Triangulo(puntoX,puntoY,puntoZ);
}

Triangulo* Triangulo:: creaTrianguloIzquierda(GLdouble radio)
{
	PV2D puntoX = PV2D(x.x-radio,x.y);
	PV2D puntoY = PV2D((x.x+z.x)/2,(x.y+z.y)/2);
	PV2D puntoZ = PV2D(z.x-radio,z.y);

	return new Triangulo(puntoX,puntoY,puntoZ);
}



Triangulo* Triangulo:: creaTrianguloArriba(GLdouble radio)
{
	PV2D puntoX = PV2D((z.x+y.x)/2, (z.y+y.y)/2);
	PV2D puntoY = PV2D(y.x,y.y+radio);
	PV2D puntoZ = PV2D(z.x,z.y+radio);

	return new Triangulo(puntoX,puntoY,puntoZ);
}



