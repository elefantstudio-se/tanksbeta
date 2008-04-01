#include "tank_turret.h"
#include "allegro.h"
#include <iostream>

void tank_turret::fire()
{
	if( this->current_bullet == max_bullets )
		return; // Play out of ammo click noise?
	
	bullet tmpbullet = bullet();
	tmpbullet.x = this->x;
	tmpbullet.y = this->y;
	tmpbullet.bmp = this->ammo_graphic;
	
	bullets[current_bullet] = tmpbullet;
	
	current_bullet++;
}

void tank_turret::update_bullets(BITMAP *buffer)
{
	//std::cout << "current_bullet: " << current_bullet;
//	std::cout << "bullets[0
	//system("CLS");
	
	if( current_bullet == 0)
		return;
		
	for(int i=0; i < max_bullets; i++ )
	{
		bullets[i].draw(buffer);
	}
}
