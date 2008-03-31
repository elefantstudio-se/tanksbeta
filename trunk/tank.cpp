#include "allegro.h"
#include "tank.h"

const int screen_w = 1024;
const int screen_h = 768;

void tank::move_x (float velocity_x) {
	
	if(this->x+velocity_x > -7 && this->x + velocity_x < screen_w-43)
		this->x += (int)velocity_x;
}

void tank::move_y (float velocity_y){
	
	if( this->y + velocity_y > -7 && this->y + velocity_y < screen_h - 43)
		this->y+= (int)velocity_y;
}

tank::tank()
{
}

tank::tank(BITMAP *bmp)
{
	this->bmp = bmp;
}
