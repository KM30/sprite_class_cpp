#pragma once
#include "BaseSprite.h"

class AutoSprite :
    public BaseSprite
{
public:
    AutoSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1);
    AutoSprite(AutoSprite& sprite);
    virtual ~AutoSprite();

    virtual void move(reset us);
};