#include "allegro.h"

#ifndef SPRITE_H
#define SPRITE_H

class sprite
{

public:
	sprite();
	sprite(BITMAP *bmp);
	
	BITMAP *bmp;
	
	int x;
	int y;
	
	int width;
	int height;
	
	bool visible;

	double angle;
	
	void draw(BITMAP *buffer);
	void draw(BITMAP *buffer, int x, int y);

};

#endif
