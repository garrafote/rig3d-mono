using System.Runtime.CompilerServices;

namespace Rig3DEngine
{
    public class Transform
    {
        public int ObjectId { get; private set; }

        public Vector3 Position
        {
            get { return __InternalCall__GetPosition(); }
            set { __InternalCall__SetPosition(value); }
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern Vector3 __InternalCall__GetPosition();

        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern void __InternalCall__SetPosition(Vector3 value);
    }
}