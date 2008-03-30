#include "allegro.h"
#include "sprite.h"

const int screen_w = 1024;
const int screen_h = 768;

void sprite::move_x(float velocity_x){
	
	if(x+velocity_x>-7 && x+velocity_x < screen_w-43)
		x+=velocity_x;


}

void sprite::move_y(float velocity_y){
	
	if(y+velocity_y >-7 && y+velocity_y < screen_h-43)
		y+=velocity_y;
}

