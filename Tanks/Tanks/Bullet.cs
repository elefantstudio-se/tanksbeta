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

        private Vector2 position;
        private Vector2 velocity;
        private float angle;
        public Texture2D bullet_image;
        Vector2 origin;

        public Bullet(float angle, Vector2 position, Vector2 velocity) 
        {
            this.position = position;
            this.velocity = velocity;
            this.angle = angle;
            this.bullet_image = Game1.bullet;

            origin = new Vector2(this.bullet_image.Width / 2, this.bullet_image.Height / 2);
        }

        public void Update()
        {
            this.position += this.velocity;
        }

        public void Draw()
        {
            Game1.spriteBatch.Draw(this.bullet_image, this.position, null, Color.White, this.angle, this.origin, 1.0f, SpriteEffects.None, 0.0f);
        }


    }
}
