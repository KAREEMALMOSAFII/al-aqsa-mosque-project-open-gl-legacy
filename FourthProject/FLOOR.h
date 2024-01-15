#ifndef FLOOR_H
#define FLOOR_H

class FLOOR
{
public:
	FLOOR();
	void FLOOR:: garden(Point v1, Point v2, Point v3, Point v4,int garden_texture);
void FLOOR::DRAWFLOOR(int floor_texture,int floor_wall_texture,int garden_texture,int door);
void newstairs( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int stair_counter,int stairs_texture);
void FLOOR:: DrawQuad(Point v1, Point v2, Point v3, Point v4);
};

#endif