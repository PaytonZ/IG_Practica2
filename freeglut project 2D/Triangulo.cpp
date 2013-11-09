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
	PV2D medioZX = PV2D((x.x+z.x) /2 , (x.y+z.y)/2)
		,medioXY = PV2D((x.x+y.x) /2 , (x.y+y.y)/2)
		,medioYZ = PV2D((y.x+z.x) /2 , (y.y+y.y)/2);

	
	PV2D XZ 
		,XY = medioXY + normalXY*10
		,YZ;

	//std::cout << "MEDIOYZ " << medioYZ.x << " " << medioYZ.y << std::endl;
	std::cout << "MEDIOXY " << medioXY.x << " " << medioXY.y << std::endl;
	std::cout << "xy " << XY.x << " " << XY.y << std::endl;
	//std::cout << "MEDIOZX " << medioZX.x << " " << medioZX.y << std::endl;
	

	//std::cout << "Normal XY " << normalXY.x  << " " << normalXY.y << std::endl;
	std::cout << "Punto XY " << XY.x << " " << XY.y << std::endl;

	glBegin(GL_POINTS);
		glVertex2d(medioXY.x,medioXY.y);
		glVertex2d(XY.x,XY.y);


	glEnd();
	

	
}


