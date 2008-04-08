#include "allegro.h"
#include "tank.h"

const int screen_w = 1024;
const int screen_h = 768;

void tank::move_x (float velocity_x) {
	
	if(this->x+velocity_x > -7 && this->x + velocity_x < screen_w-43)
		this->x += (int)velocity_x;
		
	this->turret.x = this->x;
	this->turret.y = this->y;
}

void tank::move_y (float velocity_y) {
	
	if( this->y + velocity_y > -7 && this->y + velocity_y < screen_h - 43)
		this->y+= (int)velocity_y;
	
	this->turret.x = this->x;
	this->turret.y = this->y;
}

tank::tank()
{
	
}

tank::tank(BITMAP *bmp)
{
	this->bmp = bmp;
}

void tank::draw(BITMAP *buffer)
{
	rotate_sprite(buffer, this->bmp, this->x, this->y, ftofix(this->angle) );
	rotate_sprite(buffer, this->turret.bmp, this->x, this->y, ftofix(this->turret.angle) );
	
	this->turret.x = this->x;
	this->turret.y = this->y;

	this->turret.update_bullets(buffer);
	
}

void tank::draw(BITMAP *buffer, int x, int y)
{
	rotate_sprite(buffer, this->bmp, x, y, ftofix(this->angle) );
	rotate_sprite(buffer, this->turret.bmp, x, y, ftofix(this->turret.angle) );
	
	this->turret.update_bullets(buffer);
}
