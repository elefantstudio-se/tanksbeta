#include "allegro.h"
#include "sprite.h"

sprite::sprite()
{
	this->angle = 0;
}

sprite::sprite(BITMAP *bmp)
{
	this->bmp = bmp;
	this->angle = 0;
}

void sprite::draw(BITMAP *buffer)
{
	/* Only use rotate if the angle is greater than 0
	because rotate_sprite takes longer to execute. So
	if the angle is 0 (default, and non rotating sprite)
	then just use draw_sprite */
	
	//if(this->angle > 0)
	rotate_sprite(buffer, this->bmp, this->x, this->y, ftofix(this->angle) );

	//else
	//	draw_sprite(buffer, this->bmp, this->x, this->y );
}

void sprite::draw(BITMAP *buffer, int x, int y)
{
	//if(this->angle > 0)
	rotate_sprite(buffer, this->bmp, x, y, ftofix(this->angle) );
	//else
	//	draw_sprite(buffer, this->bmp, x, y );	
}
