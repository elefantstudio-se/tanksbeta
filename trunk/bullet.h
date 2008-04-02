#include "sprite.h"

class bullet : public sprite
{
public:
	bullet();
	
	bool visible; 
	
	void draw(BITMAP *buffer);
};
