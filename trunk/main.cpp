/*|--------------------------------------|*/
/*|            Table Tanks               |*/
/*|    By Jason Spafford and Hamzeh      |*/
/*|--------------------------------------|*/
/*|             04/02/08                 |*/
/*|--------------------------------------|*/

#include <math.h> 
#include "allegro.h"
#include "box.h"
#include "tank.h"
#include "directions.h"

#define DEBUG

void allegro_initialize();

const int screen_w = 1024;
const int screen_h = 768;

int ticks=0;

void ticker() {
	 ticks++;
} END_OF_FUNCTION(ticker)

int main() {
	
	allegro_initialize();
	
	BITMAP *buffer = create_bitmap(screen_w, screen_h);
	
	//create objects of class sprite
	tank player1 = tank(load_bmp("tank_body_yellow.bmp", NULL));
	player1.turret.bmp = load_bmp("tank_cannon.bmp", NULL);
	player1.turret.ammo_graphic = load_bmp("tank_missle.bmp", NULL);

	player1.turret.current_bullet = 0;
	
	sprite crosshair = sprite(load_bmp("crosshair.bmp", NULL));
	sprite bg = sprite(load_bmp("bg.bmp", 0));
	box block = box(load_bmp("block.bmp", NULL));
	
	// set x,y in the center of the screen
	player1.x = screen_w/2-25;
	player1.y = screen_h/2-25;
	
	block.x = 50;
	block.y = 400;

	
	LOCK_VARIABLE(yicks);
	LOCK_FUNCTION(ticker);

	install_int_ex(ticker, BPS_TO_TIMER(60));
	int ntick;

	int frames = 0;
	int fps = 0;
	int didticks = 0;
	int ticksrecord = 0;

	while(!key[KEY_ESC]) {

	
		ntick=ticks;
		ticks = 0;
		
		
		for(;ntick>0;ntick--) {

		
			if(key[KEY_W] && key[KEY_D]) {
				player1.angle = 32;
				player1.move_y(-2.3);
				player1.move_x(2.3);
			}

			else if(key[KEY_W] && key[KEY_A]){
				player1.angle = -32;
				player1.move_y(-2.3);
				player1.move_x(-2.3);
			}

			else if(key[KEY_S] && key[KEY_A]){
				player1.angle = 160;
				player1.move_y(2.3);
				player1.move_x(-2.3);
			}

			else if(key[KEY_S] && key[KEY_D]){
				player1.angle = -160;
				player1.move_y(2.3);
				player1.move_x(2.3);
			}

	
			else if(key[KEY_W]) {
				player1.angle = 0;
				player1.move_y(-3);
			} 
		
			else if(key[KEY_S]) {
				player1.angle = 128;
				player1.move_y(3);
			}
	
	
			else if(key[KEY_D]) {
				player1.angle = 64;
				player1.move_x(3);
			}

			else if(key[KEY_A]) {
				player1.angle = 192;
				player1.move_x(-3);
			}
			
			if(mouse_b & 1) {
				player1.turret.fire();
			}
			
	

			// set cannon direction			
			player1.turret.angle = atan2(((mouse_y-10) - player1.y), ((mouse_x-10) - player1.x)) * (40.764331210) + 70;
		
			//blit(bg.bmp, buffer,0,0,0,0,screen_w,screen_h);
			
				
			bg.draw(buffer, 0, 0);
			
			player1.turret.current_ticks = ticksrecord;
			player1.draw(buffer);
			
			block.draw(buffer);
			crosshair.draw(buffer, (mouse_x-10), (mouse_y-10));
						
			#ifdef DEBUG
				textprintf(buffer, font, 0, 10, makecol(255, 255, 255),  "x: %.0i", player1.x);
				textprintf(buffer, font, 55, 10, makecol(255, 255, 255),  "y: %.0i", player1.y);
				textprintf(buffer, font, 0, 40, makecol(255, 255, 255),  "Bullet Count: %i", player1.turret.current_bullet);
				textprintf(buffer, font, 0, 50, makecol(255, 255, 255), "sizeof(bullets): %i", player1.turret.bullets.size());
				textprintf(buffer, font, 0, 60, makecol(255, 255, 255), "angle(turret): %f", player1.turret.angle );
				textprintf(buffer, font, 0, 70, makecol(255, 255, 255), "ticksrecord: %i" , ticksrecord);
				
				textprintf(buffer, font, 0, 80, makecol(255, 255, 255), "current_ticks: %i", player1.turret.current_ticks);
				textprintf(buffer, font, 0, 90, makecol(255, 255, 255), "ticks: %i", player1.turret.ticks);
				textprintf(buffer, font, 0, 100, makecol(255, 255, 255), "Difference: %i", player1.turret.current_ticks - player1.turret.ticks);
			#endif

			didticks++;
			ticksrecord++;
			
			if(didticks==60) {
				fps	= frames;
				didticks = 0;
				frames =0;
			}
		}
	

		acquire_screen();
		#ifdef DEBUG
			textprintf(buffer, font, 110, 10, makecol(255, 255, 255),  "FPS: %i", fps);
		#endif
		blit(buffer, screen, 0, 0, 0, 0, screen_w, screen_h);
		release_screen();
		frames++;
		
	}

return 0;

}
END_OF_MAIN()

void allegro_initialize()
{
	allegro_init();
	
	install_timer() ;
	install_keyboard();
	install_mouse();
	
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,screen_w,screen_h,0,0);
}
