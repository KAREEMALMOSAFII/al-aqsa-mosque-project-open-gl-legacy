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

DomeOfThechain::DomeOfThechain(){}


    void DomeOfThechain::CHAIN_DOME(float radius, int slices, int stacks, float posX, float posY, float posZ, int dome,int under_dome)
{
    glPushMatrix();  // Save the current matrix state

    // Translate the ball to the desired position
    glTranslatef(posX, posY, posZ);

    // Enable texture mapping and bind the texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, dome);

    // Draw the half ball
    for (int i = 0; i < stacks; ++i)
    {
        float theta1 = i * (3.14 / stacks);
        float theta2 = (i + 1) * (3.14 / stacks);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices/2; ++j)
        {
            float phi = j * (2 * 3.14 / slices);

            float x = radius * sin(theta2) * cos(phi);
            float y = radius * sin(theta2) * sin(phi);
            float z = radius * cos(theta2);

            glTexCoord2f((float)j / slices, (float)(i + 1) / stacks);
            glVertex3f(x, y, z);

            x = radius * sin(theta1) * cos(phi);
            y = radius * sin(theta1) * sin(phi);
            z = radius * cos(theta1);

            glTexCoord2f((float)j / slices, (float)i / stacks);
            glVertex3f(x, y, z);
        }
        glEnd();
    }

    glPopMatrix();  // Restore the previous matrix state
    glDisable(GL_TEXTURE_2D);  // Disable texture mapping

	glPushMatrix();
	glTranslated(posX,posY-50,posZ);
	//UNDER THE DOME 
	glEnable(GL_TEXTURE_2D);
	float angleStep = 2 * 3.14 / slices;
   // float stackHeight = height / stacks;
	float y=posY;
	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, under_dome);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUAD_STRIP);
	
        for (int j = 0; j <= slices; j++) {
            float angle = j * angleStep;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
        
			
			   glTexCoord2f(1.0f, 1.0f);	 glVertex3f(x, 50, z);
		   glTexCoord2f(1.0f, 0.0f);	  glVertex3f(x, 49.5, z);

	 glTexCoord2f(0.0f, 1.0f);	  glVertex3f(x, 50, z);
			  glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 49.5, z);
		


        }

        glEnd();
		glPopMatrix();


	}


 void DomeOfThechain::DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }



 void DomeOfThechain:: Cylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID) {
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


  void DomeOfThechain::  row( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int row_texture,int row_bottom_face) {
		
		glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, row_texture);
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

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, row_bottom_face);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	//Top Face

DrawQuad(p5,p6,p7,p8);

	//Bottom Face
DrawQuad(p1,p2,p3,p4);

	glDisable(GL_TEXTURE_2D);
}

  void DomeOfThechain::inside_roof(Point v1, Point v2, Point v3, Point v4,int triangle_texture,int triangle_abs_texture) {
	  	glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, triangle_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	  //left front triangle
    glBegin(GL_TRIANGLES);
   glTexCoord2f(1.0f, 0.0f); glVertex3f(v1.x, v1.y, v1.z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(v1.x, v1.y+0.5, v1.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f((v1.x+v4.x)/2, v1.y+0.5, v1.z);
    glEnd();

		  //left back triangle
	    glBegin(GL_TRIANGLES);
   glTexCoord2f(1.0f, 0.0f); glVertex3f(v2.x, v2.y, v2.z);
 glTexCoord2f(1.0f, 1.0f);   glVertex3f(v2.x, v2.y+0.5, v2.z);
 glTexCoord2f(0.0f, 1.0f);   glVertex3f((v1.x+v4.x)/2, v2.y+0.5, v2.z);
    glEnd();

		  //left triangle roof
	glBegin(GL_QUADS);
   glTexCoord2f(1.0f, 0.0f);  glVertex3f(v1.x, v1.y+0.5, v1.z);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(v2.x, v2.y+0.5, v2.z);
  glTexCoord2f(0.0f, 1.0f);    glVertex3f((v1.x+v3.x)/2, v2.y+0.5, v2.z);
 glTexCoord2f(0.0f, 0.0f); 	 glVertex3f((v1.x+v4.x)/2, v2.y+0.5, v1.z);
    glEnd();




	
			  //left triangle side
	glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);  glVertex3f(v1.x, v1.y, v1.z);
   glTexCoord2f(1.0f, 1.0f);  glVertex3f(v2.x, v2.y, v2.z);
    glTexCoord2f(0.0f, 1.0f);   glVertex3f(v2.x, v2.y+0.5, v2.z);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(v1.x, v1.y+0.5, v1.z);
    glEnd();

	glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, triangle_abs_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		  //left triangle bottom
	glBegin(GL_QUADS);
 glTexCoord2f(1.0f, 0.0f);   glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f);  glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);   glVertex3f((v1.x+v3.x)/2, v2.y+0.5, v2.z);
