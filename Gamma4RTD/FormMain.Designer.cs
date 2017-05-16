namespace Gamma4RTD
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.FrameRTDAct = new System.Windows.Forms.GroupBox();
            this.buttonRTDInit = new System.Windows.Forms.Button();
            this.FrameRTDAct.SuspendLayout();
            this.SuspendLayout();
            // 
            // FrameRTDAct
            // 
            this.FrameRTDAct.Controls.Add(this.buttonRTDInit);
            this.FrameRTDAct.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FrameRTDAct.Location = new System.Drawing.Point(0, 0);
            this.FrameRTDAct.Name = "FrameRTDAct";
            this.FrameRTDAct.Size = new System.Drawing.Size(226, 131);
            this.FrameRTDAct.TabIndex = 0;
            this.FrameRTDAct.TabStop = false;
            this.FrameRTDAct.Text = "RTD Action";
            // 
            // buttonRTDInit
            // 
            this.buttonRTDInit.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.buttonRTDInit.Location = new System.Drawing.Point(3, 17);
            this.buttonRTDInit.Name = "buttonRTDInit";
            this.buttonRTDInit.Size = new System.Drawing.Size(75, 23);
            this.buttonRTDInit.TabIndex = 0;
            this.buttonRTDInit.Text = "Init";
            this.buttonRTDInit.UseVisualStyleBackColor = true;
            this.buttonRTDInit.Click += new System.EventHandler(this.buttonRTDInit_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.FrameRTDAct);
            this.Name = "FormMain";
            this.Text = "Form1";
            this.FrameRTDAct.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox FrameRTDAct;
        private System.Windows.Forms.Button buttonRTDInit;
    }
}

