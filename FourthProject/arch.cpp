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

 void arch::  DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }
void arch::  angel_roof( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int angel_texture) {
		
		glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, angel_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);

	//Front Face
	
	DrawQuad(p2,p6,p7,p3);


	//Back Face
	DrawQuad(p1,p5,p8,p4);

	//Right Face
    DrawQuad(p8,p7,p3,p4);
	//Left Face
	DrawQuad(p5,p6,p2,p1);

	//Top Face
	DrawQuad(p5,p6,p7,p8);

	//Bottom Face
	DrawQuad(p1,p2,p3,p4);

	glDisable(GL_TEXTURE_2D);
}


void arch::  newpyramid( Point v1, Point v2, Point v3, Point v4, Point v5, Point v6,int pyramid_texture) {
		
		glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, pyramid_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_TRIANGLE_FAN);

  glTexCoord2f(1.0f, 0.0f);  glVertex3f(v1.x, v1.y, v1.z);
   glTexCoord2f(1.0f, 1.0f);  glVertex3f(v2.x, v2.y, v2.z);
 glTexCoord2f(0.0f, 1.0f);   glVertex3f(v3.x, v3.y, v3.z);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v5.x, v5.y, v5.z);
	 glTexCoord2f(1.0f, 1.0f);glVertex3f(v6.x, v6.y, v6.z);
    glEnd();

			glDisable(GL_TEXTURE_2D);
}


void arch::  Cylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID) {
    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Save the current matrix
    glPushMatrix();

    // Translate to the specified location
    glTranslatef(x, y, z);

    // Apply rotations
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);

    // Set the number of sides for the cylinder
    const int sides = 32;

    // Calculate the angle between each side
    const float angleIncrement = 2.0f * 3.14 / sides;

    // Draw the top and bottom circles
    glBegin(GL_TRIANGLE_FAN);
    
    // Draw the top circle
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, height / 2.0f + topHeight, 0.0f);

    for (int i = 0; i <= sides; ++i) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glTexCoord2f((x / radius + 1) / 2, (z / radius + 1) / 2);
        glVertex3f(x, height / 2.0f + topHeight, z);
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    
    // Draw the bottom circle
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, -height / 2.0f, 0.0f);

    for (int i = 0; i <= sides; ++i) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glTexCoord2f((x / radius + 1) / 2, (z / radius + 1) / 2);
        glVertex3f(x, -height / 2.0f, z);
    }

    glEnd();

    // Draw the sides of the cylinder
    glBegin(GL_QUAD_STRIP);
    
    for (int i = 0; i <= sides; ++i) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glTexCoord2f((float)i / sides, 0.0f);
        glVertex3f(x, -height / 2.0f, z);

        glTexCoord2f((float)i / sides, 1.0f);
        glVertex3f(x, height / 2.0f + topHeight, z);
    }

    glEnd();

    // Restore the matrix
    glPopMatrix();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);
}

void arch:: DrawAngle(Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int angel_texture,int pyramid_texture)
{
	//THIS FUNCTION STARTS WITH DRAWING THE ROOF  

	//X VALUE= 31

	//Y VALUE=1

	//Z VALUE =4

	//ROOF
	angel_roof(p1,p2,p3,p4,p5,p6,p7,p8,angel_texture);

	//FIRST 3DADA
	

	
	angel_roof(Point(p4.x-2,p4.y-7,p4.z),Point(p4.x-2,p4.y-7,p4.z+4),Point(p3.x,p3.y-7,p3.z),Point(p4.x,p4.y-7,p4.z),Point(p4.x-2,p5.y,p4.z),Point(p4.x-2,p5.y,p4.z+4),Point(p7.x,p7.y,p7.z),Point(p8.x,p8.y,p8.z),angel_texture);

	//SECOND 3DADA

	angel_roof(Point(p1.x,p1.y-7,p4.z),Point(p1.x,p1.y-7,p1.z+4),Point(p1.x+2,p1.y-7,p1.z+4),Point(p1.x+2,p1.y-7,p1.z),Point(p5.x,p5.y,p5.z),Point(p6.x,p6.y,p6.z),Point(p6.x+2,p7.y,p6.z),Point(p6.x+2,p7.y,p5.z),angel_texture);

	//FIRST COLUMN FROM RIGHT

	Cylinder(p8.x-8,p1.y,p1.z+2,0.9,1,7,180,0,0,pyramid_texture);
		

	newpyramid(Point(p8.x-8,p1.y-2,p1.z+2),Point(p8.x-6,p1.y,p2.z),Point(p8.x-6,p1.y,p1.z),Point(p8.x-10,p1.y,p1.z),Point(p8.x-10,p1.y,p2.z),Point(p8.x-6,p1.y,p2.z),pyramid_texture);

	//SECOND COLUMN FROM RIGHT



		Cylinder(p8.x-16,p1.y,p1.z+2,0.9,1,7,180,0,0,pyramid_texture);


	newpyramid(Point(p8.x-16,p1.y-2,p1.z+2),Point(p8.x-14,p1.y,p2.z),Point(p8.x-14,p1.y,p1.z),Point(p8.x-18,p1.y,p1.z),Point(p8.x-18,p1.y,p2.z),Point(p8.x-14,p1.y,p2.z),pyramid_texture);
	

	//THIRD COLUMN FROM RIGHT

			Cylinder(p8.x-24,p1.y,p1.z+2,0.9,1,7,180,0,0,pyramid_texture);


	newpyramid(Point(p8.x-24,p1.y-2,p1.z+2),Point(p8.x-22,p1.y,p2.z),Point(p8.x-22,p1.y,p1.z),Point(p8.x-26,p1.y,p1.z),Point(p8.x-26,p1.y,p2.z),Point(p8.x-22,p1.y,p2.z),pyramid_texture);

	
	
}


