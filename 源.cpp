#include"AutoSprite.h"
#include"UsrSprite.h"

#include"AvoidSprite.h"

#include<time.h>
#include<stdio.h>

const int winWidth = 800, winHeight = 600;
const int spriteWidth = 30, spriteHeight = 30;
const int avoidWidth = 20, avoidHeight = 20;

reset winReset;										
ACL_Image imgauto,imgusr,imgavoid;							

int nowNum = 0;
const int maxNum = 24;							
AutoSprite* autosprite[maxNum] = { 0 };
UsrSprite* usrsprite = NULL;	

void CreateDataAuto();
void CreateDataUsr();

void TimerEvent(int id);
void keyEvent(int key, int event);
void paint();
void printtxt();

int Setup()
{
	initWindow("KM30 : Base Sprite AU Collision Score", DEFAULT, DEFAULT, winWidth, winHeight);

	srand((unsigned)time(NULL));

	winReset.x = DEFAULT;						
	winReset.y = DEFAULT;
	winReset.height = winHeight;
	winReset.width = winWidth;

	loadImage("jerry.bmp", &imgauto);														
	loadImage("tom.bmp", &imgusr);
	loadImage("heart.bmp", &imgavoid);

	CreateDataAuto();
	CreateDataUsr();
		
	registerTimerEvent(TimerEvent);														
	registerKeyboardEvent(keyEvent);	
	startTimer(0, 40);
	startTimer(1, 3000);

	return 0;
}

void CreateDataAuto()
{
	int x = rand() % winWidth - spriteWidth;
	if (x < 0)
		x = 0;
	int y = rand() % winHeight - spriteHeight;
	if (y < 0)
		y = 0;
	int dx = rand() % 3 + 1;
	int dy = rand() % 3 + 1;
	int rate = rand() % 100;
	if (rate < 70)
		autosprite[nowNum++] = new AutoSprite(x, y, spriteWidth, spriteHeight, dx, dy, &imgauto, winReset);
	else
		autosprite[nowNum++] = new AvoidSprite(x, y, avoidWidth, avoidHeight, dx, dy, &imgavoid, winReset);
}

void CreateDataUsr()
{
	int x = rand() % winWidth - spriteWidth;
	if (x < 0)
		x = 0;
	int y = rand() % winHeight - spriteHeight;
	if (y < 0)
		y = 0;
	int dx = rand() % 3 + 1;
	int dy = rand() % 3 + 1;
	usrsprite = new UsrSprite(x, y, spriteWidth, spriteHeight, dx, dy, &imgusr, winReset);
}

void TimerEvent(int id)
{
	switch (id)
	{
	case 0:
		for (int i = 0;i < nowNum;i++)
		{
			if (autosprite[i])
			{
				autosprite[i]->move(usrsprite->getReset());
				if (usrsprite)
				{
					if (autosprite[i]->collision(usrsprite->getReset()))
					{
						delete(autosprite[i]);
						autosprite[i] = NULL;
						usrsprite->addScore();
					}
				}
			}
		}
		break;
	case 1:								
		if (nowNum < maxNum)
		{
			CreateDataAuto();
		}
		break;
	}
	paint();
}

void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)
		return;
	if (usrsprite)
	{
		usrsprite->move(key);
		for (int i = 0;i < nowNum;i++)
		{
			if (autosprite[i])
			{
				if (usrsprite->collision(autosprite[i]->getReset()))
				{
					delete(autosprite[i]);
					autosprite[i] = NULL;
					usrsprite->addScore();
				}
			}
		}
	}
	paint();
}

void paint()
{
	beginPaint();
	clearDevice();
	int i = 0;
	for (i = 0;i < nowNum;i++)
	{
		if (autosprite[i])
		{
			autosprite[i]->drawSprite();
		}
	}
	if (usrsprite)
	{
		switch (usrsprite->getScore() / 4)
		{
		case 0:
			usrsprite->drawSprite();
			break;
		case 1:
			usrsprite->drawSprite(2 * spriteWidth, 2 * spriteHeight);
			break;
		default:
			usrsprite->drawSprite(3 * spriteWidth, 3 * spriteHeight);
			break;
		}
		printtxt();
	}
	endPaint();
}

void printtxt()
{
	char txt[10] = { 0 };
	sprintf_s(txt, "%d/%d", usrsprite->getScore(), maxNum);
	setTextSize(12);
	paintText(390, 10, txt);
}