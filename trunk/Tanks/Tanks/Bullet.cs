using System;
using System.Collections.Generic;
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
    class Bullet
    {

        public Vector2 position;
        public Vector2 velocity;
        public Texture2D bullet_image;

        bool alive;
        MouseState mouseState;

        public Bullet () 
        {

            velocity = Vector2.Zero;
            position = Vector2.Zero;
            alive = false;
        }

        public void update_bullet(Double angle,Vector2 cordinate)
        {
            mouseState = Mouse.GetState();

            if (alive)
            {
                position += velocity;


            }
            else if (mouseState.LeftButton == Microsoft.Xna.Framework.Input.ButtonState.Pressed)
            {
                if (!alive)
                {
                    velocity = new Vector2(
                                (float)Math.Cos(angle),
                                (float)Math.Sin(angle)) * 5.0f;
                    position = new Vector2(cordinate.X - 4, cordinate.Y - 4);

                    alive = true;
                }  
            }
        }

        public void draw_bullet()
        {
            Game1.spriteBatch.Draw(bullet_image, position, Color.White);
        }


    }
}
