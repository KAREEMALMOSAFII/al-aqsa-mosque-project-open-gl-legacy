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
Mosque::Mosque(){}

void Mosque::DrawDome(float radius, float height, int slices, int stacks, float x, float y, float z, float rotateX, float rotateY, float rotateZ,int dome,int under_dome) {
 
      glPushMatrix();  
	
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, dome);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	// Draw Front side
    glTranslatef(x, y, z);
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);

    float angleStep = 2 * 3.14 / slices;
    float stackHeight = height / stacks;

    for (int i = 0; i < stacks; i++) {
        float stackRadius = radius * sin((i / static_cast<float>(stacks)) * 3.14 / 2);
        float nextStackRadius = radius * sin(((i + 1) / static_cast<float>(stacks)) * 3.14 / 2);
        float stackY = i * stackHeight;
        float nextStackY = (i + 1) * stackHeight;

        glBegin(GL_QUAD_STRIP);

        for (int j = 0; j <= slices; j++) {
            float angle = j * angleStep;
            float x = stackRadius * cos(angle);
            float z = stackRadius * sin(angle);
            float nextX = nextStackRadius * cos(angle);
            float nextZ = nextStackRadius * sin(angle);

            glTexCoord2f(1.0f, 0.0f);  glVertex3f(x, stackY, z);
             glTexCoord2f(1.0f, 1.0f); glVertex3f(nextX, nextStackY, nextZ);
        }

        glEnd();
    }
	glDisable(GL_TEXTURE_2D);
	//UNDER THE DOME 
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, under_dome);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUAD_STRIP);

        for (int j = 0; j <= slices; j++) {
            float angle = j * angleStep;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
        
    
			   glTexCoord2f(1.0f, 0.0f);  glVertex3f(x, y-20, z);
			 glTexCoord2f(1.0f, 1.0f);  glVertex3f(x, y-40, z);

			   glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y-20, z);
			 glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y-40, z);
        }

        glEnd();
	


		/*
		glBegin(GL_QUAD_STRIP);

       //for (int j = 0; j <= slices; j++) {
    
       
    
			   glTexCoord2f(1.0f, 0.0f);  glVertex3f(x, y-20, 35);
			 glTexCoord2f(1.0f, 1.0f);  glVertex3f(x-40, y-20, 35);

			   glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y-20, z);
			 glTexCoord2f(0.0f, 1.0f);  glVertex3f(x-40, y-20, z);
      // }

        glEnd();

		glBegin(GL_QUAD_STRIP);

       //for (int j = 0; j <= slices; j++) {
    
       
    
			   glTexCoord2f(1.0f, 0.0f);  glVertex3f(x-40, y-20, 35);
			 glTexCoord2f(1.0f, 1.0f);  glVertex3f(x-60, y-20, 0);

			   glTexCoord2f(0.0f, 0.0f);  glVertex3f(x-40, y-20, z);
			 glTexCoord2f(0.0f, 1.0f);  glVertex3f(x-90, y-20, z-35);
      // }

        glEnd();

		//make it fans or quads
/*
	glBegin(GL_TRIANGLE_FAN);
	
	

glVertex3f(0,60,0);



glVertex3f(x, y-20, z);

	glVertex3f(x-40, y-20, z);
		glVertex3f(x-80, y-20, z-40);
	glEnd();
	
	*/
    glPopMatrix();
}
  


