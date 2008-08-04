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
        bool alive;
        MouseState mouseState;

        Bullet () 
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
                fire_bullet(angle,cordinate);
            }
        }

        void fire_bullet(Double angle, Vector2 cordinate)
        {
            if (!alive)
            {
                velocity = new Vector2(
                            (float)Math.Cos(angle),
                            (float)Math.Sin(angle)) * 5.0f;
                position = new Vector2(cordinate.X - 4, cordinate.Y - 4);
            }         
        }


    }
}
