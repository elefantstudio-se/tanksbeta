#include "rect.h"
#include "sprite.h"

class map_object : public sprite
{
	
public:
	map_object();
	map_object(BITMAP *bmp);
	  
	bool density;
};
