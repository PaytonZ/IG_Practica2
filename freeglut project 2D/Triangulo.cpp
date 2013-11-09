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
	PV2D medioXZ = PV2D((x.x+z.x) /2 , (x.y+z.y)/2)
		,medioXY = PV2D((x.x+y.x) /2 , (x.y+y.y)/2)
		,medioYZ = PV2D((y.x+z.x) /2 , (y.y+y.y)/2);

	std::cout << "MEDIOYZ" << medioXY.x << " " << medioYZ.y << std::endl;

	PV2D XZ 
		,XY = medioXY * normalXY
		,YZ;
	std::cout << "YZ" << XY.x << " " << YZ.y << std::endl;

	glBegin(GL_LINES);
		glVertex2d(medioXY.x,medioXY.y);
		glVertex2d(XY.x,XY.y);


	glEnd();
	

	
}


