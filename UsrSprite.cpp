#include "UsrSprite.h"

UsrSprite::UsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1)
	:BaseSprite(x, y, width, height, dx, dy, img, w1)
{
}

UsrSprite::UsrSprite(UsrSprite& sprite)
	: BaseSprite(sprite)
{
}

UsrSprite::~UsrSprite()
{
}



void UsrSprite::move(int key)
{
	switch (key)
	{
	case VK_UP:
		y -= key;
		if (y < w.y)
			y = w.y;
		break;
	case VK_DOWN:
		y += key;
		if (y > (w.y + w.height - height))
			y = (w.y + w.height - height);
		break;
	case VK_LEFT:
		x -= key;
		if (x < w.x)
			x = w.x;
		break;
	case VK_RIGHT:
		x += key;
		if (x > (w.x + w.width - width))
			x = (w.x + w.width - width);
		break;
	}
}

void UsrSprite::addScore()
{
	score += 1;
}

int UsrSprite::getScore()
{
	return score;
}