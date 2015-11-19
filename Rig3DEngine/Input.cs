using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Rig3DEngine
{
    public class Input
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static bool __InternalCall__GetKeyDown(KeyCode key);
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static bool __InternalCall__GetKeyUp(KeyCode key);
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static bool __InternalCall__GetKey(KeyCode key);
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static bool __InternalCall__GetMouseButtonDown(MouseButton button);
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static bool __InternalCall__GetMouseButtonUp(MouseButton button);
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static bool __InternalCall__GetMouseButton(MouseButton button);

        public static bool GetKeyDown(KeyCode key)                  => __InternalCall__GetKeyDown(key);
        public static bool GetKeyUp(KeyCode key)                    => __InternalCall__GetKeyUp(key);
        public static bool GetKey(KeyCode key)                      => __InternalCall__GetKey(key);
        public static bool GetMouseButtonDown(MouseButton button)   => __InternalCall__GetMouseButtonDown(button);
        public static bool GetMouseButtonUp(MouseButton button)     => __InternalCall__GetMouseButtonUp(button);
        public static bool GetMouseButton(MouseButton button)       => __InternalCall__GetMouseButton(button);
    }
}
