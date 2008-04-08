class point
{

public:
	point();
	point( int new_x, int new_y);
	
	point & operator=(const point & p) { this->x = p.x; this->y = p.y; return *this; }
	
 	int x, y;
	   
};
