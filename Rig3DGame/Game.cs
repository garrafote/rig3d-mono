using Rig3DEngine;

namespace Rig3DGame
{
   
    public class Game
    {
        public Transform player;

        public void Start()
        {
            player = Engine.PlayerTransform;
        }

        public void Update()
        {
            var pos = player.Position;

            var speed = 0.5f;

            if (Input.GetKey(KeyCode.KEYCODE_LEFT))
            {
                pos.X -= speed;
            }

            if (Input.GetKey(KeyCode.KEYCODE_RIGHT))
            {
                pos.X += speed;
            }

            if (Input.GetKey(KeyCode.KEYCODE_UP))
            {
                pos.Y += speed;
            }

            if (Input.GetKey(KeyCode.KEYCODE_DOWN))
            {
                pos.Y -= speed;
            }

            player.Position = pos;
        }

    }
}