void Mosque::DrawWall(Point v1, Point v2, Point v3, Point v4,Point r1,Point r2,int ball) {	
	float width=abs(v1.x+v4.x);
	float height=40;
	//DrawDome(40,height,40,100,(v1.x+v4.x)/2,v2.y*(height/10),width+(width/2),180,0,0,dome);

//		drawWallMosque(Point(0,0,0),Point(0,20,0),Point(40,20,0),Point(40,0,0));
//drawDomeMosque(40,40,40,100,20,80,60,180,0,0);
	
	//front

	DrawQuad(v1,v2,v3,v4);
	r1=v2;
	r2=v3;
	r1.z+=25;
	r2.z+=25;
	
	DrawRoof(v2,r1,r2,v3);

	//front right
	v1=v4;
	v2=v3;
	v3.x+=width;
	v3.z+=width;
	v4.x+=width;
	v4.z+=width;

	DrawQuad(v1,v2,v3,v4);

		r1=v2;
	r2=v3;
	r1.z+=10;
	r1.x-=20;
	r2.x-=20;
	r2.z+=10;
	
	DrawRoof(v2,r1,r2,v3);

	// right

	v1=v4;
	v2=v3;
	v3.z+=width;
	v4.z+=width;
	DrawQuad(v1,v2,v3,v4);

	r1=v2;
	r2=v3;
	
	r1.x-=25;
	r2.x-=25;
	
	
	
	DrawRoof(v2,r1,r2,v3);
	//back right
	v1=v4;
	v2=v3;
	v3.x-=width;
	v3.z+=width;
	v4.x-=width;
	v4.z+=width;
	DrawQuad(v1,v2,v3,v4);


			r1=v2;
	r2=v3;
	r1.z-=5;
	r1.x-=25;
	r2.x-=5;
	r2.z-=25;
	
	DrawRoof(v2,r1,r2,v3);


	//back
	v1=v4;
	v2=v3;
	v3.x-=width;
	v4.x-=width;
	DrawQuad(v1,v2,v3,v4);


	  glLineWidth(50);
  glBegin(GL_LINES);
 
  /*
  glVertex3d(v3.x+width,v3.y,v3.z);
  glVertex3d(r2.x,r2.y,r2.z);

   glVertex3d(v3.x,v3.y,v3.z);
   glVertex3d(r2.x-width+2,r2.y,r2.z-3);
  glEnd();
	*/

  r1=v3;
  r1.x+=width;

  	DrawRoof(v2,r1,r2,v3);
  /*
		r1=v2;
	r2=v3;
	r1.z-=5;
	r1.x-=25;
	//r2.x-=5;
	//r2.z-=25;
	
	DrawRoof(v2,r1,r2,v3);
	*/

	//back left
	v1=v4;
	v2=v3;
	v3.x-=width;
	v3.z-=width;
	v4.x-=width;
	v4.z-=width;
	DrawQuad(v1,v2,v3,v4);

	// left
		v1=v4;
	v2=v3;
	v3.z-=width;
	v4.z-=width;
	DrawQuad(v1,v2,v3,v4);

	//front left
		v1=v4;
	v2=v3;
	v3.x+=width;
	v3.z-=width;
	v4.x+=width;
	v4.z-=width;
	DrawQuad(v1,v2,v3,v4);



  }



  void Mosque::DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

    void Mosque::the_floor(Point v1, Point v2, Point v3, Point v4,int carpet) {
			 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D, carpet);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_QUADS);
  glTexCoord2f(60.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(60.0f, 60.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 60.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);
  }

	    void Mosque::the_qibli_roof(Point v1, Point v2, Point v3, Point v4,int qibli_roof_texture) {
			 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D, qibli_roof_texture);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_QUADS);
  glTexCoord2f(10.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(10.0f, 10.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 10.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);
  }

		    void Mosque::the_qibli_wall(Point v1, Point v2, Point v3, Point v4,int qibli_wall_texture,int texcoord) {
			 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D, qibli_wall_texture);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_QUADS);
  glTexCoord2f(texcoord, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(texcoord, texcoord); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, texcoord);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);
  }
  // the width must be odd
    void Mosque::DOOR_WALL(Point v1, Point v2, Point v3, Point v4,int wall,int door,int under_dome,int above_wall,int quran,int quran2,int wood_window,float pz) {
	
		glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, wall);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	//LEFT WALL
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f((v3.x-10)/2, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f((v4.x-10)/2, v4.y, v4.z);
    glEnd();


	//RIGHT WALL
	    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f((v4.x-(v3.x-10)/2), v4.y, v4.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f((v3.x-(v3.x-10)/2), v3.y, v3.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();


	
	


	glDisable(GL_TEXTURE_2D);

	//	QURAN
		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, quran);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	  glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v2.x, v2.y*2, v2.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, (v2.y*2)+3, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, (v3.y*2)+3, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v3.y*2, v4.z);
    glEnd();


		glDisable(GL_TEXTURE_2D);
	// ABOVE THE DOOR
	glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, wood_window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
   glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);   glVertex3f((v3.x-10)/2, v3.y/2, v3.z);
  glTexCoord2f(1.0f, 1.0f);glVertex3f((v3.x-10)/2, v3.y, v3.z);
  glTexCoord2f(0.0f, 1.0f);   glVertex3f((v3.x-(v3.x-10)/2), v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f((v4.x-(v3.x-10)/2), v3.y/2, v4.z);  ;
    glEnd();


	glDisable(GL_TEXTURE_2D);



	//LEFT DOOR
	glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, door);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	glPushMatrix();

	//FIX THE DOOR OPENING
	glTranslated((v3.x-10)/2, v1.y, v3.z);

glRotated(pz,0,1,  0);

  glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(0, v1.y, v3.z);
  glTexCoord2f(1.0f, 1.0f);glVertex3f(0, v3.y/2, v4.z);

  glTexCoord2f(0.0f, 1.0f);   glVertex3f(5, v3.y/2, v4.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(5, v1.y, v3.z);
    glEnd();
	glPopMatrix();

	/*
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f((v3.x-10)/2, v1.y, v3.z);
  glTexCoord2f(1.0f, 1.0f);glVertex3f((v4.x-10)/2, v3.y/2, v4.z);

  glTexCoord2f(0.0f, 1.0f);   glVertex3f((v4.x-(v3.x-10)/2)-5, v3.y/2, v4.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f((v3.x-(v3.x-10)/2)-5, v1.y, v3.z);
    glEnd();
	glPopMatrix();*/
glDisable(GL_TEXTURE_2D);



//RIGHT DOOR 
glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, door);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glPushMatrix();
	glTranslated((v4.x-(v3.x-10)/2), v4.y, v4.z);

