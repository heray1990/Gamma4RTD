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

        private void FormMain_Load(object sender, EventArgs e)
        {
            comboBoxGamId.SelectedIndex = 0;
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

        private void buttonRTDWrite_Click(object sender, EventArgs e)
        {
            new Thread(new ThreadStart(StartWriteGamma)).Start();
        }
        private void buttonRTDErase_Click(object sender, EventArgs e)
        {
            Rtddll.DDCCI_EraseGamma((byte)comboBoxGamId.SelectedIndex);
        }

        private void StartWriteGamma()
        {
            bool isDone = false;
            WriteGamma writeGamma = new WriteGamma();
            writeGamma.onWriteProgress += new WriteGamma.dWriteProgress(WriteGamma_onWriteProgress);
            isDone = writeGamma.Write();
            if (isDone)
            {
                MessageBox.Show("True");
            }
            else
            {
                MessageBox.Show("False");
            }
        }

        private void WriteGamma_onWriteProgress(int total, int current)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new WriteGamma.dWriteProgress(WriteGamma_onWriteProgress), new object[] { total, current });
            }
            else
            {
                this.progressBarWrite.Maximum = total;
                this.progressBarWrite.Value = current;
                int value = (int)(((double)current / (double)total) * 100);
            }
        }

    }
}
