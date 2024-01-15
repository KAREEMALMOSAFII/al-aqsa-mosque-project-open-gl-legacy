#ifndef SKYBOX_H
#define SKYBOX_H
class SKYBOX
{
public:
	void SKYBOX:: Draw_Skybox(float x, float y, float z, float width, float height, float length,int SKYFRONT,int SKYBACK,int SKYLEFT,int SKYRIGHT,int SKYUP);
	void SKYBOX::day(int SKYFRONT,int SKYBACK,int SKYLEFT,int SKYRIGHT,int SKYUP);
	void SKYBOX::midday(int SKYFRONT,int SKYBACK,int SKYLEFT,int SKYRIGHT,int SKYUP);
		void SKYBOX::sunset(int SKYFRONT,int SKYBACK,int SKYLEFT,int SKYRIGHT,int SKYUP);
		void SKYBOX::night(int SKYFRONT,int SKYBACK,int SKYLEFT,int SKYRIGHT,int SKYUP);
};

#endif