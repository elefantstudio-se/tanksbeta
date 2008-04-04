#include "sprite.h"

class bullet : public sprite
{
public:
	bullet();
	
	int xvel;
	int yvel;
	
	bool visible; 
	
	void draw(BITMAP *buffer);
};
