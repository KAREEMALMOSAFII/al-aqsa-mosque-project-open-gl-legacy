#ifndef DOMEOFTHECHAIN_H
#define DOMEOFTHECHAIN_H
class DomeOfThechain
{
public:
	DomeOfThechain();
	
		  void Cylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID) ;
		   void row( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int row_texture,int row_bottom_face) ;
		   void DomeOfThechain::DRAW_CHAIN( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int row_texture,int roof_texture,int cylinder_texture,int dome_texture,int under_dome_texture,int triangle_texture,int triangle_abs_texture,int row_bottom_face);
		   void DomeOfThechain::roof(Point v1, Point v2, Point v3, Point v4,bool fix,int triangle_texture,int roof_texture,int triangle_abs_texture);
		   void DomeOfThechain::DrawQuad(Point v1, Point v2, Point v3, Point v4);
		     void DomeOfThechain::CHAIN_DOME(float radius, int slices, int stacks, float posX, float posY, float posZ, int dome,int under_dome);
			  void DomeOfThechain::inside_roof(Point v1, Point v2, Point v3, Point v4,int triangle_texture,int triangle_abs_texture);
};

#endif