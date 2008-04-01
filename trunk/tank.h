#include "sprite.h"
#include "tank_turret.h"

class tank : public sprite
{
public:
	tank();
	tank(BITMAP *bmp);
	
	tank_turret turret;
	
	void move_x(float velocity_x);
	void move_y(float veloctiy_y);
	
	void draw(BITMAP *buffer);
	void draw(BITMAP *buffer, int x, int y);
	
	int direction;
};