glRotated(-pz,0,1,  0);

 glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(0, v4.y, v4.z);  
  glTexCoord2f(1.0f, 1.0f);  glVertex3f(0, v3.y/2, v3.z);

  glTexCoord2f(0.0f, 1.0f);   glVertex3f(-5, v3.y/2, v4.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(-5, v4.y, v4.z);
    glEnd();

	/*
	 glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f((v4.x-(v3.x-10)/2), v4.y, v4.z);  
  glTexCoord2f(1.0f, 1.0f);  glVertex3f((v3.x-(v3.x-10)/2), v3.y/2, v3.z);

  glTexCoord2f(0.0f, 1.0f);   glVertex3f((v4.x-(v3.x-10)/2)-5, v3.y/2, v4.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f((v3.x-(v3.x-10)/2)-5, v4.y, v4.z);
    glEnd();
	*/
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	// zakharef
	glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, under_dome);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glPushMatrix();
	
	 glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v2.x, v2.y, v2.z);  
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v2.x, v2.y*2, v2.z);  

  glTexCoord2f(0.0f, 1.0f);    glVertex3f(v3.x, v2.y*2, v2.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v3.x, v2.y, v3.z); 
    glEnd();
			glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	}
	
  

  void Mosque::DrawRoof(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }





   void Mosque::WALL(Point v1, Point v2, Point v3, Point v4,int wall,int door,int under_dome,int above_wall,int quran,float pz) {
		glEnable(GL_TEXTURE_2D);

	// mosque_body
	glBindTexture(GL_TEXTURE_2D, wall);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();


	
	


	glDisable(GL_TEXTURE_2D);

	//	QURAN
		glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, quran);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	  glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v2.x, v2.y*2, v2.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, (v2.y*2)+3, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, (v3.y*2)+3, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v3.y*2, v4.z);
    glEnd();


		glDisable(GL_TEXTURE_2D);
	

	// zakharef
	glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, under_dome);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	
	 glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v2.x, v2.y, v2.z);  
  glTexCoord2f(1.0f, 1.0f);   glVertex3f(v2.x, v2.y*2, v2.z);  

  glTexCoord2f(0.0f, 1.0f);    glVertex3f(v3.x, v2.y*2, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v3.x, v2.y, v3.z); 
    glEnd();

	glDisable(GL_TEXTURE_2D);
	
  }


    void Mosque::drawHalfBall(float radius, int slices, int stacks, float posX, float posY, float posZ, int dome,int under_dome)
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
        
			
			   glTexCoord2f(1.0f, 1.0f);	 glVertex3f(x, y-20, z);
		   glTexCoord2f(1.0f, 0.0f);	  glVertex3f(x, y-40, z);

	 glTexCoord2f(0.0f, 1.0f);	  glVertex3f(x, y-20, z);
			  glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y-40, z);
		


        }

        glEnd();
		glPopMatrix();


	}
	
	 void Mosque::qibliHalfBall(float radius, int slices, int stacks, float posX, float posY, float posZ, int dome,int under_dome)
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

	/*glPushMatrix();
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
        
			
			   glTexCoord2f(1.0f, 1.0f);	 glVertex3f(x, y-20, z);
		   glTexCoord2f(1.0f, 0.0f);	  glVertex3f(x, y-40, z);

	 glTexCoord2f(0.0f, 1.0f);	  glVertex3f(x, y-20, z);
			  glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y-40, z);
		


        }

        glEnd();
		glPopMatrix();

		*/
	}
	 void Mosque:: drawCylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID) {
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
	  void Mosque:: drawhalfCylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID) {
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

    for (int i = 0; i <= sides/2; ++i) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glTexCoord2f((x / radius + 1) / 2, (z / radius + 1) / 2);
        glVertex3f(x, height / 2.0f + topHeight, z);
    }

    glEnd();
	/*
    glBegin(GL_TRIANGLE_FAN);
    
    // Draw the bottom circle
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, -height / 2.0f, 0.0f);

    for (int i = 0; i <= sides/2; ++i) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glTexCoord2f((x / radius + 1) / 2, (z / radius + 1) / 2);
        glVertex3f(x, -height / 2.0f, z);
    }

    glEnd();
	*/
    // Draw the sides of the cylinder
    glBegin(GL_QUAD_STRIP);
    
    for (int i = 0; i <= sides/2; ++i) {
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
	void myCube( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int texture) {
		PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
		glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);

	//Front Face
	
	
	primitiveDrawer.DrawQuad(p2,p6,p7,p3);


	//Back Face
	primitiveDrawer.DrawQuad(p1,p5,p8,p4);

	//Right Face
primitiveDrawer.DrawQuad(p8,p7,p3,p4);
	//Left Face
	primitiveDrawer.DrawQuad(p5,p6,p2,p1);

	//Top Face
	primitiveDrawer.DrawQuad(p5,p6,p7,p8);

	//Bottom Face
	primitiveDrawer.DrawQuad(p1,p2,p3,p4);

	
}

   void Mosque::DRAWMOSQUE(Point v1, Point v2, Point v3, Point v4,int wall,int door,int under_dome,int above_wall,int quran,int quran2,int dome,int roof,int cylinder,int cylinder2,int wood_window,int wood,int under_gold_dome,int carpet,int flag ,float pz)
   {


//	  drawCylinder(50,0,10,1,0,20,0,0,0,mosque_body);

	   float width=v3.x/2;
	   Point p1(0, 40, 0);
	    Point p2(0, 50, -80);
		 Point p3(110, 50, -80);
		  Point p4(110, 40, 0);

	   drawHalfBall(60,50,50,width,70,-(width*2)-20,dome,under_gold_dome);
	drawCylinder(width,131,-(width*2)-20,0.5,0,40,0,0,0,wall);
	glEnable(GL_TEXTURE_2D);
	// quran above door
	glBindTexture(GL_TEXTURE_2D, flag);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);    glVertex3f(width,161,-(width*2)-20);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(width,171,-(width*2)-20);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(width+25,171,-(width*2)-20);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(width+25,161,-(width*2)-20);
	 glEnd();
	 glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	// quran above door
	glBindTexture(GL_TEXTURE_2D, quran2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glPushMatrix();
	glTranslated((v3.x-10)/2, v2.y, v3.z);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);    glVertex3f(-4, 0, 2);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(-4, 12, 2);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(14,12, 2);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(14, 0, 2);
	 glEnd();
	glPopMatrix();
