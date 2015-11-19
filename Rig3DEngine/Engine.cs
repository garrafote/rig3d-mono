using System.Runtime.CompilerServices;

namespace Rig3DEngine
{
    public class Engine
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern Transform __InternalCall__GetPlayer();

        public static Transform PlayerTransform => __InternalCall__GetPlayer();
    }
}