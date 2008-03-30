#include <math.h> 
#include "allegro.h"
#include "sprite.h"
#include "box.h"

#include "colidable.h"


void allegro();

const int screen_w = 1024;
const int screen_h = 768;

int ticks=0;

void ticker() {
	 ticks++;
} END_OF_FUNCTION(ticker)

int main(){
	allegro();
	
	
	BITMAP *buffer = create_bitmap(screen_w, screen_h);
	BITMAP *bg = load_bitmap("bg.bmp",0);

	//colidable colide_box;
	//colide_box.density = true;
	//colide_box.upperleft = new point(0, 2);
	
	//create objects of class sprite
	sprite tank;
	sprite tank_cannon;
	sprite crosshair;
	box block;
	
	block.bmp = load_bmp("block.bmp",NULL);
	tank.bmp = load_bmp("tank_body_yellow.bmp", NULL);
	tank_cannon.bmp = load_bmp("tank_cannon.bmp", NULL);
	crosshair.bmp = load_bmp("crosshair.bmp",NULL);

	// set x,y in the center of the screen
	tank.x = screen_w/2-25;
	tank.y = screen_h/2-25;
	
	block.x = 50;
	block.y = 400;
	

	LOCK_VARIABLE(yicks);
	LOCK_FUNCTION(ticker);

	install_int_ex(ticker, BPS_TO_TIMER(60));
	int ntick;

	int frames = 0;
	int fps =0;
	int didticks = 0;
		

	while(!key[KEY_ESC]) {

	
		ntick=ticks;
		ticks = 0;
		
		
		for(;ntick>0;ntick--){

		
			if(key[KEY_W] && key[KEY_D]){
				tank.direction = 32;
				tank.move_y(-2.3);
				tank.move_x(2.3);
			}

			else if(key[KEY_W] && key[KEY_A]){
				tank.direction = -32;
				tank.move_y(-2.3);
				tank.move_x(-2.3);
			}

			else if(key[KEY_S] && key[KEY_A]){
				tank.direction = 160;
				tank.move_y(2.3);
				tank.move_x(-2.3);
			}

			else if(key[KEY_S] && key[KEY_D]){
				tank.direction = -160;
				tank.move_y(2.3);
				tank.move_x(2.3);
			}

	
			else if(key[KEY_W]){
				tank.direction = 0;
				tank.move_y(-3);
			} 
		
			else if(key[KEY_S]){
				tank.direction = 128;
				tank.move_y(3);
			}
	
	
			else if(key[KEY_D]){
				tank.direction = 64;
				tank.move_x(3);
			}

			else if(key[KEY_A]){
				tank.direction = 192;
				tank.move_x(-3);
			}

			
	

			// set cannon direction
			tank_cannon.direction = atan2(((mouse_y-10) - tank.y), ((mouse_x-10) - tank.x))* (40.764331210)+70;
		
			// draw the tank body and cannon at the updated x,y
			blit(bg, buffer,0,0,0,0,screen_w,screen_h);
			rotate_sprite(buffer, tank.bmp, tank.x, tank.y ,ftofix(tank.direction));
			draw_sprite(buffer, block.bmp, block.x, block.y);
			rotate_sprite(buffer, tank_cannon.bmp, tank.x, tank.y ,ftofix(tank_cannon.direction));
			draw_sprite(buffer, crosshair.bmp, (mouse_x-10), (mouse_y-10));
			
			//print the value of x,y
			textprintf(buffer, font, 0, 10, makecol(255, 255, 255),  "x: %.0f", tank.x);
			textprintf(buffer, font, 50, 10, makecol(255, 255, 255),  "y: %.0f", tank.y);
			didticks++;
			
			if(didticks==60){
				
				
				fps	= frames;
				didticks = 0;
				frames =0;
			}
		}
	

		acquire_screen();
		textprintf(buffer, font, 100, 10, makecol(255, 255, 255),  "FPS: %i", fps);
		blit(buffer, screen, 0, 0, 0, 0, screen_w, screen_h);
		release_screen();
		frames++;
		
	}

return 0;

}
END_OF_MAIN()

void allegro(){
	allegro_init();
	install_timer() ;
	install_keyboard();
	install_mouse();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,screen_w,screen_h,0,0);
}
