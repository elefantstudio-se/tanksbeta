#include "collision.h"
#include "directions.h"
#include <iostream>

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
			if(	(int)test_object.y + speed < objects[i].bottomright.y &&
				(int)test_object.y > objects[i].upperleft.y &&
				((int)test_object.x >= objects[i].upperleft.x &&
				(int)test_object.x <= objects[i].bottomright.x) )
				return true;
		}
		
		if( direction == SOUTH )
		{
			if(	((int)test_object.y + 40) + speed > objects[i].upperleft.y && 
				(int)test_object.y < objects[i].bottomright.y && 
				((int)test_object.x >= objects[i].upperleft.x && 
				(int)test_object.x <= objects[i].bottomright.x) )
				return true;	
		}
		
		if( direction == EAST )
		{
			// Not finished
		}
		
		if( direction == WEST )
		{
			// Not finished
		}
	}
		
	return false;
}
