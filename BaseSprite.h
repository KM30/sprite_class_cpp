#pragma once
#include"acllib.h"

typedef struct resets
{
	int x, y, width, height;
}reset;

class BaseSprite
{
protected:
	int x, y;
	int width, height;
	int dx, dy;
	ACL_Image* img;
	reset w;

public:
	BaseSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1);
	BaseSprite(BaseSprite& sprite);
	~BaseSprite();

	void move();

	void drawSprite();
	void drawSprite(int width,int height);

	reset getReset();
	int collision(reset s2);
};