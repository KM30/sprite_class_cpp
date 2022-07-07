#pragma once
#include "AutoSprite.h"

class AvoidSprite :
    public AutoSprite
{
    bool nears(reset us);
public:
    AvoidSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1);
    AvoidSprite(AvoidSprite& sprite);
    ~AvoidSprite();

    void move(reset us);
};