void arch:: DrawAngle_mosque(Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int angel_texture,int pyramid_texture)
{
	//THIS FUNCTION STARTS WITH DRAWING THE ROOF  

	//X VALUE= 31

	//Y VALUE=1

	//Z VALUE =4

	//ROOF
	angel_roof(p1,p2,p3,p4,p5,p6,p7,p8,angel_texture);

	//FIRST 3DADA
	
		glPushMatrix();
		glTranslated(p8.x-130.5,p1.y,p1.z);

	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+7.3),Point(p3.x,p3.y-7,p3.z),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+7.3),Point(p7.x,p7.y,p7.z),Point(p8.x,p8.y,p8.z),angel_texture);
	glPopMatrix();

	
	//angel_roof(Point(p4.x-2,p4.y-7,p4.z),Point(p4.x-2,p4.y-7,p4.z),Point(p3.x,p3.y-7,p3.z),Point(p4.x,p4.y-7,p4.z),Point(p4.x-2,p5.y,p4.z),Point(p4.x-2,p5.y,p4.z),Point(p7.x,p7.y,p7.z),Point(p8.x,p8.y,p8.z),angel_texture);

	//SECOND 3DADA

	glPushMatrix();
		glTranslated(p8.x-66,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+7.3),Point(p3.x,p3.y-7,p3.z),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+7.3),Point(p7.x,p7.y,p7.z),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();

	//angel_roof(Point(p1.x,p1.y-7,p4.z),Point(p1.x,p1.y-7,p1.z),Point(p1.x+2,p1.y-7,p1.z),Point(p1.x+2,p1.y-7,p1.z),Point(p5.x,p5.y,p5.z),Point(p6.x,p6.y,p6.z),Point(p6.x+2,p7.y,p6.z),Point(p6.x+2,p7.y,p5.z),angel_texture);

	//FIRST COLUMN FROM RIGHT
	


		glPushMatrix();
		glTranslated(p8.x-73,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+2.3),Point(p3.x,p3.y-7,p3.z-5),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+2.3),Point(p7.x,p7.y,p7.z-5),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();


	glPushMatrix();
		glTranslated(p8.x-83,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+2.3),Point(p3.x,p3.y-7,p3.z-5),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+2.3),Point(p7.x,p7.y,p7.z-5),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();


	glPushMatrix();
		glTranslated(p8.x-93,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+2.3),Point(p3.x,p3.y-7,p3.z-5),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+2.3),Point(p7.x,p7.y,p7.z-5),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();

	glPushMatrix();
		glTranslated(p8.x-103,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+2.3),Point(p3.x,p3.y-7,p3.z-5),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+2.3),Point(p7.x,p7.y,p7.z-5),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();

	glPushMatrix();
		glTranslated(p8.x-112,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+2.3),Point(p3.x,p3.y-7,p3.z-5),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+2.3),Point(p7.x,p7.y,p7.z-5),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();


	glPushMatrix();
		glTranslated(p8.x-121,p1.y,p1.z);
	angel_roof(Point(p4.x-1.5,p4.y-7,p4.z),Point(p4.x-1.5,p4.y-7,p4.z+2.3),Point(p3.x,p3.y-7,p3.z-5),Point(p4.x,p4.y-7,p4.z),Point(p4.x-1.5,p5.y,p4.z),Point(p4.x-1.5,p5.y,p4.z+2.3),Point(p7.x,p7.y,p7.z-5),Point(p8.x,p8.y,p8.z),angel_texture);
