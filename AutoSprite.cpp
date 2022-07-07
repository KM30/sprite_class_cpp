#include "AutoSprite.h"

AutoSprite::AutoSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1)
	:BaseSprite(x,y,width,height,dx,dy,img,w1)
{
}

AutoSprite::AutoSprite(AutoSprite& sprite)
	:BaseSprite(sprite)
{
}

AutoSprite::~AutoSprite()
{
}

void AutoSprite::move(reset us)
{
	x += dx;
	y += dy;
	if (x<w.x || x>(w.x + w.width - width))dx *= -1;
	if (y<w.y || y>(w.y + w.height - height))dy *= -1;
}