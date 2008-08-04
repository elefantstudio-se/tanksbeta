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

namespace Tanks
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


        public Tank(float x, float y, Color temp_color, Texture2D loaddedBodyTexture, Texture2D loaddedCannonTexture)
        {

            bodyTexture = loaddedBodyTexture;
            cannonTexture = loaddedCannonTexture;

            cordinate = new Vector2(x, y);
            bodyOrigin = new Vector2(bodyTexture.Width / 2, bodyTexture.Height / 2);
            cannonOrigin = new Vector2(cannonTexture.Width / 2, cannonTexture.Height / 2);
            color = temp_color;
            speed = 3;
            
         
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

            update_cannon_angle();
        }

        void update_cannon_angle()
        {
            MouseState mouseState = Mouse.GetState();

            cannonAngle = Math.Atan2(mouseState.Y - (cordinate.Y), mouseState.X - (cordinate.X));

        }



        void update_cordinate(float x, float y)
        {
            if (!(cordinate.X + x < 25 - 7) && !(cordinate.X + x > 1024))
            {
                cordinate.X += x;
            }

            if (!(cordinate.Y + y < 18) && !(cordinate.Y + y > 768))
            {
                cordinate.Y += y;
            }

        }



        public void draw(SpriteBatch spritebatch)
        {
            spritebatch.Draw(bodyTexture, cordinate, 
                null, color, 
                bodyAngle * 0.0174444444444f, 
                bodyOrigin, 1.0f, 
                SpriteEffects.None, 0.0f);
         
            spritebatch.Draw(cannonTexture, cordinate , 
                null, color, 
                (float)(cannonAngle + 1.570795), 
                cannonOrigin, 1.0f, 
                SpriteEffects.None, 0.0f);
        }
    }
}
