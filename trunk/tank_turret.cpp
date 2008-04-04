#include "tank_turret.h"
#include "allegro.h"
#include <iostream>

tank_turret::tank_turret() : max_bullets(1000)
{
	this->fire_speed = 10;
	this->cooldown = 20;
	this->ticks = 0;
	this->current_ticks = 0;
}

tank_turret::~tank_turret()
{
	this->fire_speed = 10;
	this->cooldown = 50;
	this->ticks = 0;
	this->current_ticks = 0;
}

void tank_turret::fire()
{
	int count = current_ticks;
	
	if( (count - ticks) < this->cooldown )
		return;
	
	//std::cout << "max_bullets: " << max_bullets << "\n";
	
	if( this->current_bullet == max_bullets )
		return; // Play out of ammo click noise?
		
	this->ticks = count;
	
	bullet tmpbullet = bullet();
	tmpbullet.x = this->x;
	tmpbullet.y = this->y;
	tmpbullet.bmp = this->ammo_graphic;
	tmpbullet.visible = true;
	tmpbullet.angle = this->angle;
	
	tmpbullet.xvel = this->fire_speed * cos (fix(tmpbullet.angle) - 70);
	tmpbullet.yvel = this->fire_speed * sin (fix(tmpbullet.angle) - 70);
	
	BITMAP *buffer = load_bmp("empty.bmp", NULL);
	rotate_sprite(buffer, this->ammo_graphic, 0, 0, ftofix(tmpbullet.angle));
	
	tmpbullet.bmp = buffer;
	
	bullets.push_back(tmpbullet);
	
	current_bullet++;

}

void tank_turret::update_bullets(BITMAP *buffer)
{

	std::vector<bullet>::iterator iter;
	
	for ( iter = bullets.begin(); iter != bullets.end(); ++iter )
	{
		
		if( this->bullets.empty() )
			break;
			
		if( (*iter).x < 0 || (*iter).y < 0 || (*iter).y > 768 || (*iter).x > 1024 )
		{	
			this->bullets.erase( iter );
			this->current_bullet--;
			continue;
		}
		
		if( (*iter).visible == false )
			continue;

		(*iter).x += (*iter).xvel;
		(*iter).y += (*iter).yvel;

		(*iter).draw(buffer);
	}
	
}
