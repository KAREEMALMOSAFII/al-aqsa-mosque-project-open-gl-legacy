#ifndef ARCH_H
#define ARCH_H
class arch
{
public:
void arch::  angel_roof( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int angel_texture);
void arch::   newpyramid( Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,int pyramid_texture);
void arch::   Cylinder(float x, float y, float z, float radius, float height, float topHeight, float rotateX, float rotateY, float rotateZ, GLuint textureID);
void arch::  DrawQuad(Point v1, Point v2, Point v3, Point v4);
void arch:: DrawAngle(Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int angel_texture,int pyramid_texture);
void arch:: DrawAngle_mosque(Point p1,Point p2,Point p3,Point p4,Point p5,Point p6,Point p7,Point p8,int angel_texture,int pyramid_texture);
void arch::  multi_wall_2( int n,int pyramid_texture) ;
void arch::  multi_wall_1( int n,int pyramid_texture) ;
void arch::  all_wals(int pyramid_texture) ;
void arch::  streets(int pyramid_texture,int home1,int home2,int home3,int home4,int home5,int home6,int home7) ;
};

#endif