glPopMatrix();

}



void arch::  multi_wall_1( int n,int pyramid_texture) {
  arch ar=arch();
  for (int i = 0; i < n; i++) {
    if(i%2==0){
    Point p1(i * 2+i*11, 0, -19), p2(i * 2 + 15+i*11, 0, -19), p3(i * 2 + 15+i*11, 70, -19), p4(i * 2+i*11, 70, -19), p5(i * 2+i*11, 0, 1), p6(i * 2 + 15+i*11, 0, 1), p7(i * 2 + 15+i*11, 70, 1), p8(i * 2+i*11, 70, 1);
    ar.angel_roof(p1, p2, p3, p4, p5, p6, p7, p8, pyramid_texture);
  }else{
  Point p1(i * 2+i*11, 0, -19), p2(i * 2 + 15+i*11, 0, -19), p3(i * 2 + 15+i*11, 60, -19), p4(i * 2+i*11, 60, -19), p5(i * 2+i*11, 0, 1), p6(i * 2 + 15+i*11, 0, 1), p7(i * 2 + 15+i*11, 60, 1), p8(i * 2+i*11, 60, 1);
    ar.angel_roof(p1, p2, p3, p4, p5, p6, p7, p8, pyramid_texture);
  }
}
}

void arch::  multi_wall_2( int n,int pyramid_texture) {
  arch ar=arch();
  for (int i = 0; i < n; i++) {
    if(i%2==0){
  Point p1(0, 0,i * 2+i*11), p2(19 , 0, i * 2+i*11), p3(19, 70, i * 2+i*11), p4(0, 70,i * 2+i*11), p5(0, 0, i * 2 + 15+i*11), p6(19, 0, i * 2 + 15+i*11), p7(19, 70, i * 2 + 15+i*11), p8(0, 70, i * 2 + 15+i*11);
  ar.angel_roof(p1, p2, p3, p4, p5, p6, p7, p8, pyramid_texture);
  }else{
  Point p1(0, 0,i * 2+i*11), p2(19 , 0, i * 2+i*11), p3(19, 60, i * 2+i*11), p4(0, 60,i * 2+i*11), p5(0, 0, i * 2 + 15+i*11), p6(19, 0, i * 2 + 15+i*11), p7(19, 60, i * 2 + 15+i*11), p8(0, 60, i * 2 + 15+i*11);
    ar.angel_roof(p1, p2, p3, p4, p5, p6, p7, p8, pyramid_texture);
  }
}
}




void arch::  all_wals(int pyramid_texture) {
  arch ar=arch();
  //الجانب الاول
  //الجدار
  glPushMatrix();
  glTranslated(500,980,4020);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1150,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1160,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(1230,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(1240,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(1320,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(1330,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1140,1050,4020);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();



  //الجدار
  glPushMatrix();
  glTranslated(1337,980,4020);
  ar.multi_wall_1(115, pyramid_texture);
  glPopMatrix();
  

  
  //الجانب الثاني
  //الجدار
  glPushMatrix();
  glTranslated(500,980,510);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1150,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1160,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(1230,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(1240,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(1320,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(1330,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1140,1050,510);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();


//الجدار
  glPushMatrix();
  glTranslated(1337,980,510);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1987,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1997,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2067,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2077,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2157,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2167,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1977,1050,510);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();
  

  
  //الجدار
  glPushMatrix();
  glTranslated(2174,980,510);
  ar.multi_wall_1(48, pyramid_texture);
  glPopMatrix();
  

  

  
  
  //الجانب الثالث
  //الجدار
  glPushMatrix();
  glTranslated(2800,980,510);
  ar.multi_wall_2(115, pyramid_texture);
  glPopMatrix();
  
  
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(2800,980,2005);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(2810,1025,1995);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2800,980,2085);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2810,1025,2075);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2800,980,2165);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2810,1025,2155);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(2800,1045,1995);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();


//الجدار
  glPushMatrix();
  glTranslated(2800,980,2160);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(2800,980,2830);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(2810,1025,2820);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2800,980,2910);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2810,1025,2900);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2800,980,2990);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2810,1025,2980);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(2800,1045,2820);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();
  //الجدار
  glPushMatrix();
  glTranslated(2800,980,2985);
  ar.multi_wall_2(80, pyramid_texture);
  glPopMatrix();
  
  
  
  //الجانب الرابع
  //الجدار
  glPushMatrix();
  glTranslated(482,980,510);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(482,980,1180);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(488,1025,1170);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(482,980,1260);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(488,1025,1250);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(482,980,1340);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(488,1025,1330);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(482,1045,1170);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();


