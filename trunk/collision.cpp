#include "collision.h"
#include "directions.h"

collision::collision()
{
}

void collision::draw(BITMAP *buffer)
{
	if( draw_bounds == false )
		return;
		
	for(int i=0; i < max_collidable_objects; i++)
	{
		rectfill(buffer, objects[i].upperleft.x, objects[i].upperleft.y, objects[i].bottomright.x, objects[i].bottomright.y, 255);
	}
}

bool collision::check_collision(sprite test_object, int speed, int direction)
{
	for(int i=0; i < max_collidable_objects; i++)
	{
		if( direction == NORTH )
		{
			if(	test_object.y - speed < objects[i].upperleft.y);
				return true;
		}
	}
		
	return false;
}
