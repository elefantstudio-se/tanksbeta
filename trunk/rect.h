#include "point.h"

class rect
{
	
public:
	point upperleft;
	point bottomright;
	point upperright;
	point bottomleft;
	
	rect();
	rect(point upperleft, point bottomright);
	rect(point upperleft, int width, int height);
};
