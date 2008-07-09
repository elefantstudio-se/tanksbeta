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

namespace WindowsGame1
{
    
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        MouseState mouseState;
        Texture2D crosshair;

        Tank tank = new Tank(100,100,Color.White);
        //Tank tank2 = new Tank(200,100,Color.White);

       

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        
        protected override void Initialize()
        {                       
            base.Initialize();
        }

        
        protected override void LoadContent()
        {            
            spriteBatch = new SpriteBatch(GraphicsDevice);
            tank.bodyTexture = Content.Load<Texture2D>("tank_body_yellow");
            tank.cannonTexture = Content.Load<Texture2D>("tank_cannon");
            crosshair = Content.Load<Texture2D>("crosshair");
  
            
            //tank2.bodyTexture = Content.Load<Texture2D>("tank_body_yellow");
        }

        
        protected override void UnloadContent()
        {
            
        }

        
        protected override void Update(GameTime gameTime)
        {
            tank.move(Keys.W, Keys.S, Keys.D, Keys.A);

            mouseState = Mouse.GetState();

            //tank2.move(Keys.W, Keys.S, Keys.D, Keys.A);
            base.Update(gameTime);
        }

        
        protected override void Draw(GameTime gameTime)
        {
            graphics.GraphicsDevice.Clear(Color.CornflowerBlue);
            spriteBatch.Begin();
            tank.draw(spriteBatch);
        //tank2.draw(spriteBatch);
            spriteBatch.Draw(crosshair,new Vector2(mouseState.X-10,mouseState.Y-10), Color.White);
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
