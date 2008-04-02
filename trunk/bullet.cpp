#include "bullet.h"
#include <iostream>

bullet::bullet()
{
	this->visible = false;
}

void bullet::draw(BITMAP *buffer)
{
	#ifdef DEBUG
		std::cout << "DRAWN BULLET at (" << (int)this->x << ", " << (int)this->y << ") using Angle(" << this->angle <<")\n";
	#endif
	
//	draw_sprite(buffer, this->bmp, (int)x, (int)y);

	rotate_sprite(buffer, this->bmp, (int)this->x, (int)this->y, ftofix(this->angle) );
}
