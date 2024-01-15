
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "Point.h"
#include "PrimitiveDrawer.h"

PrimitiveDrawer::PrimitiveDrawer(){}

// Draw a point at the given position.
void PrimitiveDrawer::DrawPoint(Point point) {
    glBegin(GL_POINTS);
	glVertex3f(point.x,point.y,point.z);
    glEnd();
  }

 // Draw a line between the given two positions.
void PrimitiveDrawer::DrawLine(Point start, Point end) {
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
  }

 // Draw a triangle with the given three vertices.
void PrimitiveDrawer::DrawTriangle(Point v1, Point v2, Point v3) {
    glBegin(GL_TRIANGLES);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
  }

void PrimitiveDrawer::DrawPyramid(Point v1, Point v2, Point v3, Point v4, Point v5, Point v6) {
	glBegin(GL_TRIANGLE_FAN);
  glTexCoord2f(1.0f, 0.0f);  glVertex3f(v1.x, v1.y, v1.z);
   glTexCoord2f(1.0f, 1.0f);  glVertex3f(v2.x, v2.y, v2.z);
 glTexCoord2f(0.0f, 1.0f);   glVertex3f(v3.x, v3.y, v3.z);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v5.x, v5.y, v5.z);
	 glTexCoord2f(1.0f, 1.0f);glVertex3f(v6.x, v6.y, v6.z);
    glEnd();
  }

// Draw a quadrilateral with the given four vertices.


//remoooooove the stairs texture !!!!!!!!!!!!!!!!!!!!!!
  void PrimitiveDrawer::DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f);    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2f(0.0f, 0.0f);glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }
 