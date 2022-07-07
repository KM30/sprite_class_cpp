#pragma once
#include "BaseSprite.h"

class UsrSprite :
    public BaseSprite
{
protected:
    int score = 0;

public:
    UsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image* img, reset w1);
    UsrSprite(UsrSprite& sprite);
    ~UsrSprite();

    void move(int key);

    void addScore();
    int getScore();
};