glDisable(GL_TEXTURE_2D);
	
	  DOOR_WALL(v1,v2,v3,v4,wall,door,under_dome,above_wall,quran,quran2,wood_window,pz);
	    //middle carpet
		 	  the_floor(Point(v1.x,v1.y+0.1,v1.z),Point(v1.x,v1.y+0.1,v1.z-266),Point(v4.x,v4.y+0.1,v4.z-266),Point(v4.x,v4.y+0.1,v4.z),carpet);

			  //right carpet
			  		 	  the_floor(Point(v4.x,v4.y+0.1,v4.z),Point(v4.x,v4.y+0.1,v4.z-265),Point(v4.x+77.7,v4.y+0.1,v4.z-187.8),Point(v4.x+77.7,v4.y+0.1,v4.z-78),carpet);

						  //left carpet
					 	  the_floor(Point(v1.x,v1.y+0.1,v1.z),Point(v1.x,v1.y+0.1,v1.z-265),Point(v1.x-77.7,v1.y+0.1,v1.z-187.8),Point(v1.x-77.7,v1.y+0.1,v1.z-78),carpet);


	//  myCube(Point(v1.x+10,v2.y,v1.z+12),Point(v1.x+10,v2.y,v1.z+0.3),Point(v3.x-10,v3.y,v3.z+0.3),Point(v3.x-10,v3.y,v3.z+12),Point(v1.x+10,v2.y+2,v1.z+12),Point(v1.x+10,v2.y+2,v1.z+0.3),Point(v3.x-10,v3.y+2,v3.z+0.3),Point(v3.x-10,v3.y+2,v3.z+12),wood);
	  //left roof
	  	  myCube(Point(v1.x+10,v2.y,v1.z+12),Point(v1.x+10,v2.y,v1.z+0.3),Point((v3.x/2)-8,v3.y,v3.z+0.3),Point((v3.x/2)-8,v3.y,v3.z+12),Point(v1.x+10,v2.y+2,v1.z+12),Point(v1.x+10,v2.y+2,v1.z+0.3),Point((v3.x/2)-8,v3.y+2,v3.z+0.3),Point((v3.x/2)-8,v3.y+2,v3.z+12),wood);
		  //right roof
		   myCube(Point((v3.x/2)+8,v2.y,v1.z+12),Point((v3.x/2)+8,v2.y,v1.z+0.3),Point(v3.x-10,v3.y,v3.z+0.3),Point(v3.x-10,v3.y,v3.z+12),Point((v3.x/2)+8,v2.y+2,v1.z+12),Point((v3.x/2)+8,v2.y+2,v1.z+0.3),Point(v3.x-10,v3.y+2,v3.z+0.3),Point(v3.x-10,v3.y+2,v3.z+12),wood);

	   drawhalfCylinder((v3.x/2),v1.y+20,v1.z+12,12,0,11.5,-90,0,0,wood);

	 drawCylinder((v3.x/2)-10,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);

	 drawCylinder((v3.x/2)-20,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

	 drawCylinder((v3.x/2)-33,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

	 drawCylinder((v3.x/2)-43,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);
	 

	 
	 drawCylinder((v3.x/2)+10,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);

	 drawCylinder((v3.x/2)+20,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

	 drawCylinder((v3.x/2)+33,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

	 drawCylinder((v3.x/2)+43,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);
	 

	  glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
	 DrawRoof(p1,p2,p3,p4);
	 glDisable(GL_TEXTURE_2D);
	  glPushMatrix();
	  glTranslated(v3.x,0,0);
	
	  glRotated(45,0,1,0);
	     WALL(v1,v2,v3,v4,wall,door,under_dome,above_wall,quran,pz);





		   glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
		 DrawRoof(p1,p2,p3,p4);
		  glDisable(GL_TEXTURE_2D);
		 glPopMatrix();
	
	  glPushMatrix();
	  glTranslated(v3.x+width+22.7,0,v4.z-width-22.7);
	  glRotated(90,0,1,0);
	  DOOR_WALL(v1,v2,v3,v4,wall,door,under_dome,above_wall,quran,quran2,wood_window,pz);

	   // myCube(Point(v1.x+10,v2.y,v1.z+12),Point(v1.x+10,v2.y,v1.z+0.3),Point(v3.x-10,v3.y,v3.z+0.3),Point(v3.x-10,v3.y,v3.z+12),Point(v1.x+10,v2.y+2,v1.z+12),Point(v1.x+10,v2.y+2,v1.z+0.3),Point(v3.x-10,v3.y+2,v3.z+0.3),Point(v3.x-10,v3.y+2,v3.z+12),wood);


		 drawCylinder((v3.x/2)-10,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

		 myCube(Point((v3.x/2)-12,v1.y+20,v1.z+12),Point((v3.x/2)-12,v1.y+20,v1.z+0.3),Point((v3.x/2)-8,v1.y+20,v1.z+0.3),Point((v3.x/2)-8,v1.y+20,v1.z+12),Point((v3.x/2)-12,v1.y+22,v1.z+12),Point((v3.x/2)-12,v1.y+22,v1.z+0.3),Point((v3.x/2)-8,v1.y+22,v1.z+0.3),Point((v3.x/2)-8,v1.y+22,v1.z+12),cylinder2);
		 drawhalfCylinder((v3.x/2),v1.y+20,v1.z+12,12,0,11.5,-90,0,0,wood);
	// drawCylinder((v3.x/2)-20,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);

	// drawCylinder((v3.x/2)-33,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);

	// drawCylinder((v3.x/2)-43,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);
	 

	 
	 drawCylinder((v3.x/2)+10,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

	 		 myCube(Point((v3.x/2)+12,v1.y+20,v1.z+11.9),Point((v3.x/2)+12,v1.y+20,v1.z+0.3),Point((v3.x/2)+8,v1.y+20,v1.z+0.3),Point((v3.x/2)+8,v1.y+20,v1.z+11.9),Point((v3.x/2)+12,v1.y+22,v1.z+11.9),Point((v3.x/2)+12,v1.y+22,v1.z+0.3),Point((v3.x/2)+8,v1.y+22,v1.z+0.3),Point((v3.x/2)+8,v1.y+22,v1.z+11.9),cylinder2);


	// drawCylinder((v3.x/2)+20,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);

	 //drawCylinder((v3.x/2)+33,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);

	 //drawCylinder((v3.x/2)+43,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder);
	    glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
	   DrawRoof(p1,p2,p3,p4);
	   	  glDisable(GL_TEXTURE_2D);
	  glPopMatrix();


	    glPushMatrix();
	  glTranslated(v3.x+width+22.7,0,v4.z-(width*3)-22.7);
	
	  glRotated(135,0,1,0);
	     WALL(v1,v2,v3,v4,wall,door,under_dome,above_wall,quran,pz);

		   glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
		 DrawRoof(p1,p2,p3,p4);
		  glDisable(GL_TEXTURE_2D);
		 glPopMatrix();


		 	  glPushMatrix();
	  glTranslated(0,0,v4.z-(width*4)-45.5);
	
	  DOOR_WALL(v1,v2,v3,v4,wall,door,under_dome,above_wall,quran,quran2,wood_window,pz);

	  	   //FIXX THIS SHIT 

	  // myCube(Point(v1.x+10,v2.y,v1.z-0.3),Point(v1.x+10,v2.y,v1.z-12),Point(v3.x-10,v3.y,v3.z-12),Point(v3.x-10,v3.y,v3.z-0.3),Point(v1.x+10,v2.y+2,v1.z-0.3),Point(v1.x+10,v2.y+2,v1.z-12),Point(v3.x-10,v3.y+2,v3.z-12),Point(v3.x-10,v3.y+2,v3.z-0.3),wood);


		 drawCylinder((v3.x/2)-10,v1.y,v1.z-10,1.5,0,20,0,0,0,cylinder2);
		 glPushMatrix();
		 glTranslated(0,0,-12.6);
		  myCube(Point((v3.x/2)-12,v1.y+20,v1.z+12),Point((v3.x/2)-12,v1.y+20,v1.z+0.3),Point((v3.x/2)-8,v1.y+20,v1.z+0.3),Point((v3.x/2)-8,v1.y+20,v1.z+12),Point((v3.x/2)-12,v1.y+22,v1.z+12),Point((v3.x/2)-12,v1.y+22,v1.z+0.3),Point((v3.x/2)-8,v1.y+22,v1.z+0.3),Point((v3.x/2)-8,v1.y+22,v1.z+12),cylinder2);
		 drawhalfCylinder((v3.x/2),v1.y+20,v1.z+12,12,0,11.5,-90,0,0,wood);
		 	 	 		 myCube(Point((v3.x/2)+12,v1.y+20,v1.z+11.9),Point((v3.x/2)+12,v1.y+20,v1.z+0.3),Point((v3.x/2)+8,v1.y+20,v1.z+0.3),Point((v3.x/2)+8,v1.y+20,v1.z+11.9),Point((v3.x/2)+12,v1.y+22,v1.z+11.9),Point((v3.x/2)+12,v1.y+22,v1.z+0.3),Point((v3.x/2)+8,v1.y+22,v1.z+0.3),Point((v3.x/2)+8,v1.y+22,v1.z+11.9),cylinder2);

		 glPopMatrix();


	 
	 drawCylinder((v3.x/2)+10,v1.y,v1.z-10,1.5,0,20,0,0,0,cylinder2);


	 
	  	  glPushMatrix();
	  glTranslated(0,0,v4.z+(width)+25);
	 
	   glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
	     glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(p2.x, p1.y, p2.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(p1.x, p1.y+10, p1.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(p4.x, p1.y+10, p4.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(p3.x, p1.y, p3.z);
    glEnd();
	  glDisable(GL_TEXTURE_2D);
	  glPopMatrix();

	    glPopMatrix();

	     glPushMatrix();
	  glTranslated(v3.x-(width)-55,0,v4.z-(width*4)-45.5);
	
	  glRotated(225,0,1,0);
	     WALL(v1,v2,v3,v4,wall,door,under_dome,above_wall,quran,pz);

		  glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
		 DrawRoof(p1,p2,p3,p4);
		   glDisable(GL_TEXTURE_2D);
		 glPopMatrix();



		 	  glPushMatrix();
	  glTranslated(v3.x-(width*3)-22.7,0,v4.z-(width*3)-22.799);
	  glRotated(270,0,1,0);
	  DOOR_WALL(v1,v2,v3,v4,wall,door,under_dome, above_wall,quran,quran2,wood_window,pz);

	  //LEFT DOOR
	
	  

			 drawCylinder((v3.x/2)-10,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

			   myCube(Point((v3.x/2)-12,v1.y+20,v1.z+12),Point((v3.x/2)-12,v1.y+20,v1.z+0.3),Point((v3.x/2)-8,v1.y+20,v1.z+0.3),Point((v3.x/2)-8,v1.y+20,v1.z+12),Point((v3.x/2)-12,v1.y+22,v1.z+12),Point((v3.x/2)-12,v1.y+22,v1.z+0.3),Point((v3.x/2)-8,v1.y+22,v1.z+0.3),Point((v3.x/2)-8,v1.y+22,v1.z+12),cylinder2);
		 drawhalfCylinder((v3.x/2),v1.y+20,v1.z+12,12,0,11.5,-90,0,0,wood);


	 

	 
	 drawCylinder((v3.x/2)+10,v1.y,v1.z+10,1.5,0,20,0,0,0,cylinder2);

	 	 	 		 myCube(Point((v3.x/2)+12,v1.y+20,v1.z+11.9),Point((v3.x/2)+12,v1.y+20,v1.z+0.3),Point((v3.x/2)+8,v1.y+20,v1.z+0.3),Point((v3.x/2)+8,v1.y+20,v1.z+11.9),Point((v3.x/2)+12,v1.y+22,v1.z+11.9),Point((v3.x/2)+12,v1.y+22,v1.z+0.3),Point((v3.x/2)+8,v1.y+22,v1.z+0.3),Point((v3.x/2)+8,v1.y+22,v1.z+11.9),cylinder2);




	    glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
	   DrawRoof(p1,p2,p3,p4);
	      glDisable(GL_TEXTURE_2D);
	  glPopMatrix();


	      glPushMatrix();
	 glTranslated(v3.x-(width*3)-22.7,0,v4.z-(width)-23);
	
	  glRotated(315,0,1,0);
	     WALL(v1,v2,v3,v4,wall,door,under_dome, above_wall,quran,pz);

		  glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, roof);
		 DrawRoof(p1,p2,p3,p4);
		  glDisable(GL_TEXTURE_2D);
		 glPopMatrix();


   }

      void Mosque::library(Point p1,Point p2,Point p3,Point p4, int book,int sides)
	  {
		  
				 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,book );
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	    glBegin(GL_QUADS);
  glTexCoord2f(2.0f, 0.0f);    glVertex3f(p1.x, p1.y, p1.z);
  glTexCoord2f(2.0f,2.0f); glVertex3f(p2.x, p2.y, p2.z);
  glTexCoord2f(0.0f, 2.0f);  glVertex3f(p3.x, p3.y, p3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(p4.x, p4.y, p4.z);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

			 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,sides );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	DrawQuad(p1,p2,Point(p2.x,p2.y,p2.z+10),Point(p2.x,p1.y,p2.z+10));
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

		 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,sides );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	DrawQuad(p4,p3,Point(p3.x,p3.y,p3.z+10),Point(p3.x,p4.y,p3.z+10));
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

			 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,sides );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	DrawQuad(p2,Point(p2.x,p2.y,p2.z+10),Point(p3.x,p3.y,p3.z+10),p3);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();




	  }


   void Mosque::front_mosque(int angel_texture,int inside_angel_texture,int cylinder_texture,int carpet,int qibli_roof_texture,int second_qibli_roof_texture,int qibli_door,int qibli_above_door,int library_book,int library_sides,int flag,int qibli_window,float pz)
   {
	
	   arch ar=arch();
	   glPushMatrix();
	   library(Point(1075,983,3990),Point(1075,1020,3990),Point(1100,1020,3990),Point(1100,983,3990),library_book,library_sides);
	      library(Point(1100,983,3990),Point(1100,1020,3990),Point(1125,1020,3990),Point(1125,983,3990),library_book,library_sides);

	    library(Point(1125,983,3990),Point(1125,1020,3990),Point(1150,1020,3990),Point(1150,983,3990),library_book,library_sides);

		 library(Point(1175,983,3990),Point(1175,1020,3990),Point(1200,1020,3990),Point(1200,983,3990),library_book,library_sides);

		  library(Point(1200,983,3990),Point(1200,1020,3990),Point(1225,1020,3990),Point(1225,983,3990),library_book,library_sides);

		 library(Point(1225,983,3990),Point(1225,1020,3990),Point(1250,1020,3990),Point(1250,983,3990),library_book,library_sides);

		  library(Point(1275,983,3990),Point(1275,1020,3990),Point(1300,1020,3990),Point(1300,983,3990),library_book,library_sides);
			 		
		   library(Point(1300,983,3990),Point(1300,1020,3990),Point(1325,1020,3990),Point(1325,983,3990),library_book,library_sides);
		   library(Point(1325,983,3990),Point(1325,1020,3990),Point(1350,1020,3990),Point(1350,983,3990),library_book,library_sides);
				
      	  library(Point(1375,983,3990),Point(1375,1020,3990),Point(1400,1020,3990),Point(1400,983,3990),library_book,library_sides);
		    library(Point(1400,983,3990),Point(1400,1020,3990),Point(1425,1020,3990),Point(1425,983,3990),library_book,library_sides);

		library(Point(1425,983,3990),Point(1425,1020,3990),Point(1450,1020,3990),Point(1450,983,3990),library_book,library_sides);

		library(Point(1475,983,3990),Point(1475,1020,3990),Point(1500,1020,3990),Point(1500,983,3990),library_book,library_sides);
		library(Point(1500,983,3990),Point(1500,1020,3990),Point(1525,1020,3990),Point(1525,983,3990),library_book,library_sides);
		library(Point(1525,983,3990),Point(1525,1020,3990),Point(1550,1020,3990),Point(1550,983,3990),library_book,library_sides);

						  					  	


	   glPopMatrix();
	   //fron right
	the_qibli_wall(Point(1050,980,3000),Point(1300,980,3000),Point(1300,1060,3000),Point(1050,1060,3000),angel_texture,10);


	   //right
		
		    the_qibli_wall(Point(1050,980,3000),Point(1050,980,3250),Point(1050,1060,3250),Point(1050,1060,3000),angel_texture,4);

		  the_qibli_wall(Point(1050,980,3250),Point(1050,980,3500),Point(1050,1060,3500),Point(1050,1060,3250),angel_texture,4);

		 the_qibli_wall(Point(1050,980,3500),Point(1050,980,3750),Point(1050,1060,3750),Point(1050,1060,3500),angel_texture,4);

		 the_qibli_wall(Point(1050,980,3750),Point(1050,980,4000),Point(1050,1060,4000),Point(1050,1060,3750),angel_texture,4);


	  // front left
	     the_qibli_wall(Point(1580,980,3000),Point(1330,980,3000),Point(1330,1060,3000),Point(1580,1060,3000),angel_texture,10);


		  //left

		  the_qibli_wall(Point(1580,980,3000),Point(1580,980,3250),Point(1580,1060,3250),Point(1580,1060,3000),angel_texture,4);

		  the_qibli_wall(Point(1580,980,3250),Point(1580,980,3500),Point(1580,1060,3500),Point(1580,1060,3250),angel_texture,4);

		 the_qibli_wall(Point(1580,980,3500),Point(1580,980,3750),Point(1580,1060,3750),Point(1580,1060,3500),angel_texture,4);

		 the_qibli_wall(Point(1580,980,3750),Point(1580,980,4000),Point(1580,1060,4000),Point(1580,1060,3750),angel_texture,4);
	
		  //FLAGS
		     the_qibli_wall(Point(1583,1000,4000),Point(1583,1060,4000),Point(1583,1060,3980),Point(1583,1000,3980),flag,1);

			     the_qibli_wall(Point(1583,1000,3900),Point(1583,1060,3900),Point(1583,1060,3880),Point(1583,1000,3880),flag,1);

			   the_qibli_wall(Point(1583,1000,3800),Point(1583,1060,3800),Point(1583,1060,3780),Point(1583,1000,3780),flag,1);
			   
			    the_qibli_wall(Point(1583,1000,3700),Point(1583,1060,3700),Point(1583,1060,3680),Point(1583,1000,3680),flag,1);

			      the_qibli_wall(Point(1583,1000,3600),Point(1583,1060,3600),Point(1583,1060,3580),Point(1583,1000,3580),flag,1);

				  the_qibli_wall(Point(1583,1000,3500),Point(1583,1060,3500),Point(1583,1060,3480),Point(1583,1000,3480),flag,1);

				  		      the_qibli_wall(Point(1583,1000,3400),Point(1583,1060,3400),Point(1583,1060,3380),Point(1583,1000,3380),flag,1);

							  the_qibli_wall(Point(1583,1000,3300),Point(1583,1060,3300),Point(1583,1060,3280),Point(1583,1000,3280),flag,1);

							        the_qibli_wall(Point(1583,1000,3200),Point(1583,1060,3200),Point(1583,1060,3180),Point(1583,1000,3180),flag,1);

									    the_qibli_wall(Point(1583,1000,3100),Point(1583,1060,3100),Point(1583,1060,3080),Point(1583,1000,3080),flag,1);

		  //back
		    the_qibli_wall(Point(1050,980,4000),Point(1580,980,4000),Point(1580,1060,4000),Point(1050,1060,4000),angel_texture,10);
			
			//above door
			the_qibli_wall(Point(1300,1015,3000),Point(1330,1015,3000),Point(1330,1038,3000),Point(1300,1038,3000),qibli_above_door,1);
			     glDisable(GL_TEXTURE_2D);
			     //door
	
				 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1300,980,3000);
	
glRotated(pz,0,1,  0);

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();

			   	//left door
		  glPushMatrix();
		  	glTranslated(1330,980,3000);
		
		 glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();


			   			 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1380,980,3000);
	

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();

			   	//left door
		  glPushMatrix();
		  	glTranslated(1410,980,3000);
		
		// glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();


			   
			   			 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1460,980,3000);
	
//glRotated(pz,0,1,  0);

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();

			   	//left door
		  glPushMatrix();
		  	glTranslated(1490,980,3000);
		
		// glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();


			   	 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1150,980,3000);
	
//glRotated(pz,0,1,  0);

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();
		  //	   DrawQuad(Point(1300,980,3000),Point(1300,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   	//left door
		  glPushMatrix();
		  	glTranslated(1180,980,3000);
		
		// glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));
		  	//   DrawQuad(Point(1330,980,3000),Point(1330,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();

			    glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1220,980,3000);
	
//glRotated(pz,0,1,  0);

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();
		  //	   DrawQuad(Point(1300,980,3000),Point(1300,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   	//left door
		  glPushMatrix();
		  	glTranslated(1250,980,3000);
		
		// glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));
		  	//   DrawQuad(Point(1330,980,3000),Point(1330,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();

			   
			   	 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1080,980,3000);
	
