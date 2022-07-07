#include "BaseSprite.h"

BaseSprite::BaseSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->dx = dx;
	this->dy = dy;
	this->img = img;
	w = w1;
}

BaseSprite::BaseSprite(BaseSprite& sprite)
{
	x = sprite.x;
	y = sprite.y;
	width = sprite.width;
	height = sprite.height;
	dx = sprite.dx;
	dy = sprite.dy;
	img = sprite.img;
	w = sprite.w;
}

BaseSprite::~BaseSprite()
{
}

void BaseSprite::move()
{
}

void BaseSprite::drawSprite()
{
	putImageScale(img, x, y, width, height);
}

void BaseSprite::drawSprite(int width, int height)
{
	this->width = width;
	this->height = height;
	putImageScale(img, x, y, width, height);
}

reset BaseSprite::getReset()
{
	reset rs = { x,y,width,height };
	return reset(rs);
}

int BaseSprite::collision(reset s2)
{
	reset s1 = { x,y, width, height };
	int c = 1;
	if (s1.x < s2.x && s1.x + s1.width >s2.x) 
	{
		if (s1.y > s2.y && s1.y < s2.y + s2.height)return c;
		if (s1.y <s2.y && s1.y + s1.height >s2.y)return c;
	}
	else 
	{
		if (s1.x > s2.x && s2.x + s2.width > s1.x)
		{
			if (s1.y > s2.y && s1.y < s2.y + s2.height)return c;
			if (s1.y <s2.y && s1.y + s1.height >s2.y)return c;
		}
	}
	c = 0;
	return c;
}