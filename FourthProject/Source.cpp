
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
#include "SKYBOX.h"
#include "Model_3DS.h"
#include "Sound.h"
#include <glut.h>

// كريم خالد المصفي 

//محمد وفا الطويل 

//كريم شرف

//احمد زيتون 

//ماسة بيرقدار


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
DirectSoundBuffer Sound;
DirectSoundManager SoundManager;


DirectSoundBuffer Sound1;
DirectSoundManager SoundManager1;
DirectSoundBuffer Sound2;
DirectSoundManager SoundManager2;
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

Camera MyCamera;
//
int  image, image2,dome,under_dome;
double x=0;
	double y=0;
	double z=0;

	
float ch=0;


GLfloat lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat MatShn[] = { 128.0f };

float px=0,py=0.0,pz=0.0f,pa=1.0;
bool first_person=false;
// skybox
int SKYFRONT1, SKYBACK1, SKYLEFT1, SKYRIGHT1, SKYUP1, SKYDOWN1,ball, tmosque;;
int SKYFRONT2, SKYBACK2, SKYLEFT2, SKYRIGHT2, SKYUP2;
int SKYFRONT3, SKYBACK3, SKYLEFT3, SKYRIGHT3, SKYUP3;
int SKYFRONT4, SKYBACK4, SKYLEFT4, SKYRIGHT4, SKYUP4;
int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;
Model_3DS man,man2,tree,bird,rock,fence,fence2,luster,car;
float the_time=1;
float xx=0,yy=0,zz=0,pq=0;
void models(Model_3DS tree)
{
	tree.Draw();

		glPushMatrix();
glTranslated(240,0,0);
tree.Draw();
glPopMatrix();

	glPushMatrix();
glTranslated(280,0,0);
tree.Draw();
glPopMatrix();
/*
	glPushMatrix();
glTranslated(280,0,-120);
tree.Draw();
glPopMatrix();

*/

	glPushMatrix();
glTranslated(280,0,-480);
tree.Draw();
glPopMatrix();


	glPushMatrix();
glTranslated(280,0,-700);
tree.Draw();
glPopMatrix();


	glPushMatrix();
glTranslated(280,0,-900);
tree.Draw();
glPopMatrix();


//move right
	glPushMatrix();
glTranslated(680,0,-900);
tree.Draw();
glPopMatrix();




	glPushMatrix();
glTranslated(0,0,-960);
tree.Draw();
glPopMatrix();


/*
	glPushMatrix();
glTranslated(-280,0,-920);
tree.Draw();
glPopMatrix();
*/
	glPushMatrix();
glTranslated(-380,0,-920);
tree.Draw();
glPopMatrix();


	glPushMatrix();
glTranslated(-480,0,-920);
tree.Draw();
glPopMatrix();



//back back

	glPushMatrix();
glTranslated(-290,0,-1200);
tree.Draw();
glPopMatrix();
/*
	glPushMatrix();
glTranslated(-390,0,-1200);
tree.Draw();
glPopMatrix();
*/

	glPushMatrix();
glTranslated(-490,0,-1200);
tree.Draw();
glPopMatrix();


//right back



	glPushMatrix();
glTranslated(0,0,-1200);
tree.Draw();
glPopMatrix();

/*
	glPushMatrix();
glTranslated(200,0,-1200);
tree.Draw();
glPopMatrix();

*/
	glPushMatrix();
glTranslated(300,0,-1200);
tree.Draw();
glPopMatrix();
/*
	glPushMatrix();
glTranslated(400,0,-1200);
tree.Draw();
glPopMatrix();
*/


//under triangle
	glPushMatrix();
glTranslated(980,0,-900);
tree.Draw();
glPopMatrix();
/*
	glPushMatrix();
glTranslated(1080,0,-900);
tree.Draw();
glPopMatrix();

	glPushMatrix();
glTranslated(1080,0,-850);
tree.Draw();
glPopMatrix();
*/
	glPushMatrix();
glTranslated(1080,0,-800);
tree.Draw();
glPopMatrix();
//middle garden
	glPushMatrix();
glTranslated(500,0,-60);
tree.Draw();
glPopMatrix();
/*
	glPushMatrix();
glTranslated(500,0,-180);
tree.Draw();
glPopMatrix();
*/
	glPushMatrix();
glTranslated(500,0,-300);
tree.Draw();
glPopMatrix();


/*
	glPushMatrix();
glTranslated(500,0,-540);
tree.Draw();
glPopMatrix();
*/
	glPushMatrix();
glTranslated(500,0,-640);
tree.Draw();
glPopMatrix();

	rock.Draw();

	
	fence.Draw();

	glPushMatrix();
	glTranslated(45,0,0);

	fence.Draw();
	glPopMatrix();

		glPushMatrix();
	glTranslated(72,0,-17);
	
	fence2.Draw();
	glPopMatrix();

		glPushMatrix();
	glTranslated(72,0,-53);
	
	fence2.Draw();
	glPopMatrix();


		glPushMatrix();
	glTranslated(72,0,-93);
	
	fence2.Draw();
	glPopMatrix();


	glPushMatrix();

	glTranslated(0,0,-120);
	
	
	fence.Draw();
	glPopMatrix();

	fence.Draw();

	glPushMatrix();
	glTranslated(45,0,-120);

	fence.Draw();
	glPopMatrix();

		glPushMatrix();
	glTranslated(-19,0,-17);
	
	fence2.Draw();
	glPopMatrix();

		glPushMatrix();
	glTranslated(-19,0,-53);
	
	fence2.Draw();
	glPopMatrix();


		glPushMatrix();
	glTranslated(-19,0,-93);
	
	fence2.Draw();
	glPopMatrix();

						glPushMatrix();
	glTranslated(212,0,800);
	
	luster.Draw();
	glPopMatrix();



	
					glPushMatrix();
	glTranslated(212,0,600);
	
	luster.Draw();
	glPopMatrix();


	
					glPushMatrix();
	glTranslated(212,0,400);
	
	luster.Draw();
	glPopMatrix();


	
	


					glPushMatrix();
	glTranslated(212,0,200);
	
	luster.Draw();
	glPopMatrix();

	
    float objectX = 1000 + 45 * cos(360);
	glPushMatrix();
   
	bird.pos.x+=objectX*0.003;
bird.Draw();
glPopMatrix();


//glPushMatrix();
//glTranslated(240,0,0);
//tree.Draw();
//glPopMatrix();

	glPushMatrix();
glTranslated(-550,0,0);
tree.Draw();
glPopMatrix();



glPushMatrix();
glTranslated(-570,0,-200);
tree.Draw();
glPopMatrix();

glPushMatrix();
glTranslated(-570,0,-650);
tree.Draw();
glPopMatrix();

		glPushMatrix();
glTranslated(1000,0,1340);
tree.Draw();
glPopMatrix();
	
		glPushMatrix();
glTranslated(950,0,1540);
tree.Draw();
glPopMatrix();
	
			glPushMatrix();
glTranslated(900,0,1740);
tree.Draw();
glPopMatrix();
	
	


}
bool walk=false,walk_backward=false;
bool colid()
{
		
						//||MyCamera.Position.x>=1450&&MyCamera.Position.x<=1650&&MyCamera.Position.z>=1999&&MyCamera.Position.z<=2010

	//qibli colide
	if(MyCamera.Position.x<=1585&&MyCamera.Position.x>=1579.9&&MyCamera.Position.z>=2940&&MyCamera.Position.z<=4000||MyCamera.Position.x<=1055&&MyCamera.Position.x>=1049.9&&MyCamera.Position.z>=2940&&MyCamera.Position.z<=4000||MyCamera.Position.x<=1300&&MyCamera.Position.x>=1050&&MyCamera.Position.z>=2989.2&&MyCamera.Position.z<=3013||MyCamera.Position.x<=1580&&MyCamera.Position.x>=1330&&MyCamera.Position.z>=2989.2&&MyCamera.Position.z<=3013||MyCamera.Position.x<=1580&&MyCamera.Position.x>=1050&&MyCamera.Position.z>=3979.2&&MyCamera.Position.z<=4000||MyCamera.Position.x<=1400&&MyCamera.Position.x>=1350&&MyCamera.Position.z>=1790&&MyCamera.Position.z<=1810||MyCamera.Position.x<=1460&&MyCamera.Position.x>=1410&&MyCamera.Position.z>=1790&&MyCamera.Position.z<=1810||MyCamera.Position.x<=1400&&MyCamera.Position.x>=1350&&MyCamera.Position.z>=1535&&MyCamera.Position.z<=1545||MyCamera.Position.x<=1460&&MyCamera.Position.x>=1410&&MyCamera.Position.z>=1535&&MyCamera.Position.z<=1545||MyCamera.Position.x<=1470&&MyCamera.Position.x>=1460&&MyCamera.Position.z>=1803&&MyCamera.Position.z<=1805||MyCamera.Position.x<=1480&&MyCamera.Position.x>=1470&&MyCamera.Position.z>=1798&&MyCamera.Position.z<=1800||MyCamera.Position.x<=1490&&MyCamera.Position.x>=1480&&MyCamera.Position.z>=1787&&MyCamera.Position.z<=1790||MyCamera.Position.x<=1500&&MyCamera.Position.x>=1490&&MyCamera.Position.z>=1778&&MyCamera.Position.z<=1780||MyCamera.Position.x<=1510&&MyCamera.Position.x>=1500&&MyCamera.Position.z>=1768&&MyCamera.Position.z<=1770||MyCamera.Position.x<=1520&&MyCamera.Position.x>=1510&&MyCamera.Position.z>=1758&&MyCamera.Position.z<=1760||MyCamera.Position.x<=1530&&MyCamera.Position.x>=1520&&MyCamera.Position.z>=1748&&MyCamera.Position.z<=1750||MyCamera.Position.x<=1540&&MyCamera.Position.x>=1530&&MyCamera.Position.z>=1738&&MyCamera.Position.z<=1740||MyCamera.Position.x<=1540&&MyCamera.Position.x>=1535&&MyCamera.Position.z>=1680&&MyCamera.Position.z<=1740||MyCamera.Position.x<=1540&&MyCamera.Position.x>=1535&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1670||MyCamera.Position.x<=1275&&MyCamera.Position.x>=1270&&MyCamera.Position.z>=1680&&MyCamera.Position.z<=1740||MyCamera.Position.x<=1275&&MyCamera.Position.x>=1270&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1670	||MyCamera.Position.x<=1350&&MyCamera.Position.x>=1340&&MyCamera.Position.z>=1803&&MyCamera.Position.z<=1805||MyCamera.Position.x<=1340&&MyCamera.Position.x>=1330&&MyCamera.Position.z>=1798&&MyCamera.Position.z<=1800||MyCamera.Position.x<=1330&&MyCamera.Position.x>=1320&&MyCamera.Position.z>=1787&&MyCamera.Position.z<=1790||MyCamera.Position.x<=1320&&MyCamera.Position.x>=1310&&MyCamera.Position.z>=1778&&MyCamera.Position.z<=1780||MyCamera.Position.x<=1310&&MyCamera.Position.x>=1300&&MyCamera.Position.z>=1768&&MyCamera.Position.z<=1770||MyCamera.Position.x<=1300&&MyCamera.Position.x>=1290&&MyCamera.Position.z>=1758&&MyCamera.Position.z<=1760||MyCamera.Position.x<=1290&&MyCamera.Position.x>=1280&&MyCamera.Position.z>=1748&&MyCamera.Position.z<=1750||MyCamera.Position.x<=1280&&MyCamera.Position.x>=1270&&MyCamera.Position.z>=1738&&MyCamera.Position.z<=1740		||MyCamera.Position.x<=1300&&MyCamera.Position.x>=1280&&MyCamera.Position.z>=1610&&MyCamera.Position.z<=1620||MyCamera.Position.x<=1290&&MyCamera.Position.x>=1270&&MyCamera.Position.z>=1600&&MyCamera.Position.z<=1610||MyCamera.Position.x<=1300&&MyCamera.Position.x>=1280&&MyCamera.Position.z>=1590&&MyCamera.Position.z<=1600||MyCamera.Position.x<=1310&&MyCamera.Position.x>=1290&&MyCamera.Position.z>=1580&&MyCamera.Position.z<=1590||MyCamera.Position.x<=1320&&MyCamera.Position.x>=1300&&MyCamera.Position.z>=1570&&MyCamera.Position.z<=1580||MyCamera.Position.x<=1330&&MyCamera.Position.x>=1310&&MyCamera.Position.z>=1560&&MyCamera.Position.z<=1570||MyCamera.Position.x<=1340&&MyCamera.Position.x>=1320&&MyCamera.Position.z>=1550&&MyCamera.Position.z<=1560||MyCamera.Position.x<=1350&&MyCamera.Position.x>=1330&&MyCamera.Position.z>=1540&&MyCamera.Position.z<=1550||MyCamera.Position.x<=1350&&MyCamera.Position.x>=1330&&MyCamera.Position.z>=1530&&MyCamera.Position.z<=1540||MyCamera.Position.x<=1360&&MyCamera.Position.x>=1340&&MyCamera.Position.z>=1520&&MyCamera.Position.z<=1530||MyCamera.Position.x<=1540&&MyCamera.Position.x>=1530&&MyCamera.Position.z>=1610&&MyCamera.Position.z<=1620||MyCamera.Position.x<=1530&&MyCamera.Position.x>=1520&&MyCamera.Position.z>=1600&&MyCamera.Position.z<=1610||MyCamera.Position.x<=1520&&MyCamera.Position.x>=1510&&MyCamera.Position.z>=1590&&MyCamera.Position.z<=1600||MyCamera.Position.x<=1510&&MyCamera.Position.x>=1500&&MyCamera.Position.z>=1580&&MyCamera.Position.z<=1590||MyCamera.Position.x<=1500&&MyCamera.Position.x>=1490&&MyCamera.Position.z>=1570&&MyCamera.Position.z<=1580||MyCamera.Position.x<=1490&&MyCamera.Position.x>=1480&&MyCamera.Position.z>=1560&&MyCamera.Position.z<=1570||MyCamera.Position.x<=1480&&MyCamera.Position.x>=1470&&MyCamera.Position.z>=1550&&MyCamera.Position.z<=1560||MyCamera.Position.x<=1470&&MyCamera.Position.x>=1460&&MyCamera.Position.z>=1540&&MyCamera.Position.z<=1550||MyCamera.Position.x<=1460&&MyCamera.Position.x>=1450&&MyCamera.Position.z>=1530&&MyCamera.Position.z<=1540||MyCamera.Position.x<=1450&&MyCamera.Position.x>=1440&&MyCamera.Position.z>=1520&&MyCamera.Position.z<=1530||MyCamera.Position.x<=2800&&MyCamera.Position.x>=500&&MyCamera.Position.z>=528&&MyCamera.Position.z<=530||MyCamera.Position.x<=530&&MyCamera.Position.x>=528&&MyCamera.Position.z>=500&&MyCamera.Position.z<=4000||MyCamera.Position.x<=2800&&MyCamera.Position.x>=2780&&MyCamera.Position.z>=500&&MyCamera.Position.z<=4000||MyCamera.Position.x<=2800&&MyCamera.Position.x>=500&&MyCamera.Position.z>=3980&&MyCamera.Position.z<=4000||MyCamera.Position.x>=950&&MyCamera.Position.x<=1350&&MyCamera.Position.z>=1999&&MyCamera.Position.z<=2010||MyCamera.Position.x>=1450&&MyCamera.Position.x<=1650&&MyCamera.Position.z>=1999&&MyCamera.Position.z<=2010)
	return true;
	else
		return false;
}
void Key(bool* keys, float speed)
{
	if (keys['L'])
	{
		pq-=0.2;
		MyCamera.RotateX(-1 * speed);
	}
	if (keys[VK_TAB])
	{
		Sound2.Play(0);
		if(pz>-90)
		pz-=0.9;
		
		//MyCamera.RotateX(-1 * speed);
	}
	if (keys[VK_CONTROL])
	{
	Sound2.Play(0);
	if(pz<90)
			pz+=0.9;
		
		//MyCamera.RotateX(-1 * speed);
	}

		if (keys['S']&&keys[VK_SHIFT])
	{
	
		
			if (MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1900&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1800&&MyCamera.Position.z<=2080||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1895&&MyCamera.Position.z<=1995||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1200&&MyCamera.Position.z<=1300	||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||	MyCamera.Position.x>=1760&&MyCamera.Position.x<=1860&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720)
			{
				MyCamera.MoveForward(-1 * speed*0.1);
				MyCamera.MoveUpward(-1 * speed*0.26);
			
			}
			
		MyCamera.MoveForward(-1 * speed-2);

	}
		if (keys['W']&&keys[VK_SHIFT])
	{
	
		
			if (MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1900&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1800&&MyCamera.Position.z<=2080||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1895&&MyCamera.Position.z<=1995||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1200&&MyCamera.Position.z<=1300	||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||	MyCamera.Position.x>=1760&&MyCamera.Position.x<=1860&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720)
			{
				MyCamera.MoveForward(1 * speed*0.1);
				MyCamera.MoveUpward(1 * speed*0.26);
			
			}
			
		MyCamera.MoveForward(1 * speed+3);

	}
	if (keys['W'])
	{
		bool t=colid();
	
		if(t==false)
		{
			if (MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1900&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1800&&MyCamera.Position.z<=2080||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1895&&MyCamera.Position.z<=1995||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1200&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1200&&MyCamera.Position.z<=1300	||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||	MyCamera.Position.x>=1760&&MyCamera.Position.x<=1860&&MyCamera.Position.y<=1012&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720)
			{
				MyCamera.MoveForward(1 * speed*0.4);
				MyCamera.MoveUpward(1 * speed*0.86);
			
			}
			if(walk==false)
			{

				

					//||MyCamera.Position.x>=940&&MyCamera.Position.x<=1000&&MyCamera.Position.z>=1380&&MyCamera.Position.z<=2080
	

				if(MyCamera.Position.x>=1000&&MyCamera.Position.x<=1345&&MyCamera.Position.z>=2010&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1450&&MyCamera.Position.x<=1650&&MyCamera.Position.z>=2010&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1750&&MyCamera.Position.x<=1850&&MyCamera.Position.z>=2010&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1800&&MyCamera.Position.x<=1850&&MyCamera.Position.z>=1750&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1800&&MyCamera.Position.x<=1850&&MyCamera.Position.z>=1250&&MyCamera.Position.z<=1635||MyCamera.Position.x>=1950&&MyCamera.Position.x<=2150&&MyCamera.Position.z>=1300&&MyCamera.Position.z<=2080||MyCamera.Position.x>=2280&&MyCamera.Position.x<=2800&&MyCamera.Position.z>=1400&&MyCamera.Position.z<=2150||MyCamera.Position.x>=1000&&MyCamera.Position.x<=1345&&MyCamera.Position.z>=1000&&MyCamera.Position.z<=1280||MyCamera.Position.x>=1450&&MyCamera.Position.x<=1645&&MyCamera.Position.z>=1000&&MyCamera.Position.z<=1250||MyCamera.Position.x>=1750&&MyCamera.Position.x<=2200&&MyCamera.Position.z>=1000&&MyCamera.Position.z<=1250				||MyCamera.Position.x>=940&&MyCamera.Position.x<=1000&&MyCamera.Position.z>=2010&&MyCamera.Position.z<=2080||MyCamera.Position.x>=940&&MyCamera.Position.x<=1000&&MyCamera.Position.z>=1730&&MyCamera.Position.z<=1910||MyCamera.Position.x>=940&&MyCamera.Position.x<=1000&&MyCamera.Position.z>=1350&&MyCamera.Position.z<=1630
){
			
			Sound1.Play(0);
			MyCamera.MoveForward(1 * speed);
		walk=true;
			}
			else
			{
		Sound.Play(0);
			MyCamera.MoveForward(1 * speed);
		walk=true;
			}
			}
			else
			{
				
	
				
		MyCamera.MoveForward(1 * speed);
		walk=false;
			}
	}
	}
	if (keys['S'])
	{
			
			if (MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y>=995&&MyCamera.Position.z>=2000&&MyCamera.Position.z<=2080||MyCamera.Position.x>=1345&&MyCamera.Position.x<=1450&&MyCamera.Position.y>=995&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y>=995&&MyCamera.Position.z>=2000&&MyCamera.Position.z<=2080||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1020&&MyCamera.Position.y>=995&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1020&&MyCamera.Position.y>=995&&MyCamera.Position.z>=1895&&MyCamera.Position.z<=1995||	MyCamera.Position.x>=940&&MyCamera.Position.x<=1020&&MyCamera.Position.y>=995&&MyCamera.Position.z>=1200&&MyCamera.Position.z<=1300	||MyCamera.Position.x>=1650&&MyCamera.Position.x<=1750&&MyCamera.Position.y>=995&&MyCamera.Position.z>=1140&&MyCamera.Position.z<=1240||	MyCamera.Position.x>=1760&&MyCamera.Position.x<=1860&&MyCamera.Position.y>=995&&MyCamera.Position.z>=1620&&MyCamera.Position.z<=1720)
			{
				MyCamera.MoveForward(-1 * speed*0.1);
				MyCamera.MoveUpward(-1 * speed*0.26);
			
			}
				if(walk_backward==false)
			{
			
			Sound1.Play(0);
	MyCamera.MoveForward(-1 * speed);
	walk_backward=true;
				}
				else
				{
						MyCamera.MoveForward(-1 * speed);
						walk=false;
				}
	}
	if (keys['E'])
	{
		
		pq+=0.01;
		MyCamera.RotateY(-1 * speed-2);
	}
	if (keys['Q'])
	{
		
		pq-=0.01;
		MyCamera.RotateY(1 * speed+2);
	}
	if (keys['D'])
	{
		MyCamera.MoveRight(1 * speed+1);
		
	}
	
	if (keys['A'])
	{
		MyCamera.MoveRight(-1 * speed-1);
		//px+=0.5;
		//MyCamera.RotateY(1 * speed);
	}
	if (keys['F'])
	{
		first_person=!first_person;
		if(first_person==true)
		{
			MyCamera.Position.z-=50;
			MyCamera.Position.y-=0.5;
			man.visible=false;
		}
		
		if(first_person==false)
		{
			MyCamera.Position.z+=50;
			MyCamera.Position.y+=0.5;
			man.visible=true;
		}

	}
	if (keys[VK_UP])
	{		MyCamera.MoveUpward(1 * speed*0.9);
	}
	if (keys[VK_DOWN])
	{
			MyCamera.MoveUpward(-1 * speed*0.9);
	}
	if (keys[VK_RIGHT])
	{	px-=0.02;
		//MyCamera.MoveRight(1 * speed);
	}
	if (keys[VK_LEFT])
	{
			px+=0.02;
		//MyCamera.MoveRight(-1 * speed);
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

int image3;
float adada_distance;
//THIS FUNCTION STARTS WITH DRAWING THE ROOF  
int library_book, library_sides,flag,flag2,school_door,home7,home6,home5,home4,home3,home2,home1,KS2;
GLTexture head,hair,upper,shoes,eye,hand,buckle,lower,beard,accesories,tree_cane,tree_paper,bird_wave,rock_texture,fence_texture,fence2_texture,luster_texture,car_texture;
int floor_wall_texture,garden,qibli_door,carpet,left_wall,cylinder3,qibli_roof_texture,qibli_wall_texture,qibli_inside_wall_texture,quran2,qibli_above_door_texture,qibli_window;
int window,door,mosque_body,cylinder2,the_floor,quran,roof,cylinder,wood_window,under_gold_dome,wood,wood2,triangle_abs_texture,dome_of_the_chian_roof,cupola_of_the_chain_dome,row_bottom_face,cupola_of_the_chain_cylinder;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{




	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations


	glEnable(GL_TEXTURE_2D);
		garden=LoadTexture("grass.bmp", 255);
	floor_wall_texture=LoadTexture("floor_wall.bmp", 255);
	the_floor = LoadTexture("floor.bmp", 255);


row_bottom_face=LoadTexture("triangle_abs_texture2.bmp", 255);


	cupola_of_the_chain_dome=LoadTexture("qibli_dome2.bmp", 255);
	dome_of_the_chian_roof= LoadTexture("dome_of_the_chian_roof.bmp", 255);
	cupola_of_the_chain_cylinder=LoadTexture("cylinder11.bmp", 255);
	triangle_abs_texture= LoadTexture("triangle_abs_texture6.bmp", 255);
	wood2= LoadTexture("wood2.bmp", 255);
	wood= LoadTexture("wood.bmp", 255);
	wood_window= LoadTexture("wood_window_jpg.bmp", 255);
	cylinder= LoadTexture("red_cylinder.bmp", 255);
	cylinder2= LoadTexture("cylinder9.bmp", 255);
	cylinder3= LoadTexture("cylinder11.bmp", 255);
	school_door=LoadTexture("school_door.bmp", 255);


	door= LoadTexture("rdoor.bmp", 255);
	window= LoadTexture("window.bmp", 255);
	under_dome= LoadTexture("the_under.bmp", 255);
	under_gold_dome= LoadTexture("new_under_dome.bmp", 255);
	tmosque = LoadTexture("mosque.bmp", 255);
	dome = LoadTexture("gold6.bmp", 255);

	mosque_body = LoadTexture("wall2.bmp", 255);
	
	quran = LoadTexture("quran.bmp", 255);
	quran2 = LoadTexture("quran2.bmp", 255);
		roof = LoadTexture("roof.bmp", 255);

		carpet=LoadTexture("carpet2.bmp", 255);
		
		left_wall=LoadTexture("left_wall.bmp", 255);
		qibli_door=LoadTexture("qibli_door3.bmp", 255);
		qibli_roof_texture=LoadTexture("under.bmp", 255);
		qibli_wall_texture=LoadTexture("qibli_wall_texture2.bmp", 255);
    	qibli_inside_wall_texture=LoadTexture("qibli_wall_texture2.bmp", 255);
		qibli_above_door_texture=LoadTexture("qibli_above_door2.bmp", 255);
		qibli_window=LoadTexture("qibli_window.bmp", 255);
		library_book=LoadTexture("book.bmp", 255);
		library_sides=LoadTexture("wood.bmp", 255);
		flag=LoadTexture("flag.bmp", 255);
		flag2=LoadTexture("flag2.bmp", 255);
	// skybox
		
	SKYFRONT1 = LoadTexture("pzday.bmp", 255);
	SKYBACK1 = LoadTexture("nzday.bmp", 255);
	SKYLEFT1 = LoadTexture("nxday.bmp", 255);
	SKYRIGHT1 = LoadTexture("pxday.bmp", 255);
	SKYUP1 = LoadTexture("pyday.bmp", 255);

		SKYFRONT2 = LoadTexture("pzpurble.bmp", 255);
	SKYBACK2 = LoadTexture("nzpurble.bmp", 255);
	SKYLEFT2 = LoadTexture("nxpurble.bmp", 255);
	SKYRIGHT2 = LoadTexture("pxpurble.bmp", 255);
	SKYUP2 = LoadTexture("pypurble.bmp", 255);

	SKYFRONT3 = LoadTexture("pzsunset.bmp", 255);
	SKYBACK3 = LoadTexture("nzsunset.bmp", 255);
	SKYLEFT3 = LoadTexture("nxsunset.bmp", 255);
	SKYRIGHT3 = LoadTexture("pxsunset.bmp", 255);
	SKYUP3 = LoadTexture("pysunset.bmp", 255);


	SKYFRONT4 = LoadTexture("night2.bmp", 255);
	SKYBACK4 = LoadTexture("night2.bmp", 255);
	SKYLEFT4 = LoadTexture("night2.bmp", 255);
	SKYRIGHT4 = LoadTexture("night2.bmp", 255);
	SKYUP4 = LoadTexture("night2.bmp", 255);
	

	home1=LoadTexture("home1.bmp", 255);
  home2=LoadTexture("home2.bmp", 255);
  home3=LoadTexture("home3.bmp", 255);
  home4=LoadTexture("home4.bmp", 255);
  home5=LoadTexture("home5.bmp", 255);
  home6=LoadTexture("home6.bmp", 255);
  home7=LoadTexture("home7.bmp", 255);
  KS2=LoadTexture("KS2.bmp", 255);

	// note if you load a image the opengl while on the GL_Texture_2D himself
	glDisable(GL_TEXTURE_2D);
	

		
		car=Model_3DS();
	char ca[]="Zil130.3DS";
	car.Load(ca);
	car_texture.LoadBMP("cupola_of_the_chain_dome2.bmp");
	car.Materials[0].tex=car_texture;
car.Materials[1].tex=car_texture;
car.Materials[2].tex=car_texture;
car.Materials[3].tex=car_texture;
car.Materials[4].tex=car_texture;

car.Materials[5].tex=car_texture;
car.Materials[6].tex=car_texture;
car.Materials[7].tex=car_texture;
car.Materials[8].tex=car_texture;
car.Materials[9].tex=car_texture;

car.Materials[10].tex=car_texture;
car.Materials[11].tex=car_texture;
car.Materials[12].tex=car_texture;
car.Materials[13].tex=car_texture;
car.Materials[14].tex=car_texture;


	car.Materials[15].tex=car_texture;
car.Materials[16].tex=car_texture;
car.Materials[17].tex=car_texture;
car.Materials[18].tex=car_texture;
car.Materials[19].tex=car_texture;

car.Materials[20].tex=car_texture;
car.Materials[21].tex=car_texture;
car.Materials[22].tex=car_texture;
car.Materials[23].tex=car_texture;
car.Materials[24].tex=car_texture;

car.Materials[25].tex=car_texture;
car.Materials[26].tex=car_texture;
car.Materials[27].tex=car_texture;
car.Materials[28].tex=car_texture;
car.Materials[29].tex=car_texture;


	car.Materials[30].tex=car_texture;
car.Materials[31].tex=car_texture;
car.Materials[32].tex=car_texture;
car.Materials[33].tex=car_texture;
car.Materials[34].tex=car_texture;

car.Materials[35].tex=car_texture;
car.Materials[36].tex=car_texture;
car.Materials[37].tex=car_texture;
car.Materials[38].tex=car_texture;
car.Materials[39].tex=car_texture;

car.Materials[40].tex=car_texture;
car.Materials[41].tex=car_texture;
car.Materials[42].tex=car_texture;
car.Materials[43].tex=car_texture;
car.Materials[44].tex=car_texture;
	car.pos.x=2887;

	car.pos.y=985;

	car.pos.z=2915;
	car.scale=10;
	car.rot.y=90;
	
		luster=Model_3DS();
	char lus[]="luster.3DS";
	luster.Load(lus);
	luster_texture.LoadBMP("gold.bmp");
	luster.Materials[0].tex=luster_texture;

	luster.pos.x=1102;

	luster.pos.y=1080;

	luster.pos.z=3100;
	luster.scale=3;
	

		fence=Model_3DS();
	char fen[]="fence.3DS";
	fence.Load(fen);
	fence_texture.LoadBMP("rock2better.bmp");
	fence.Materials[0].tex=fence_texture;

	fence.pos.x=1380;

	fence.pos.y=1000;

	fence.pos.z=1740;
	fence.scale=0.1;

		fence2=Model_3DS();
	char fen2[]="fence.3DS";
	fence2.Load(fen2);
	fence2_texture.LoadBMP("rock2better.bmp");
	fence2.Materials[0].tex=fence_texture;

	fence2.pos.x=1380;

	fence2.pos.y=1000;

	fence2.pos.z=1740;
	fence2.rot.y=90;
	fence2.scale=0.1;
		rock=Model_3DS();
	char r[]="Rock07-Base.3DS";
	rock.Load(r);
	rock_texture.LoadBMP("rock2better.bmp");
	rock.Materials[0].tex=rock_texture;

	rock.pos.x=1410;

	rock.pos.y=995;

	rock.pos.z=1680;
	rock.scale=1;
	//switched to plane
	bird=Model_3DS();
		char b[]="An225.3DS";
	bird.Load(b);
	bird_wave.LoadBMP("wave.bmp");
	bird.Materials[0].tex=bird_wave;
bird.pos.x=-2500;
//5000
	bird.pos.y=4000;
	bird.pos.z=1850;

	bird.scale=2.5;
	bird.rot.x=90;
	bird.rot.z=180;
	tree=Model_3DS();
		char t[]="Tree1.3DS";
	tree.Load(t);
	tree_cane.LoadBMP("bark_loo.bmp");
tree_paper.LoadBMP("blatt1.bmp");
tree.pos.x=1550;
	tree.pos.y=982;
	tree.pos.z=2040;
tree.rot.y=180;
	tree.scale=15;
	tree.Materials[0].tex=tree_cane;
		tree.Materials[1].tex=tree_cane;
		tree.Materials[2].tex=tree_cane;
		tree.Materials[3].tex=tree_cane;
			tree.Materials[4].tex=tree_paper;
	man=Model_3DS();
	
	
	char ar[]="kiryu.3DS";
	man.Load(ar);

head.LoadBMP("head.bmp");
hair.LoadBMP("hair.bmp");
buckle.LoadBMP("buckle.bmp");
eye.LoadBMP("eye.bmp");
upper.LoadBMP("upper.bmp");
lower.LoadBMP("lower.bmp");
beard.LoadBMP("beard.bmp");
accesories.LoadBMP("accesories.bmp");
	
//man.pos.x=MyCamera.Position.x;
	//man.pos.y=MyCamera.Position.y;
	//man.pos.z=MyCamera.Position.z;
man.rot.y=180;
	man.scale=0.1;
	

	man.Materials[0].tex=accesories;
		man.Materials[1].tex=beard;
	man.Materials[2].tex=buckle;
		man.Materials[3].tex=eye;
		man.Materials[4].tex=hair;
		man.Materials[5].tex=head;
	man.Materials[6].tex=head;
	man.Materials[7].tex=lower;
	man.Materials[8].tex=hair;
	man.Materials[9].tex=upper;



		man2=Model_3DS();
	
	
	char arr[]="kiryu.3DS";
	man2.Load(arr);


	
//man.pos.x=MyCamera.Position.x;
	//man.pos.y=MyCamera.Position.y;
	//man.pos.z=MyCamera.Position.z;

	man2.scale=0.1;
	

	man2.Materials[0].tex=accesories;
		man2.Materials[1].tex=beard;
	man2.Materials[2].tex=buckle;
		man2.Materials[3].tex=eye;
		man2.Materials[4].tex=hair;
		man2.Materials[5].tex=head;
	man2.Materials[6].tex=head;
	man2.Materials[7].tex=lower;
	man2.Materials[8].tex=hair;
	man2.Materials[9].tex=upper;



	
	SoundManager.Initialize(hWnd);

	SoundManager.CreateSound("250-milliseconds-of-silence_2utEam3d.wav", Sound);

	SoundManager1.Initialize(hWnd);
	SoundManager1.CreateSound("250-milliseconds-of-silence_YzgIrRgq.wav", Sound1);

	SoundManager2.Initialize(hWnd);
	SoundManager2.CreateSound("creakylightwoodendoor-mc.wav", Sound2);
	
	 glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

//Set light properties
  GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

 glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
 glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	//glEnable depth testing and normalize normals
  glEnable(GL_DEPTH_TEST);
   glEnable(GL_NORMALIZE);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	MyCamera = Camera();
	MyCamera.Position.x = 1400;

	MyCamera.Position.y = 995;
	MyCamera.Position.z = 2500;
	//MyCamera.Position.z = 3000;
	return TRUE;										// Initialization Went OK
}

void list()
{
	Mosque m=Mosque();
	SKYBOX skybox=SKYBOX();
	DomeOfThechain d=DomeOfThechain();
	FLOOR b=FLOOR();
	arch ar=arch();
	GLuint list = glGenLists(1);
	glNewList(list, GL_COMPILE);


	glPushMatrix();
	m.front_mosque(qibli_wall_texture, qibli_inside_wall_texture,cylinder3,carpet,qibli_roof_texture,cupola_of_the_chain_dome,qibli_door,qibli_above_door_texture,library_book,library_sides,flag, qibli_window,pz);
	b.DRAWFLOOR(the_floor,floor_wall_texture,garden,school_door);
	glPopMatrix();
			glEndList();
	glCallList(list);
}
float a=0.1,angle=0;
double k = 0 , l=0 , h=0;


// Object coordinates
float objectX = 0.0f;
float objectY = 0.0f;

// Circle parameters
float centerX = 0.0f;
float centerY = 0.0f;
float radius = 100.0f;

float plane=0;
int even=1;
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawingzxc
{
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//fix texture
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(60.0, 2, 1.0, 10000);
	MOUSE mouse=MOUSE();
	mouse.mouse(mouseX, mouseY, isClicked, isRClicked);
	
			MyCamera.Render();
			Key(keys, 0.2);
	glTranslated(0,0,-8);


	Mosque m=Mosque();
	SKYBOX skybox=SKYBOX();
	DomeOfThechain d=DomeOfThechain();
	FLOOR b=FLOOR();
	arch ar=arch();
	//mirror
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex3d(550,983,520);
	glVertex3d(570,983,520);
	glVertex3d(570,995,520);
	glVertex3d(550,995,520);
	glEnd();

	ar.all_wals(the_floor);
	

		glPushMatrix();

			glTranslated(MyCamera.Position.x,MyCamera.Position.y-12,MyCamera.Position.z-10);
	
	man.Draw();
	glPopMatrix();
	glPopMatrix();
	
	if(	MyCamera.Position.x>=550&&MyCamera.Position.x<=570&&MyCamera.Position.z <540)
	
	{
			glPushMatrix();

			glTranslated(MyCamera.Position.x,(MyCamera.Position.y-12),(MyCamera.Position.z-20));
		
	man2.Draw();
	glPopMatrix();
	}
	
models(tree);
car.Draw();

	glPushMatrix();
	m.front_mosque(qibli_wall_texture, qibli_inside_wall_texture,cylinder3,carpet,qibli_roof_texture,cupola_of_the_chain_dome,qibli_door,qibli_above_door_texture,library_book,library_sides,flag, qibli_window,pz);
	b.DRAWFLOOR(the_floor,floor_wall_texture,garden,school_door);
	glPopMatrix();
	



	glPushMatrix();

				
				glTranslated(1350,1000,1800);
			
			glPushMatrix();
	glTranslated(275,0,-176);
	glScalef(8,8,8);
	
	d.DRAW_CHAIN(Point(0,2,0),Point(0,2,0.5),Point(3,2,0.5),Point(3,2,0),Point(0,2.2,0),Point(0,2.2,0.5),Point(3,2.2,0.5),Point(3,2.2,0),cupola_of_the_chain_dome,dome_of_the_chian_roof,cupola_of_the_chain_cylinder,cupola_of_the_chain_dome,under_gold_dome,triangle_abs_texture,triangle_abs_texture,row_bottom_face);
	glPopMatrix();
	
	m.DRAWMOSQUE(Point(0,0,0),Point(0,20,0),Point(110,20,0),Point(110,0,0),mosque_body,door,under_dome, ball,quran,quran2,dome,roof,cylinder,cylinder2,wood_window,wood2,under_gold_dome,carpet,flag2,pz);
	glPopMatrix();
	
	if(the_time==1)
	{
		skybox.day(SKYFRONT1,SKYBACK1,SKYLEFT1,SKYRIGHT1,SKYUP1);
	}
	else if(the_time==2)
	{
		skybox.midday(SKYFRONT2,SKYBACK2,SKYLEFT2,SKYRIGHT2,SKYUP2);
	}
	else if(the_time==3)
	{
		skybox.sunset(SKYFRONT3,SKYBACK3,SKYLEFT3,SKYRIGHT3,SKYUP3);
	}
	else
	{
		skybox.night(SKYFRONT4,SKYBACK4,SKYLEFT4,SKYRIGHT4,SKYUP4);
	}
	even+=1;
	if(even<1000||even>5000)
plane*=-1;
	else
		plane*=-1;

	plane+=0.1;

	






	glPushMatrix();
	
	//ar.streets(KS2,home1,home2,home3,home4,home5,home6,home7);
    glPopMatrix();
	glRotated(90,0,1,0);
	

	return TRUE;

}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;
	switch (uMsg)									// Check For Windows Messages
	{
case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
		isClicked = false; 	 break;
	case WM_RBUTTONUP:
		isRClicked = false;   break;
	case WM_LBUTTONDOWN:
		isClicked = true; 	break;
	case WM_RBUTTONDOWN:
		isRClicked = true;	break;
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Example", 1920, 1080, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

