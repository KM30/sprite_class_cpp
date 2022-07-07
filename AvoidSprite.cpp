#include "AvoidSprite.h"
#include<math.h>

bool AvoidSprite::nears(reset us)
{
	int ax = (x + width) / 2;
	int ay = (y + height) / 2;
	int ux = (us.x + us.width) / 2;
	int uy = (us.y + us.height) / 2;
	int dist = int(sqrt((ax - ux) * (ax - ux) + (ay - uy) * (ay - uy)));
	int osdist = 66;
	if (dist < osdist)
		return true;
	else
		return false;
}

AvoidSprite::AvoidSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1)
	:AutoSprite(x,y,width,height,dx,dy,img,w1)
{
}

AvoidSprite::AvoidSprite(AvoidSprite& sprite)
	:AutoSprite(sprite)
{
}

AvoidSprite::~AvoidSprite()
{
}

void AvoidSprite::move(reset us)
{
	if (nears(us))
	{	
		dx *= 5;
		dy *= 5;
		if (x < us.x)
			dx = -abs(dx);
		else
			dx = abs(dx);
		if (y < us.y)
			dy = -abs(dy);
		else
			dy = abs(dy);
		x += dx;
		y += dy;
		if (x<w.x || x>(w.x + w.width - width))dx *= -1;
		if (y<w.y || y>(w.y + w.height - height))dy *= -1;
		dx /= 5;
		dy /= 5;
	}
	else
	{
		x += dx;
		y += dy;
		if (x<w.x || x>(w.x + w.width - width))dx *= -1;
		if (y<w.y || y>(w.y + w.height - height))dy *= -1;
	}
}
