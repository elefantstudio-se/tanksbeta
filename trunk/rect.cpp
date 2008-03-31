#include "rect.h"

rect::rect()
{
}

rect::rect(point upperleft, point bottomright)
{
	this->upperleft = upperleft;
	this->upperright = point(upperleft.y, bottomright.x);
	
	this->bottomright = bottomright;
	this->bottomleft = point(upperleft.x, bottomright.y); 
}

rect::rect(point upperleft, int width, int height)
{
	this->upperleft = upperleft;
	this->upperright = point( upperleft.x + width, upperleft.y);
	
	this->bottomleft = point( upperleft.x, upperleft.y + height);
	this->bottomright = point( upperleft.x + width, upperleft.y + height);
}
