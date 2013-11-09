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
	glBegin(GL_TRIANGLES);

	glVertex2d(x.x,x.y);
	glVertex2d(y.x,y.y);
	glVertex2d(z.x,z.y);

	glEnd();

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



}


