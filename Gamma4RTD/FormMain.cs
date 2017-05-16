using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Gamma4RTD
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void buttonRTDInit_Click(object sender, EventArgs e)
        {
            if (Rtddll.RTD2758Init())
            {
                MessageBox.Show("True");
            }
            else
            {
                MessageBox.Show("False");
            }
        }

        private void buttonRTDRst_Click(object sender, EventArgs e)
        {
            Rtddll.RTD2758_Reset();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            comboBoxGamId.SelectedIndex = 0;
        }

        private void buttonRTDWrite_Click(object sender, EventArgs e)
        {
            new Thread(new ThreadStart(StartWriteGamma)).Start();
        }

        public void StartWriteGamma()
        {
            bool isDone = false;
            isDone = DccCiWriteGamma(2.2, 3.454, 5);
            if (isDone)
            {
                MessageBox.Show("True");
            }
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
            Application.DoEvents();

            return result;
        }

        private void buttonRTDErase_Click(object sender, EventArgs e)
        {
            Rtddll.DDCCI_EraseGamma(4);
        }
    }
}
