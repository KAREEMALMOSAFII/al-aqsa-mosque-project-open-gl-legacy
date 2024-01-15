#ifndef MOSQUE_H
#define MOSQUE_H

class Mosque
{
public:
	Mosque();
	void DrawDome(float radius, float height, int slices, int stacks, float x, float y, float z, float rotateX, float rotateY, float rotateZ,int dome,int under_dome);
	void DrawWall(Point v1, Point v2, Point v3, Point v4,Point r1,Point r2,int ball);
	  void Mosque::DrawQuad(Point v1, Point v2, Point v3, Point v4) ;
	  void Mosque::DrawRoof(Point v1, Point v2, Point v3, Point v4) ;
	    void Mosque::DOOR_WALL(Point v1, Point v2, Point v3, Point v4,int wall,int door,int under_dome,int above_wall,int quran,int quran2,int wood_window,float pz);
		 void Mosque::WALL(Point v1, Point v2, Point v3, Point v4,int wall,int door,int under_dome,int above_wall,int quran,float pz);
		 void Mosque::DRAWMOSQUE(Point v1, Point v2, Point v3, Point v4,int wall,int door,int under_dome,int above_wall,int quran,int quran2,int dome,int roof,int cylinder,int cylinder2, int wood_window,int wood,int under_gold_dome,int carpet,int flag,float pz);
		 void drawHalfBall(float radius, int slices, int stacks, float posX, float posY, float posZ, int dome,int under_dome);
		 void drawCylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID) ;
		 	  void Mosque:: drawhalfCylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID);
			   void Mosque::front_mosque(int angel_texture,int inside_angel_texture,int cylinder_texture,int carpet,int qibli_roof_texture,int second_qibli_roof_texture,int qibli_door,int qibli_above_door,int library_book,int library_sides,int flag,int qibli_window,float pz);
				     void Mosque::the_floor(Point v1, Point v2, Point v3, Point v4,int carpet);
	    void Mosque::the_qibli_roof(Point v1, Point v2, Point v3, Point v4,int qibli_roof_texture);
				    void Mosque::the_qibli_wall(Point v1, Point v2, Point v3, Point v4,int qibli_wall_texture,int texcoord);
					      void Mosque::library(Point p1,Point p2,Point p3,Point p4, int book,int sides);
						  	 void Mosque::qibliHalfBall(float radius, int slices, int stacks, float posX, float posY, float posZ, int dome,int under_dome);



};
#endif