glTexCoord2f(0.0f, 0.0f);	 glVertex3f((v1.x+v4.x)/2, v2.y+0.5, v1.z);
    glEnd();

	glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, triangle_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	  //right front triangle
	  glBegin(GL_TRIANGLES);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(1.0f, 1.0f);  glVertex3f(v3.x, v3.y+0.5, v3.z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f((v1.x+v4.x)/2, v3.y+0.5, v3.z);
    glEnd();

	 //right back triangle
	    glBegin(GL_TRIANGLES);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(v4.x, v4.y, v4.z);
   glTexCoord2f(1.0f, 1.0f); glVertex3f(v4.x, v4.y+0.5, v4.z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f((v1.x+v4.x)/2, v4.y+0.5, v4.z);
    glEnd();

	//right triangle roof
glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(v3.x, v3.y+0.5, v3.z);
   glTexCoord2f(1.0f, 1.0f); glVertex3f(v4.x, v4.y+0.5, v4.z);
   glTexCoord2f(0.0f, 1.0f); glVertex3f((v1.x+v4.x)/2, v4.y+0.5, v4.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f((v1.x+v3.x)/2, v3.y+0.5, v3.z);
    glEnd();

	

			  //right triangle side
	glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);   glVertex3f(v3.x, v3.y, v3.z);
   glTexCoord2f(1.0f, 1.0f); glVertex3f(v4.x, v4.y, v4.z);
 glTexCoord2f(0.0f, 1.0f);   glVertex3f(v4.x, v4.y+0.5, v4.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(v3.x, v3.y+0.5, v3.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	
		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, triangle_abs_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		  //right triangle bottom
	glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v4.x, v4.y, v4.z);
   glTexCoord2f(1.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
   glTexCoord2f(0.0f, 1.0f);   glVertex3f((v1.x+v3.x)/2, v3.y+0.5, v3.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f((v1.x+v4.x)/2, v4.y+0.5, v4.z);
    glEnd();
		glDisable(GL_TEXTURE_2D);
  }
   void DomeOfThechain::roof(Point v1, Point v2, Point v3, Point v4,bool fix,int triangle_texture,int roof_texture,int triangle_abs_texture) {

	   		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, triangle_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);



	  //left front triangle
    glBegin(GL_TRIANGLES);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(v1.x, v1.y, v1.z);
   glTexCoord2f(1.0f, 1.0f);   glVertex3f(v1.x, v1.y+0.5, v1.z);
 glTexCoord2f(0.0f, 1.0f);   glVertex3f((v1.x+v4.x)/2, v1.y+0.5, v1.z);
    glEnd();

		  //left back triangle
	    glBegin(GL_TRIANGLES);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v2.x, v2.y+0.5, v2.z);
glTexCoord2f(0.0f, 1.0f);    glVertex3f((v1.x+v4.x)/2, v2.y+0.5, v2.z);
    glEnd();

		  //left triangle roof
	glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);  glVertex3f(v1.x, v1.y+0.5, v1.z);
   glTexCoord2f(1.0f, 1.0f);  glVertex3f(v2.x, v2.y+0.5, v2.z);
   glTexCoord2f(0.0f, 1.0f);    glVertex3f((v1.x+v3.x)/2, v2.y+0.5, v2.z);
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f((v1.x+v4.x)/2, v2.y+0.5, v1.z);
    glEnd();

	


	
			  //left triangle side
	glBegin(GL_QUADS);
     glTexCoord2f(1.0f, 0.0f); glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v2.x, v2.y, v2.z);
   glTexCoord2f(0.0f, 1.0f); glVertex3f(v2.x, v2.y+0.5, v2.z);
glTexCoord2f(0.0f, 0.0f);	 glVertex3f(v1.x, v1.y+0.5, v1.z);
    glEnd();


	glDisable(GL_TEXTURE_2D);
	//triangle abs 
	   		glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, triangle_abs_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);



		  //left triangle bottom
	glBegin(GL_QUADS);
   glTexCoord2f(1.0f, 0.0f);   glVertex3f(v1.x, v1.y, v1.z);
 glTexCoord2f(1.0f, 1.0f);   glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);    glVertex3f((v1.x+v3.x)/2, v2.y+0.5, v2.z);
