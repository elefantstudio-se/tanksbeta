#include "sprite.h"

class tank : public sprite
{
public:
	tank();
	tank(BITMAP *bmp);
	
	void move_x(float velocity_x);
	void move_y(float veloctiy_y);
	
	int direction;
};