//glRotated(pz,0,1,  0);

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();
		  //	   DrawQuad(Point(1300,980,3000),Point(1300,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   	//left door
		  glPushMatrix();
		  	glTranslated(1110,980,3000);
		
		// glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));
		  	//   DrawQuad(Point(1330,980,3000),Point(1330,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();


			   
			   	 glPushMatrix();
				 glEnable(GL_TEXTURE_2D);
				 	glBindTexture(GL_TEXTURE_2D,qibli_door );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTranslated(1530,980,3000);
	
//glRotated(pz,0,1,  0);

//right door
		 DrawQuad(Point(0,0,0),Point(0,35,0),Point(15,35,0),Point(15,0,0));
		  glPopMatrix();
		  //	   DrawQuad(Point(1300,980,3000),Point(1300,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   	//left door
		  glPushMatrix();
		  	glTranslated(1560,980,3000);
		
		// glRotated(-pz,0,1,  0);

		  DrawQuad(Point(0,0,0),Point(0,35,0),Point(-15,35,0),Point(-15,0,0));
		  	//   DrawQuad(Point(1330,980,3000),Point(1330,1015,3000),Point(1315,1015,3000),Point(1315,980,3000));

			   glDisable(GL_TEXTURE_2D);
			   glPopMatrix();


			   //angel
			    glPushMatrix();
			   glTranslated(1050,1045,2940);
			    glScaled(8,8,8);

				ar.DrawAngle_mosque(Point(0,-1,0),Point(0,-1,7.3),Point(66,-1,7.3),Point(66,-1,0),Point(0,2,0),Point(0,2,7.3),Point(66,2,7.3),Point(66,2,0),angel_texture,angel_texture);

				 glPopMatrix();
				 
				 //floor
			
	the_floor(Point(1050,982.5,4000),Point(1050,982.5,3000),Point(1580,982.5,3000),Point(1580,982.5,4000),carpet);
				  	
				 //roof 
	the_qibli_roof(Point(1050,1060,4000),Point(1050,1060,3000),Point(1580,1060,3000),Point(1580,1060,4000),qibli_roof_texture);

					   //above the roof
				
						
					   //right
					     the_qibli_roof(Point(1580,1070,3000),Point(1580,1070,4000),Point(1580,1061,4000),Point(1580,1061,3000),second_qibli_roof_texture);

						 //front
						  the_qibli_roof(Point(1580,1070,3000),Point(1280,1070,3000),Point(1280,1061,3000),Point(1580,1061,3000),second_qibli_roof_texture);

						  //back
						    the_qibli_roof(Point(1580,1070,4000),Point(1280,1070,4000),Point(1280,1061,4000),Point(1580,1061,4000),second_qibli_roof_texture);

							//left

							  the_qibli_roof(Point(1280,1070,3000),Point(1280,1070,4000),Point(1280,1061,4000),Point(1280,1061,3000),second_qibli_roof_texture);

							  //second roof
					     the_qibli_roof(Point(1580,1070,3000),Point(1580,1070,4000),Point(1280,1070,4000),Point(1280,1070,3000),second_qibli_roof_texture);
						
						 	   qibliHalfBall(60,50,50,1430,1070,3800,second_qibli_roof_texture,angel_texture);

							   	    glPushMatrix();
