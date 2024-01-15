
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "camera.h"
#include <fstream>
#include "Point.h" // Header File For Point
#include "PrimitiveDrawer.h"
#include "Mosque.h"
#include "DomeOfThechain.h"
#include "arch.h"
#include "FLOOR.h"
#include "MOUSE.h"
#include "Model_3DS.h"



void MOUSE:: mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked)
{
    // Calculate rotation angles based on mouse position
    float rotationX = (mouseY - 520) * 0.1f;
    float rotationY = (mouseX - 520) * 0.1f;

    // Rotate when mouse moves in X-axis
    if (mouseX)
    {
        glRotated(rotationX, 1, 0, 0);
		glRotated(rotationY, 0, 1, 0);

    }

    // Rotate when left mouse button is clicked
    if (isClicked)
    {
      
       
    }

    // Rotate when right mouse button is clicked
    if (isRClicked)
    {
       
    }
}
/*
void MOUSE:: Key(bool* keys, float speed,Camera MyCamera,int px,int py,int pz,int pq,float the_time)
{
	if (keys['L'])
	{
		pq-=0.2;
		MyCamera.RotateX(-1 * speed);
	}
	if (keys['S'])
	{
		pz-=0.5;
		//MyCamera.RotateX(-1 * speed);
	}
	if (keys['W'])
	{
		pz+=0.5;
	//	MyCamera.RotateX(1 * speed);
	}
	if (keys['E'])
	{
		pq+=0.5;
		MyCamera.RotateY(-1 * speed);
	}
	if (keys['Q'])
	{
		pq-=0.5;
		MyCamera.RotateY(1 * speed);
	}
	if (keys['D'])
	{
		px-=0.5;
		//MyCamera.RotateY(-1 * speed);
	}
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
	{px+=0.5;
		//MyCamera.RotateY(1 * speed);
	}
	if (keys[VK_UP])
	{	py-=0.02;
		MyCamera.MoveForward(1 * speed);
	}
	if (keys[VK_DOWN])
	{
			py+=0.02;
		MyCamera.MoveForward(-1 * speed);
	}
	if (keys[VK_RIGHT])
	{	px-=0.02;
		MyCamera.MoveRight(1 * speed);
	}
	if (keys[VK_LEFT])
	{
			px+=0.02;
		MyCamera.MoveRight(-1 * speed);
	}
	if (keys[VK_NUMPAD6])
		pq+=0.1;
	if (keys[VK_NUMPAD1])
	{
		the_time=1;
		
	}
		if (keys[VK_NUMPAD2])
	{
		the_time=2;
		
	}
			if (keys[VK_NUMPAD3])
	{
		the_time=3;
	
	}
				if (keys[VK_NUMPAD4])
	{
		the_time=4;
	
	}
	
	
}
*/