glTexCoord2f(0.0f, 0.0f);	 glVertex3f((v1.x+v4.x)/2, v2.y+0.5, v1.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, triangle_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	  //right front triangle
	  glBegin(GL_TRIANGLES);
     glTexCoord2f(1.0f, 0.0f); glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v3.x, v3.y+0.5, v3.z);
   glTexCoord2f(0.0f, 1.0f); glVertex3f((v1.x+v4.x)/2, v3.y+0.5, v3.z);
    glEnd();

	 //right back triangle
	    glBegin(GL_TRIANGLES);
   glTexCoord2f(1.0f, 0.0f);   glVertex3f(v4.x, v4.y, v4.z);
glTexCoord2f(1.0f, 1.0f);    glVertex3f(v4.x, v4.y+0.5, v4.z);
 glTexCoord2f(0.0f, 1.0f);    glVertex3f((v1.x+v4.x)/2, v4.y+0.5, v4.z);
    glEnd();

	//right triangle roof
glBegin(GL_QUADS);
     glTexCoord2f(1.0f, 0.0f);  glVertex3f(v3.x, v3.y+0.5, v3.z);
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v4.x, v4.y+0.5, v4.z);
   glTexCoord2f(0.0f, 1.0f);  glVertex3f((v1.x+v4.x)/2, v4.y+0.5, v4.z);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f((v1.x+v3.x)/2, v3.y+0.5, v3.z);
    glEnd();

			

			  //right triangle side
	glBegin(GL_QUADS);
 glTexCoord2f(1.0f, 0.0f);   glVertex3f(v3.x, v3.y, v3.z);
 glTexCoord2f(1.0f, 1.0f);   glVertex3f(v4.x, v4.y, v4.z);
   glTexCoord2f(0.0f, 1.0f);  glVertex3f(v4.x, v4.y+0.5, v4.z);
 glTexCoord2f(0.0f, 0.0f);	 glVertex3f(v3.x, v3.y+0.5, v3.z);
    glEnd();

	
	glDisable(GL_TEXTURE_2D);
	//triangle abs 
	   		glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, triangle_abs_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	  //right triangle bottom
	glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);   glVertex3f(v4.x, v4.y, v4.z);
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v3.x, v3.y, v3.z);
   glTexCoord2f(0.0f, 1.0f);  glVertex3f((v1.x+v3.x)/2, v3.y+0.5, v3.z);
 glTexCoord2f(0.0f, 0.0f);	 glVertex3f((v1.x+v4.x)/2, v4.y+0.5, v4.z);
    glEnd();

		glDisable(GL_TEXTURE_2D);

	if(fix==true)
	{
			   		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, roof_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(v1.x, v1.y+0.5, v1.z);
  glTexCoord2f(1.0f, 1.0f);  glVertex3f(v4.x, v4.y+0.5, v4.z);
   glTexCoord2f(0.0f, 1.0f);   glVertex3f(v4.x, v4.y+0.5, v4.z+4);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(v1.x, v1.y+0.5, v1.z+4);
    glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, roof_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

				glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);  glVertex3f(v1.x, v1.y+0.5, v1.z);
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v4.x, v4.y+0.5, v4.z);
 glTexCoord2f(0.0f, 1.0f);   glVertex3f(v4.x, v4.y+0.5, v4.z+3);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(v1.x, v1.y+0.5, v1.z+3);
    glEnd();

		glDisable(GL_TEXTURE_2D);
	}
  }
  //add cylinder , roof .... texture
  void DomeOfThechain::DRAW_CHAIN( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int row_texture,int roof_texture,int cylinder_texture,int dome_texture,int under_dome_texture,int triangle_texture,int triangle_abs_texture,int row_bottom_face) {
	  //THE OUTSIDE
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	 
	  roof(p5,p6,p7,p8,true, triangle_texture,roof_texture,triangle_abs_texture);


	glPushMatrix();
	glTranslated(-2,0,2);
	glRotated(45,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-4,0,4);
	glRotated(45,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	  glPopMatrix();
	
		glPushMatrix();
	glTranslated(-4,0,7);
	glRotated(90,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();


		glPushMatrix();
	glTranslated(-2,0,9);
	glRotated(135,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();


		glPushMatrix();
	glTranslated(0,0,11);
	glRotated(135,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();



		glPushMatrix();
	glTranslated(3,0,11);
	glRotated(180,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,true, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();

		glPushMatrix();
	glTranslated(5,0,9);
	glRotated(225,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();

			glPushMatrix();
	glTranslated(7,0,7);
	glRotated(225,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();

	
			glPushMatrix();
	glTranslated(7,0,4);
	glRotated(270,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();

			glPushMatrix();
	glTranslated(5,0,2);
	glRotated(310,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();

		glPushMatrix();
	glTranslated(3.2,0,0);
	glRotated(310,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	  roof(p5,p6,p7,p8,false, triangle_texture,roof_texture,triangle_abs_texture);
	glPopMatrix();
	
		  //THE INSIDE

	p1.z+=3;
	p2.z+=3;
	p3.z+=3;
	p4.z+=3;
    p5.z+=3;
	p6.z+=3;
	p7.z+=3;
	p8.z+=3;

	 row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	 
	  inside_roof(p5,p6,p7,p8,triangle_texture,triangle_abs_texture);
	  CHAIN_DOME(2.5,40,40,p5.x+1.4,p5.y+1,p5.z+2.5,dome_texture,under_dome_texture);
	  glPushMatrix();
	glTranslated(-4,0,3);
	glRotated(45,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	 inside_roof(p5,p6,p7,p8,triangle_texture,triangle_abs_texture);
	 
	glPopMatrix();
	
	

		glPushMatrix();
	glTranslated(-2,0,9.5);
	glRotated(135,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	inside_roof(p5,p6,p7,p8,triangle_texture,triangle_abs_texture);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3,0,10.5);
	glRotated(180,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	inside_roof(p5,p6,p7,p8,triangle_texture,triangle_abs_texture);
	glPopMatrix();

		glPushMatrix();
	glTranslated(7,0,7.5);
	glRotated(225,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	inside_roof(p5,p6,p7,p8,triangle_texture,triangle_abs_texture);
	glPopMatrix();


	glPushMatrix();
	glTranslated(5,0,1);
	glRotated(315,0,1,0);
	  row(p1,p2,p3,p4,p5,p6,p7,p8,row_texture,row_bottom_face);
	  
	  Cylinder(p1.x+0.2,p1.y,p1.z+0.2,0.1,0.1,2,180,0,0,cylinder_texture);
	inside_roof(p5,p6,p7,p8,triangle_texture,triangle_abs_texture);
	glPopMatrix();
	
  }