//الجدار
  glPushMatrix();
  glTranslated(482,980,1335);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(482,980,2005);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(488,1025,1995);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(482,980,2085);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(488,1025,2075);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(482,980,2165);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(488,1025,2155);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(482,1045,1995);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();


  //الجدار
  glPushMatrix();
  glTranslated(482,980,2160);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(482,980,2830);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(488,1025,2820);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(482,980,2910);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(488,1025,2900);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(482,980,2990);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(488,1025,2980);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(482,1045,2820);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();
  //الجدار
  glPushMatrix();
  glTranslated(482,980,2985);
  ar.multi_wall_2(80, pyramid_texture);
  glPopMatrix();
  
}


void arch::  streets(int pyramid_texture,int home1,int home2,int home3,int home4,int home5,int home6,int home7) {
  arch ar=arch();
  //street 1 
  
  glPushMatrix();
  glTranslated(-100,980,1970);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //street 2
  
  glPushMatrix();
  glTranslated(-100,980,2800);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();
  //street 3
  
  glPushMatrix();
  glTranslated(2800,980,2800);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();
  //street 4
  
  glPushMatrix();
  glTranslated(2800,980,1990);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();

  //street 5
  
  glPushMatrix();
  glTranslated(2170,980,-90);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);

  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();
  //street 6
  
  glPushMatrix();
  glTranslated(1330,980,-90);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);

glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();
  //street 7
  
  glPushMatrix();
  glTranslated(500,980,1350);
  
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
     glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
   glDisable(GL_TEXTURE_2D);
    glPopMatrix();
  


  
  
  
  //side one
  //1

  //1
  glPushMatrix();
  glTranslated(1900,977,350);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(1900,977,150);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
 //3
  glPushMatrix();
  glTranslated(1900,977,-50);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
 //4
  glPushMatrix();
  glTranslated(2160,977,350);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
 //5
  glPushMatrix();
  glTranslated(2160,977,150);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
 //6
  glPushMatrix();
  glTranslated(2160,977,-50);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
 


  //2


  //1
  glPushMatrix();
  glTranslated(1050,977,350);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(1050,977,150);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
 //3
  glPushMatrix();
  glTranslated(1050,977,-50);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
 //4
  glPushMatrix();
  glTranslated(1330,977,350);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
 //5
  glPushMatrix();
  glTranslated(1330,977,150);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
 //6
  glPushMatrix();
  glTranslated(1330,977,-50);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
 


  //side two
  //1

//1
  glPushMatrix();
  glTranslated(460,977,1350);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(260,977,1350);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
  
 //3
  glPushMatrix();
  glTranslated(60,977,1350);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
  //4
  glPushMatrix();
  glTranslated(460,977,1070);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
  //5
  glPushMatrix();
  glTranslated(260,977,1070);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
  
 //6
  glPushMatrix();
  glTranslated(60,977,1070);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  
  //2

  //1
  glPushMatrix();
  glTranslated(460,977,2150);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(260,977,2150);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
  
 //3
  glPushMatrix();
  glTranslated(60,977,2150);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
  //4
  glPushMatrix();
  glTranslated(460,977,1900);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
  //5
  glPushMatrix();
  glTranslated(260,977,1900);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
  
 //6
  glPushMatrix();
  glTranslated(60,977,1900);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();


   //3

  //1
  glPushMatrix();
  glTranslated(460,977,2990);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(260,977,2990);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
  
 //3
  glPushMatrix();
  glTranslated(60,977,2990);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
  //4
  glPushMatrix();
  glTranslated(460,977,2720);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
  //5
  glPushMatrix();
  glTranslated(260,977,2720);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
  
 //6
  glPushMatrix();
  glTranslated(60,977,2720);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  
  //side three
   //1

  
  //1
  glPushMatrix();
  glTranslated(2980,977,2710);
  glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(3200,977,2710);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
 //3
  glPushMatrix();
  glTranslated(3420,977,2710);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
 //4
  glPushMatrix();
  glTranslated(2980,977,2980);
  glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
  //5
  glPushMatrix();
  glTranslated(3200,977,2980);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
 //6
  glPushMatrix();
  glTranslated(3420,977,2980);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();

   //2

  
  //1
  glPushMatrix();
  glTranslated(2980,977,1900);
  glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(3200,977,1900);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
 //3
  glPushMatrix();
  glTranslated(3420,977,1900);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
 //4
  glPushMatrix();
  glTranslated(2980,977,2150);
  glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
  //5
  glPushMatrix();
  glTranslated(3200,977,2150);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
 //6
  glPushMatrix();
  glTranslated(3420,977,2150);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();




  //between streests
  //1
  glPushMatrix();
  glTranslated(2980,977,2550);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
