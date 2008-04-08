#include "bullet.h"
#include <iostream>


bullet::bullet()
{
	this->visible = false;
}

void bullet::draw(BITMAP *buffer)
{
	
	
	#ifdef DEBUG
		std::cout << "DRAWN BULLET at (" << this->x << ", " << this->y << ") using Angle(" << this->angle <<")\n";
	#endif
	
	draw_sprite(buffer, this->bmp, x, y);

}
