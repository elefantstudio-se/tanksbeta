#include "tank_turret.h"
#include "allegro.h"
#include <iostream>

tank_turret::tank_turret() : max_bullets(100)
{
	
}

tank_turret::~tank_turret()
{
	
}

void tank_turret::fire()
{
	std::cout << "max_bullets: " << max_bullets << "\n";
	
	if( this->current_bullet == max_bullets )
		return; // Play out of ammo click noise?
	
	bullet tmpbullet = bullet();
	tmpbullet.x = this->x;
	tmpbullet.y = this->y;
	tmpbullet.bmp = this->ammo_graphic;
	tmpbullet.visible = true;
	tmpbullet.angle = this->angle;
	
	bullets.push_back(tmpbullet);
	
	current_bullet++;
}

void tank_turret::update_bullets(BITMAP *buffer)
{
	
	std::vector<bullet>::iterator iter;
	
	for ( iter = bullets.begin(); iter != bullets.end(); ++iter )
	{
		bullet new_bullet = *iter;
		new_bullet.draw(buffer);
	}
	
}
