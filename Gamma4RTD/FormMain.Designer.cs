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
            this.buttonRTDRst = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBoxGamId = new System.Windows.Forms.ComboBox();
            this.FrameRTDAct.SuspendLayout();
            this.SuspendLayout();
            // 
            // FrameRTDAct
            // 
            this.FrameRTDAct.Controls.Add(this.comboBoxGamId);
            this.FrameRTDAct.Controls.Add(this.label1);
            this.FrameRTDAct.Controls.Add(this.buttonRTDRst);
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
            this.buttonRTDInit.Location = new System.Drawing.Point(6, 20);
            this.buttonRTDInit.Name = "buttonRTDInit";
            this.buttonRTDInit.Size = new System.Drawing.Size(75, 23);
            this.buttonRTDInit.TabIndex = 0;
            this.buttonRTDInit.Text = "Init";
            this.buttonRTDInit.UseVisualStyleBackColor = true;
            this.buttonRTDInit.Click += new System.EventHandler(this.buttonRTDInit_Click);
            // 
            // buttonRTDRst
            // 
            this.buttonRTDRst.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.buttonRTDRst.Location = new System.Drawing.Point(93, 20);
            this.buttonRTDRst.Name = "buttonRTDRst";
            this.buttonRTDRst.Size = new System.Drawing.Size(75, 23);
            this.buttonRTDRst.TabIndex = 1;
            this.buttonRTDRst.Text = "Reset";
            this.buttonRTDRst.UseVisualStyleBackColor = true;
            this.buttonRTDRst.Click += new System.EventHandler(this.buttonRTDRst_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(6, 58);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "Gamma Table:";
            // 
            // comboBoxGamId
            // 
            this.comboBoxGamId.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxGamId.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.comboBoxGamId.FormattingEnabled = true;
            this.comboBoxGamId.Items.AddRange(new object[] {
            "DICOM",
            "Gamma 2.2",
            "Gamma 2.4",
            "Gamma 2.6",
            "DSA",
            "DSI",
            "CT/MRI",
            "AXCGA"});
            this.comboBoxGamId.Location = new System.Drawing.Point(89, 55);
            this.comboBoxGamId.Name = "comboBoxGamId";
            this.comboBoxGamId.Size = new System.Drawing.Size(79, 20);
            this.comboBoxGamId.TabIndex = 3;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.FrameRTDAct);
            this.Name = "FormMain";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.FrameRTDAct.ResumeLayout(false);
            this.FrameRTDAct.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox FrameRTDAct;
        private System.Windows.Forms.Button buttonRTDInit;
        private System.Windows.Forms.Button buttonRTDRst;
        private System.Windows.Forms.ComboBox comboBoxGamId;
        private System.Windows.Forms.Label label1;
    }
}

