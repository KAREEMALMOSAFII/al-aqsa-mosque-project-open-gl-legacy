#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "Point.h"
#include "PrimitiveDrawer.h"
#include "mosque.h"
#include "DomeOfThechain.h"
#include "arch.h"
#include "FLOOR.h"
#include "Model_3DS.h"
FLOOR::FLOOR(){}

void FLOOR:: garden(Point v1, Point v2, Point v3, Point v4,int garden_texture) {
	
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, garden_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_QUADS);

  glTexCoord2f(3.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(3.0f, 3.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 3.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);
  }

 void FLOOR:: DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

void FLOOR:: newstairs( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int stair_counter,int stairs_texture)
{

	
		float yy=p6.y;
	float zz=p6.z;

	
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, stairs_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	DrawQuad(p1,p2,p3,p4);
	DrawQuad(p5,p6,p7,p8);

	for (int i= 1; i<=stair_counter; i++)
	{
		if(i%2!=0){

			p1.z+=zz;
			p1.y=p2.y;

			p2.z+=zz;
			p2.y+=yy;

			p3.z+=zz;
			p3.y+=yy;

			p4.z=p1.z;
			p4.y=p1.y;

DrawQuad(p1,p2,p3,p4);
		}
		else
		{
		p5.y=p2.y;
			p5.z=p2.z;

			p6.y=p2.y;
			p6.z+=zz;

			p7.y=p2.y;
			p7.z+=zz;

			p8.y=p2.y;
			p8.z=p1.z;
				DrawQuad(p5,p6,p7,p8);
		}
	p4.z=p6.z;
	}
	

	//glColor3f(1, 1, 1);

	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/
	
}


void FLOOR::DRAWFLOOR(int floor_texture,int floor_wall_texture,int garden_texture,int door )
{
	arch ar=arch();
	
	glBindTexture(GL_TEXTURE_2D, floor_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  //middle area
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2f(80.0f, 0.0f); 	glVertex3d(1000,1000,2000);
glTexCoord2f(80.0f,80.0f);	glVertex3d(1000,1000,1200);
glTexCoord2f(0.0f, 80.0f);	glVertex3d(1800,1000,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,2000);

		glEnd();

		//big area
			glBegin(GL_POLYGON);
	glTexCoord2f(80.0f, 0.0f); 	glVertex3d(500,982,4000);
glTexCoord2f(80.0f,80.0f);	glVertex3d(500,982,500);
glTexCoord2f(0.0f, 80.0f);	glVertex3d(2800,982,500);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(2800,982,4000);

		glEnd();

		glDisable(GL_TEXTURE_2D);


			glBindTexture(GL_TEXTURE_2D, floor_wall_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  // front wall under middle area
	glEnable(GL_TEXTURE_2D);

	{
			glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1100,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1100,1000,2000);


		glEnd();

					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1100,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1100,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1200,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1200,1000,2000);


		glEnd();

					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1200,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1200,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1300,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1300,1000,2000);


		glEnd();


					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1300,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1300,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1400,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1400,1000,2000);


		glEnd();

					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1400,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1400,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1500,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1500,1000,2000);


		glEnd();

							glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1500,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1500,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1600,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1600,1000,2000);


		glEnd();

							glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1600,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1600,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1700,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1700,1000,2000);


		glEnd();

									glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1700,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1700,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,2000);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,2000);


		glEnd();


	}
	{
			glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1900);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1900);


		glEnd();



					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1900);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1900);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1800);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1800);


		glEnd();


							glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1800);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1800);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1700);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1700);


		glEnd();


									glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1700);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1700);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1600);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1600);


		glEnd();

											glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1600);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1600);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1500);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1500);


		glEnd();


													glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1500);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1500);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1400);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1400);


		glEnd();



															glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1400);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1400);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1300);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1300);


		glEnd();


																glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1300);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1300);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1000,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1000,1000,1200);


		glEnd();

	}

	{	
		glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1000,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1000,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1100,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1100,1000,1200);


		glEnd();

					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1100,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1100,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1200,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1200,1000,1200);


		glEnd();

					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1200,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1200,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1300,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1300,1000,1200);


		glEnd();


					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1300,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1300,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1400,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1400,1000,1200);


		glEnd();

					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1400,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1400,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1500,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1500,1000,1200);


		glEnd();

							glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1500,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1500,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1600,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1600,1000,1200);


		glEnd();

							glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1600,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1600,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1700,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1700,1000,1200);


		glEnd();

									glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1700,1000,1200);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1700,980,1200);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1200);


		glEnd();



	}
	


	{
				glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,2000);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,2000);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1900);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1900);


		glEnd();



					glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1900);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1900);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1800);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1800);


		glEnd();


							glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1800);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1800);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1700);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1700);


		glEnd();


									glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1700);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1700);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1600);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1600);


		glEnd();

											glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1600);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1600);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1500);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1500);


		glEnd();


													glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1500);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1500);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1400);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1400);


		glEnd();



															glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1400);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1400);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1300);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1300);


		glEnd();


																glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 	glVertex3d(1800,1000,1300);