//first cylinder row from right


		ar.Cylinder(1155,970,3880,7,0,100,0,0,0,cylinder_texture);

	//	ar.Cylinder(1155,970,3880,7.2,0,10,0,0,0,library_book);
				
		ar.Cylinder(1155,970,3760,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1155,970,3640,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1155,970,3520,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1155,970,3400,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1155,970,3280,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1155,970,3160,7,0,100,0,0,0,cylinder_texture);
							
			//newpyramid(Point(p8.x-8,p1.y-2,p1.z+2),Point(p8.x-6,p1.y,p2.z),Point(p8.x-6,p1.y,p1.z),Point(p8.x-10,p1.y,p1.z),Point(p8.x-10,p1.y,p2.z),Point(p8.x-6,p1.y,p2.z),pyramid_texture);

							
		//second cylinder row from right
	  	ar.Cylinder(1261,970,3880,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1261,970,3760,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1261,970,3640,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1261,970,3520,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1261,970,3400,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1261,970,3280,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1261,970,3160,7,0,100,0,0,0,cylinder_texture);

		//third cylinder row from right
		ar.Cylinder(1367,970,3880,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1367,970,3760,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1367,970,3640,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1367,970,3520,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1367,970,3400,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1367,970,3280,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1367,970,3160,7,0,100,0,0,0,cylinder_texture);

				//fourth cylinder row from right
	    ar.Cylinder(1473,970,3880,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1473,970,3760,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1473,970,3640,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1473,970,3520,7,0,100,0,0,0,cylinder_texture);

	    ar.Cylinder(1473,970,3400,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1473,970,3280,7,0,100,0,0,0,cylinder_texture);

		ar.Cylinder(1473,970,3160,7,0,100,0,0,0,cylinder_texture);

	


		glPopMatrix();

   }