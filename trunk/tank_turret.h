#include "bullet.h"
#include "sprite.h"
#include <vector>

#ifndef TANK_TURRET_H
#define TANK_TURRET_H

class tank_turret : public sprite
{
public:
	tank_turret();
	~tank_turret();
	
	void fire();
	void update_bullets(BITMAP *buffer);
	void setTicks( int new_ticks );
	
	BITMAP *ammo_graphic;
	
	int ammo;
	int current_bullet;
	
	int ticks;
	int cooldown;
	int fire_speed;
	int current_ticks;
	
	const int max_bullets;
	
	std::vector<bullet> bullets;
	
};

#endif
