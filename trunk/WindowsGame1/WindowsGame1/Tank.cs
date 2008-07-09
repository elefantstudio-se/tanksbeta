using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Net;
using Microsoft.Xna.Framework.Storage;

namespace WindowsGame1
{
    class Tank
    {
        public Texture2D cannonTexture;
        public Texture2D bodyTexture;
        
        public Vector2 cordinate;
        public Vector2 cannonOrigin;
        public Vector2 bodyOrigin;
        public Color color;

        public double cannonAngle;
        public float bodyAngle;
        public float speed;
       

        public Tank(float x, float y, Color temp_color)
        {
            cordinate = new Vector2(x,y);
            bodyOrigin = new Vector2(25, 25);
            cannonOrigin = new Vector2(25, 25);
            color = temp_color;
            speed = 1;

        }

        public void draw(SpriteBatch spritebatch)
        {
            spritebatch.Draw(bodyTexture, cordinate, null, color ,bodyAngle * 0.0174444444444f, bodyOrigin, 1.0f, SpriteEffects.None, 0.0f);
            spritebatch.Draw(cannonTexture, new Vector2(cordinate.X, cordinate.Y), null, color, (float)(cannonAngle+1.570795), cannonOrigin, 1.0f, SpriteEffects.None, 0.0f);
        }

        public void move(Keys up, Keys down, Keys right, Keys left)
        {
            
            KeyboardState keyState = Keyboard.GetState();

            if (keyState.IsKeyDown(left) && keyState.IsKeyDown(down))
            {
                update_cordinate(-speed, speed);
                bodyAngle = 225;
            }

            else if (keyState.IsKeyDown(right) && keyState.IsKeyDown(down))
            {
                update_cordinate(speed, speed);
                bodyAngle = 135;
            }

            else if (keyState.IsKeyDown(right) && keyState.IsKeyDown(up))
            {
                update_cordinate(speed, -speed);
                bodyAngle = 45;
            }

            else if (keyState.IsKeyDown(left) && keyState.IsKeyDown(up))
            {
                update_cordinate(-speed, -speed);
                bodyAngle = 315;
            }

            else if (keyState.IsKeyDown(up))
            {
                update_cordinate(0, -speed);
                bodyAngle = 0;
            }

            else if (keyState.IsKeyDown(down))
            {
                update_cordinate(0, speed);
                bodyAngle = 180;
            }

            else if (keyState.IsKeyDown(right))
            {
                update_cordinate(speed, 0);
                bodyAngle = 90;
            }

            else if (keyState.IsKeyDown(left))
            {
                update_cordinate(-speed, 0);
                bodyAngle = 270;
            }

            cannon_angle();
        }

        void cannon_angle()
        { 
            MouseState mouseState = Mouse.GetState();

            cannonAngle = Math.Atan2(mouseState.Y - (cordinate.Y),mouseState.X - (cordinate.X));
        
        }

        

        void update_cordinate(float x, float y) 
        { 
            if(!(cordinate.X + x < 0) && !(cordinate.X + x > 750))
            {
                cordinate.X += x;
            }

            if (!(cordinate.Y + y < 18) && !(cordinate.Y + y > 582))
            {
                cordinate.Y += y;
            }

        }
    }
}
