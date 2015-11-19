using System.Runtime.InteropServices;

namespace Rig3DEngine
{
    [StructLayout(LayoutKind.Sequential)]
    public struct Vector3
    {
        public float X, Y, Z;

        public override string ToString() => $"[{X}, {Y}, {Z}]";
    }
}