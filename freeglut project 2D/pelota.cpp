#include "pelota.h"
#include <cmath>

	void pelota::pintar()
	{

		glBegin(GL_LINE_LOOP);

		for(int i = 0; i < SEGMENTOS_CIRCULO ; i++) 

	{ 
		GLdouble theta = 2.0f * 3.1415926f * GLdouble(i) / GLdouble(SEGMENTOS_CIRCULO);//get the current angle 

		GLdouble x = radio * cosf(theta);//calculate the x component 
		GLdouble y = radio * sinf(theta);//calculate the y component 

		glVertex2f(x + centro.x, y + centro.y);//output vertex 

		}

		glEnd();
			
	}
	/*
	void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd(); 


}
*/

	/**float theta = 2 * 3.1415926 / float(num_segments); 
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	} 
	glEnd(); */

