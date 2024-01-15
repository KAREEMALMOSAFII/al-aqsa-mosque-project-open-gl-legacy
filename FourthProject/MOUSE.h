#ifndef MOUSE_H
#define MOUSE_H
class MOUSE
{
public:
void MOUSE:: mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked);
void MOUSE:: Key(bool* keys, float speed,Camera MyCamera,int px,int py,int pz,int pq,float the_time);
};

#endif