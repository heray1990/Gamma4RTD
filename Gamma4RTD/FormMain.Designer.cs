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
            this.buttonRTDErase = new System.Windows.Forms.Button();
            this.buttonRTDWrite = new System.Windows.Forms.Button();
            this.comboBoxGamId = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonRTDRst = new System.Windows.Forms.Button();
            this.buttonRTDInit = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.progressBarWrite = new System.Windows.Forms.ProgressBar();
            this.FrameRTDAct.SuspendLayout();
            this.SuspendLayout();
            // 
            // FrameRTDAct
            // 
            this.FrameRTDAct.Controls.Add(this.progressBarWrite);
            this.FrameRTDAct.Controls.Add(this.buttonRTDErase);
            this.FrameRTDAct.Controls.Add(this.buttonRTDWrite);
            this.FrameRTDAct.Controls.Add(this.comboBoxGamId);
            this.FrameRTDAct.Controls.Add(this.label1);
            this.FrameRTDAct.Controls.Add(this.buttonRTDRst);
            this.FrameRTDAct.Controls.Add(this.buttonRTDInit);
            this.FrameRTDAct.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FrameRTDAct.Location = new System.Drawing.Point(0, 0);
            this.FrameRTDAct.Name = "FrameRTDAct";
            this.FrameRTDAct.Size = new System.Drawing.Size(176, 164);
            this.FrameRTDAct.TabIndex = 0;
            this.FrameRTDAct.TabStop = false;
            this.FrameRTDAct.Text = "RTD Action";
            // 
            // buttonRTDErase
            // 
            this.buttonRTDErase.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.buttonRTDErase.Location = new System.Drawing.Point(93, 86);
            this.buttonRTDErase.Name = "buttonRTDErase";
            this.buttonRTDErase.Size = new System.Drawing.Size(75, 23);
            this.buttonRTDErase.TabIndex = 5;
            this.buttonRTDErase.Text = "Erase";
            this.buttonRTDErase.UseVisualStyleBackColor = true;
            this.buttonRTDErase.Click += new System.EventHandler(this.buttonRTDErase_Click);
            // 
            // buttonRTDWrite
            // 
            this.buttonRTDWrite.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.buttonRTDWrite.Location = new System.Drawing.Point(8, 86);
            this.buttonRTDWrite.Name = "buttonRTDWrite";
            this.buttonRTDWrite.Size = new System.Drawing.Size(75, 23);
            this.buttonRTDWrite.TabIndex = 4;
            this.buttonRTDWrite.Text = "Write";
            this.buttonRTDWrite.UseVisualStyleBackColor = true;
            this.buttonRTDWrite.Click += new System.EventHandler(this.buttonRTDWrite_Click);
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
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 200);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(260, 50);
            this.textBox1.TabIndex = 1;
            // 
            // progressBarWrite
            // 
            this.progressBarWrite.Location = new System.Drawing.Point(8, 115);
            this.progressBarWrite.Name = "progressBarWrite";
            this.progressBarWrite.Size = new System.Drawing.Size(160, 23);
            this.progressBarWrite.TabIndex = 11;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.FrameRTDAct);
            this.Name = "FormMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.FrameRTDAct.ResumeLayout(false);
            this.FrameRTDAct.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox FrameRTDAct;
        private System.Windows.Forms.Button buttonRTDInit;
        private System.Windows.Forms.Button buttonRTDRst;
        private System.Windows.Forms.ComboBox comboBoxGamId;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button buttonRTDWrite;
        private System.Windows.Forms.Button buttonRTDErase;
        private System.Windows.Forms.ProgressBar progressBarWrite;
    }
}

