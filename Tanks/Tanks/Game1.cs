using System;
using System.Collections.Generic;
//using System.Windows.Forms;
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

    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        public static SpriteBatch spriteBatch;
        MouseState mouseState;
        KeyboardState keyboardState;

        public static Texture2D bullet; 

        Texture2D crosshair;
        Texture2D background;
        Tank tank;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }


        protected override void Initialize()
        {
            base.Initialize();
            graphics.PreferredBackBufferWidth = 1024;
            graphics.PreferredBackBufferHeight = 768;
            graphics.ApplyChanges();

            //Form MyGameForm = (Form)Form.FromHandle(Window.Handle);

            //MyGameForm.FormBorderStyle = FormBorderStyle.None;


        }


        protected override void LoadContent()
        {
            spriteBatch = new SpriteBatch(GraphicsDevice);

            tank = new Tank(new Vector2(100,100), Color.White, 
                Content.Load<Texture2D>("Tankk"), 
                Content.Load<Texture2D>("TankCcc"),
                Keys.W, Keys.S , Keys.D , Keys.A );

            crosshair = Content.Load<Texture2D>("ch1");
            background = Content.Load<Texture2D>("Background");
            bullet = Content.Load<Texture2D>("Bullet");
        }

        
        protected override void UnloadContent()
        {
            Content.Unload();
        }


        protected override void Update(GameTime gameTime)
        {
            mouseState = Mouse.GetState();
            keyboardState = Keyboard.GetState();

            if (keyboardState.IsKeyDown(Keys.Escape)) {
                this.Exit();
            }
            
            tank.Move();
            base.Update(gameTime);
        }


        protected override void Draw(GameTime gameTime)
        {
            graphics.GraphicsDevice.Clear(Color.Gray);
            spriteBatch.Begin();

            spriteBatch.Draw(background, new Vector2(0, 0), Color.White);
            tank.Draw();
            spriteBatch.Draw(crosshair, new Vector2(mouseState.X-16, mouseState.Y-16), Color.White);           

            spriteBatch.End();
            base.Draw(gameTime);
        }
    }
}
