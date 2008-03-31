#include "allegro.h"
#include "collidable.h"
#include "sprite.h"

class collision
{
	public:
		collision();
		
		static const int max_collidable_objects = 1;
		
		collidable objects[ max_collidable_objects ];
		
		bool check_collision(sprite test_object, int speed, int direction);	

		void draw(BITMAP *buffer);
		
	private:
		static const bool draw_bounds = false;
};
