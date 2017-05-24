using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gamma4RTD
{
    class WriteGamma
    {
        public delegate void dWriteProgress(int total, int current);
        public event dWriteProgress onWriteProgress;

        public bool Write()
        {
            int cnt = 0;
            int i = 0;
            const int tableNum = 8;
            double gammaVal = 2.2;

            for (i = 0; i < tableNum; i++)
            {
                switch (i)
                {
                    case 0:
                        gammaVal = 3.73;
                        break;
                    case 1:
                        gammaVal = 2.2;
                        break;
                    case 2:
                        gammaVal = 2.4;
                        break;
                    case 3:
                        gammaVal = 2.6;
                        break;
                    case 4:
                        gammaVal = 1;
                        break;
                    case 5:
                        gammaVal = 0.5;
                        break;
                    case 6:
                        gammaVal = 2.4;
                        break;
                    case 7:
                        gammaVal = 4;
                        break;
                    default:
                        gammaVal = 2.2;
                        break;
                }

                if (DccCiWriteGamma(gammaVal, 3.454, (byte)i))
                {
                    cnt++;
                    if (onWriteProgress != null)
                        onWriteProgress(tableNum, cnt);
                }
                else
                {
                    return false;
                }

                System.Threading.Thread.Sleep(100);
            }

            return true;
        }

        private bool DccCiWriteGamma(double gamma, double gammaMapping, byte gammaid)
        {
            byte[] gammaArray = new byte[6156];
            byte[] gammaArrayTmp = new byte[2052];
            int[] inputArray = new int[1024];
            double tmp = 0;
            int i = 0;
            bool result = false;

            gammaArrayTmp[0] = 0x00;
            gammaArrayTmp[1] = 0x00;
            gammaArrayTmp[2050] = 0x00;
            gammaArrayTmp[2051] = 0x00;

            for (i = 1; i <= 1024; i++)
            {
                // 16383 = 0x3F
                tmp = 16383 * Math.Pow(((double)i / 1024.0), (gamma / gammaMapping));
                inputArray[i - 1] = (int)tmp;
            }

            for (i = 2; i <= 2048; i = i + 2)
            {
                gammaArrayTmp[i] = (byte)(inputArray[i / 2 - 1] / 256);
                gammaArrayTmp[i + 1] = (byte)(inputArray[i / 2 - 1] % 256);
            }

            for (i = 0; i < 6156; i++)
            {
                if (i <= 2051)
                {
                    gammaArray[i] = gammaArrayTmp[i];
                }
                else if (i >= 4104)
                {
                    gammaArray[i] = gammaArrayTmp[i - 4104];
                }
                else
                {
                    gammaArray[i] = gammaArrayTmp[i - 2052];
                }
            }

            //for (i = 0; i < 6156; i++)
            //{
            //    textBox1.Text = textBox1.Text + gammaArray[i].ToString() + ", ";
            //}

            result = Rtddll.DDCCI_WriteGamma(ref gammaArray[0], gammaid);

            return result;
        }
    }
}
