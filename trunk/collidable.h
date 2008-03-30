#include "point.h"

class collidable
{
public:
	collidable();
	
	point upperleft;
	point upperright;
	point bottomleft;
	point bottomright;
	  
	bool density;
};
