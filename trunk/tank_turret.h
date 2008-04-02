#include "bullet.h"
#include "sprite.h"

#ifndef TANK_TURRET_H
#define TANK_TURRET_H

class tank_turret : public sprite
{
public:
	tank_turret();
	
	void fire();
	void update_bullets(BITMAP *buffer);
	
	BITMAP *ammo_graphic;
	
	int ammo;
	int current_bullet;
	
	static const int max_bullets = 20;
	bullet bullets[ max_bullets ];
	
		
};

#endif

