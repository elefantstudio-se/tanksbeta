#include "tank_turret.h"
#include "allegro.h"
#include <iostream>

tank_turret::tank_turret()
{
	for(int i=0; i < max_bullets; i++)
	{
		bullet tmpbullet;
		tmpbullet.visible = false;
		tmpbullet.x = 0;
		tmpbullet.y = 0;
		tmpbullet.bmp = this->ammo_graphic;
		
		bullets[i] = tmpbullet;
	}
}

void tank_turret::fire()
{
	if( this->current_bullet == max_bullets )
		return; // Play out of ammo click noise?
	
	bullet tmpbullet = bullet();
	tmpbullet.x = this->x;
	tmpbullet.y = this->y;
	tmpbullet.bmp = this->ammo_graphic;
	tmpbullet.visible = true;
	tmpbullet.angle = this->angle;
	
	
	/*BITMAP *buffer = tmpbullet.bmp;
	
	rectfill(buffer, 0, 0, 50, 50, 255);
	rectfill(tmpbullet.bmp, 0, 0, 50, 50, 255);
	
	rotate_sprite(buffer, this->ammo_graphic, 0, 0, ftofix(tmpbullet.angle) );
	tmpbullet.bmp = buffer;
	*/
	
	bullets[current_bullet] = tmpbullet;
	
	current_bullet++;
}

void tank_turret::update_bullets(BITMAP *buffer)
{
	//std::cout << "current_bullet: " << current_bullet;
	//std::cout << "bullets[0
	//system("CLS");
	
		
	for(int i=0; i < max_bullets; i++ )
	{
	//	std::cout << "bullets[i].visible: " << bullets[i].visible << "\n";
		
		//if( bullets[i].bmp == this->ammo_graphic )
			//std::cout << "LOLTEST!\n";
		
		if(bullets[i].visible == false)
			continue;
		
		bullets[i].draw(buffer);
	}
}