//2
  glPushMatrix();
  glTranslated(2980,977,2410);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
//3
  glPushMatrix();
  glTranslated(2980,977,2300);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();





  //1
 glPushMatrix();
  glTranslated(460,977,2300);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix(); 
  
  //2
 glPushMatrix();
  glTranslated(460,977,2450);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix(); 
  
  //3
 glPushMatrix();
  glTranslated(460,977,2600);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix(); 
  
  //4
 glPushMatrix();
  glTranslated(460,977,1780);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix(); 
  //5
 glPushMatrix();
  glTranslated(460,977,1650);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix(); 
  //6
 glPushMatrix();
  glTranslated(460,977,1500);
       glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix(); 
 




   //1
 glPushMatrix();
  glTranslated(1450,977,350);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix(); 
 //2
 glPushMatrix();
  glTranslated(1600,977,350);

ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix(); 
 //3
 glPushMatrix();
  glTranslated(1750,977,350);

  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix(); 
 
}
/*
void arch::  streets(int pyramid_texture,int home1,int home2,int home3,int home4,int home5,int home6,int home7) {
  arch ar=arch();
  //one side 1

  glPushMatrix();
  glTranslated(1340,977,4000);
  glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
  
  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(-190, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(0, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(0, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-190, 0,600);
   glEnd();
  glDisable(GL_TEXTURE_2D);
    glPopMatrix();




  //one side 2
  
  glPushMatrix();
  glTranslated(1295,977,4000);
   glBindTexture(GL_TEXTURE_2D, pyramid_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //left front triangle
  glEnable(GL_TEXTURE_2D);
  
  glBegin(GL_QUADS);
   glTexCoord2f(20.0f, 0.0f);   glVertex3f(700, 0,0);
   glTexCoord2f(20.0f, 20.0f);   glVertex3f(890, 0, 0);
   glTexCoord2f(0.0f, 20.0f);   glVertex3f(890, 0,600);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(700, 0,600);
   glEnd();
  glDisable(GL_TEXTURE_2D);
    glPopMatrix();



  //side 1
  // adada 1
  //1
  glPushMatrix();
  glTranslated(1330,977,4040);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //2
  glPushMatrix();
  glTranslated(1330,977,4250);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home2);
  glPopMatrix();
  //3
  glPushMatrix();
  glTranslated(1330,977,4460);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home1);
  glPopMatrix();
  //4
  glPushMatrix();
  glTranslated(1070,977,4040);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home4);
  glPopMatrix();
  //5
  glPushMatrix();
  glTranslated(1070,977,4250);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home5);
  glPopMatrix();
  //6
  glPushMatrix();
  glTranslated(1070,977,4460);
  ar.angel_roof(Point (0, 0, -19), Point(90, 0, -19), Point(90, 160, -19), Point(0, 160, -19), Point(0, 0, 150), Point(90, 0, 150), Point(90, 160, 150), Point(0, 160, 150),home3);
  glPopMatrix();
  //7
  glPushMatrix();
  glTranslated(1170,977,4610);
  ar.angel_roof(Point (0, 0, -19), Point(180, 0, -19), Point(180, 160, -19), Point(0, 160, -19), Point(0, 0, 50), Point(180, 0, 50), Point(180, 160, 50), Point(0, 160, 50),home7);
  glPopMatrix();
  }

/*

void arch::  all_wals(int pyramid_texture) {
  arch ar=arch();

  glPushMatrix();
  glTranslated(500,980,4020);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1150,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1160,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(1230,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(1240,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(1320,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(1330,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1140,1050,4020);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();



  //الجدار
  glPushMatrix();
  glTranslated(1337,980,4020);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1987,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1997,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2067,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2077,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2157,980,4020);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2167,1030,4010);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1977,1050,4020);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();
  
  
  
  //الجدار
  glPushMatrix();
  glTranslated(2174,980,4020);
  ar.multi_wall_1(48, pyramid_texture);
  glPopMatrix();


//الجانب الثاني
  //الجدار
  glPushMatrix();
  glTranslated(500,980,510);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1150,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1160,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(1230,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(1240,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(1320,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(1330,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1140,1050,510);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();



  //الجدار
  glPushMatrix();
  glTranslated(1337,980,510);
  ar.multi_wall_1(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(1987,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(1997,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2067,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2077,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2157,980,510);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2167,1030,500);
  ar.newpyramid(Point (0, 0, 0), Point(-20, 20, -10), Point(-20, 20, 10), Point(20, 20, -10), Point(20, 20, 10), Point(-20, 20, -10),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(1977,1050,510);
    ar.angel_roof(Point (0, 0, -19), Point(210, 0, -19), Point(210, 12, -19), Point(0, 12, -19), Point(0, 0, 1), Point(210, 0, 1), Point(210, 12, 1), Point(0, 12, 1),pyramid_texture);
  glPopMatrix();
  

  
  //الجدار
  glPushMatrix();
  glTranslated(2174,980,510);
  ar.multi_wall_1(48, pyramid_texture);
  glPopMatrix();


//الجانب الثالث
  //الجدار
  glPushMatrix();
  glTranslated(2800,980,510);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(2800,980,1180);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(2810,1025,1170);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2800,980,1260);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2810,1025,1250);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2800,980,1340);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2810,1025,1330);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(2800,1045,1170);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();

  

  //الجدار
  glPushMatrix();
  glTranslated(2800,980,1335);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(2800,980,2005);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(2810,1025,1995);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2800,980,2085);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2810,1025,2075);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2800,980,2165);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2810,1025,2155);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(2800,1045,1995);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();


//الجدار
  glPushMatrix();
  glTranslated(2800,980,2160);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(2800,980,2830);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(2810,1025,2820);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(2800,980,2910);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(2810,1025,2900);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(2800,980,2990);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(2810,1025,2980);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(2800,1045,2820);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();
  //الجدار
  glPushMatrix();
  glTranslated(2800,980,2985);
  ar.multi_wall_2(80, pyramid_texture);
  glPopMatrix();
  

  
  //الجانب الرابع
  //الجدار
  glPushMatrix();
  glTranslated(482,980,510);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(482,980,1180);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(488,1025,1170);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(482,980,1260);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(488,1025,1250);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(482,980,1340);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(488,1025,1330);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(482,1045,1170);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();


//الجدار
  glPushMatrix();
  glTranslated(482,980,1335);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(482,980,2005);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(488,1025,1995);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(482,980,2085);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(488,1025,2075);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(482,980,2165);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(488,1025,2155);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(482,1045,1995);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();


  //الجدار
  glPushMatrix();
  glTranslated(482,980,2160);
  ar.multi_wall_2(50, pyramid_texture);
  glPopMatrix();
  //العضاضة الاولى
  glPushMatrix();
  glTranslated(482,980,2830);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الاول
  glPushMatrix();
  glTranslated(488,1025,2820);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثانية
  glPushMatrix();
  glTranslated(482,980,2910);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثاني
  glPushMatrix();
  glTranslated(488,1025,2900);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //العضاضة الثالثة
  glPushMatrix();
  glTranslated(482,980,2990);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 60, -19), Point(0, 60, -19), Point(0, 0, 1), Point(15, 0, 1), Point(15, 60, 1), Point(0, 60, 1),pyramid_texture);
  glPopMatrix();
  //الهرم الثالث
  glPushMatrix();
  glTranslated(488,1025,2980);
  ar.newpyramid(Point (0, 0, 0), Point(-10, 20, 20), Point(10, 20, 20), Point(10, 20, -20), Point(-10, 20, -20), Point(-10, 20, 20),pyramid_texture);
  glPopMatrix();
  //السقفف
  glPushMatrix();
  glTranslated(482,1045,2820);
    ar.angel_roof(Point (0, 0, -19), Point(15, 0, -19), Point(15, 12, -19), Point(0, 12, -19), Point(0, 0, 190), Point(15, 0, 190), Point(15, 12, 190), Point(0, 12, 190),pyramid_texture);
  glPopMatrix();
  //الجدار
  glPushMatrix();
  glTranslated(482,980,2985);
  ar.multi_wall_2(80, pyramid_texture);
  glPopMatrix();
 */ 

