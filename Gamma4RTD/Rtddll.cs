using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace Gamma4RTD
{
    internal class Rtddll
    {
        private Rtddll() {}

        [DllImport("rtddll.dll")]
        public static extern bool RTD2758Init();

        [DllImport("rtddll.dll")]
        public static extern void RTD2758_Run();

        [DllImport("rtddll.dll")]
        public static extern void RTD2758_Stop();

        [DllImport("rtddll.dll")]
        public static extern void RTD2758_Reset();

        [DllImport("rtddll.dll")]
        public static extern void Set_GammaEnable(bool enable);

        [DllImport("rtddll.dll")]
        public static extern void Read_GammaTable(ref byte arry);

        [DllImport("rtddll.dll")]
        public static extern void Read_GammaRGBTable(byte type, ref byte arry);

        [DllImport("rtddll.dll")]
        public static extern void Write_GammaTable(ref byte arry);

        [DllImport("rtddll.dll")]
        public static extern void Write_GammaRGBTable(byte type, ref byte arry);

        [DllImport("rtddll.dll")]
        public static extern void DDCCI_EraseGamma(byte gammaID);

        [DllImport("rtddll.dll")]
        public static extern bool DDCCI_WriteGamma(ref byte gammabuff, byte gammaID);

        [DllImport("rtddll.dll")]
        public static extern void DDCCI_EnableGamma(bool enable);

        [DllImport("rtddll.dll")]
        public static extern void DDCCI_SetGamma(byte gammaID);
    }
}