glTexCoord2f(1.0f, 1.0f);	glVertex3d(1800,980,1300);
glTexCoord2f(0.0f, 1.0f);	glVertex3d(1800,980,1200);
glTexCoord2f(0.0f, 0.0f);	glVertex3d(1800,1000,1200);


		glEnd();
	}
			

		glEnd();
		glDisable(GL_TEXTURE_2D);


		//front stairs
		glPushMatrix();
		glTranslated(1450,982,2060);
		glRotated(180,0,1,0);

		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		garden(Point(450,0.01,60),Point(-350,0.01,60),Point(-350,0.01,0),Point(450,0.01,0),garden_texture);
			
		glPushMatrix();
		glTranslated(105,0,0);
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
			glPopMatrix();
		//front right stairs
		glPushMatrix();
		glTranslated(1750,982,2060);
		glRotated(180,0,1,0);
		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();

		//left stairs
				glPushMatrix();
		glTranslated(940,982,1720);
		glRotated(90,0,1,0);
		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();
		 

		//left front stairs
				glPushMatrix();
		glTranslated(940,982,1995);
		glRotated(90,0,1,0);
		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();


		//left back stairs
			glPushMatrix();
		glTranslated(940,982,1300);
		glRotated(90,0,1,0);
		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();

		//back stairs
		 //make it flat stairs
			glPushMatrix();
		glTranslated(1350,982,1140);


		//LEFT GARDEN

		garden(Point(-350,0.01,920),Point(-410,0.01,920),Point(-410,0.01,90),Point(-350,0.01,90),garden_texture);
		//big garden under stairs
		garden(Point(450,0.01,60),Point(-350,0.01,60),Point(-350,0.01,0),Point(450,0.01,0),garden_texture);

		//right the right stairs garden
		garden(Point(300,0.01,-150),Point(100,0.01,-150),Point(100,0.01,70),Point(300,0.01,70),garden_texture);

		//right garden
		garden(Point(1050,0.01,-150),Point(400,0.01,-150),Point(400,0.01,70),Point(900,0.01,70),garden_texture);

		


		//right garden after the street
		garden(Point(300,0.01,-500),Point(100,0.01,-500),Point(100,0.01,-200),Point(300,0.01,-200),garden_texture);

		//right rectangular gardein
			garden(Point(1450,0.01,-500),Point(350,0.01,-500),Point(350,0.01,-200),Point(1100,0.01,-200),garden_texture);

				//right triangle
			garden(Point(1450,0.01,-450),Point(1440,0.01,-450),Point(1200,0.01,-200),Point(1450,0.01,-200),garden_texture);

				//right quad under triangle
			garden(Point(1450,0.01,-150),Point(1160,0.01,-150),Point(930,0.01,150),Point(1450,0.01,150),garden_texture);

				ar.angel_roof(Point(1250,0.01,300),Point(1250,0.01,150),Point(1450,0.01,150),Point(1450,0.01,300),Point(1250,50,300),Point(1250,50,150),Point(1450,50,150),Point(1450,50,300),floor_wall_texture);
					 glEnable(GL_TEXTURE_2D);
					 glBindTexture(GL_TEXTURE_2D,door );
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);	glVertex3d(1249.5,0.01,210);
 glTexCoord2f(1.0f, 1.0f);	glVertex3d(1249.5,30,210);
	  glTexCoord2f(0.0f, 1.0f);glVertex3d(1249.5,30,240);
  glTexCoord2f(0.0f, 0.0f);	glVertex3d(1249.5,0,240);

   glTexCoord2f(1.0f, 0.0f);	glVertex3d(-599.5,0.01,2500);
 glTexCoord2f(1.0f, 1.0f);	glVertex3d(-599.5,30,2500);
	  glTexCoord2f(0.0f, 1.0f);glVertex3d(-599.5,30,2530);
  glTexCoord2f(0.0f, 0.0f);	glVertex3d(-599.5,0,2530);

	glEnd();
	glDisable(GL_TEXTURE_2D);


		ar.angel_roof(Point(-850,0.01,2450),Point(-850,0.01,2850),Point(-600,0,2850),Point(-600,0,2450),Point(-850,50,2450),Point(-850,50,2850),Point(-600,50,2850),Point(-600,50,2450),floor_wall_texture);


			//right quad under quad

			garden(Point(1450,0.01,300),Point(930,0.01,300),Point(930,0.01,1000),Point(1450,0.01,1000),garden_texture);

			//THE LAST
			garden(Point(800,0.01,150),Point(600,0.01,150),Point(600,0.01,900),Point(800,0.01,900),garden_texture);

				garden(Point(1500,0.01,2200),Point(1000,0.01,2200),Point(1000,0.01,2850),Point(1500,0.01,2850),garden_texture);

		//left garden
		garden(Point(-350,0.01,-150),Point(0,0.01,-150),Point(0,0.01,70),Point(-350,0.01,70),garden_texture);
		//left garden after the street
		garden(Point(-350,0.01,-500),Point(0,0.01,-500),Point(0,0.01,-200),Point(-350,0.01,-200),garden_texture);

		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		//glRotated(90,0,1,0);
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();


		//back right stairs
			glPushMatrix();
		glTranslated(1650,982,1140);
		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		//glRotated(90,0,1,0);
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();

		//right stairs
				glPushMatrix();
		glTranslated(1860,982,1620);
		glRotated(270,0,1,0);
		garden(Point(440,0.01,60),Point(-480,0.01,60),Point(-480,0.01,0),Point(440,0.01,0),garden_texture);
		ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
		glPushMatrix();
		glTranslated(105,0,0);
			ar.angel_roof(Point(-5,0,75),Point(0,0,75),Point(0,0,0),Point(-5,0,0),Point(-5,40,75),Point(0,40,75),Point(0,10,0),Point(-5,10,0),floor_texture);
				glPopMatrix();
		newstairs(Point(0,0,0),Point(0,3,0),Point(100,3,0),Point(100,0,0),Point(0,3,0),Point(0,3,10),Point(100,3,10),Point(100,3,0),10,floor_texture);
		glPushMatrix();

			glTranslated(70,45,70);
			glScalef(3.5,5.5,3);
		ar.DrawAngle(Point(-21,1,-2),Point(-21,1,2),Point(10,1,2),Point(10,1,-2),Point(-21,2,-2),Point(-21,2,2),Point(10,2,2),Point(10,2,-2),floor_texture,floor_texture);

		glPopMatrix();
		glPopMatrix();



		
			
}

