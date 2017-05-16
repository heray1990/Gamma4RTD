<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormMain
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.ButtonRTDInit = New System.Windows.Forms.Button()
        Me.LabelRTDState = New System.Windows.Forms.Label()
        Me.GroupBox1.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.LabelRTDState)
        Me.GroupBox1.Controls.Add(Me.ButtonRTDInit)
        Me.GroupBox1.Location = New System.Drawing.Point(0, 0)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(284, 264)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "RTD"
        '
        'ButtonRTDInit
        '
        Me.ButtonRTDInit.Location = New System.Drawing.Point(33, 63)
        Me.ButtonRTDInit.Name = "ButtonRTDInit"
        Me.ButtonRTDInit.Size = New System.Drawing.Size(75, 23)
        Me.ButtonRTDInit.TabIndex = 0
        Me.ButtonRTDInit.Text = "Init"
        Me.ButtonRTDInit.UseVisualStyleBackColor = True
        '
        'LabelRTDState
        '
        Me.LabelRTDState.BackColor = System.Drawing.SystemColors.ActiveCaption
        Me.LabelRTDState.Font = New System.Drawing.Font("SimSun", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.LabelRTDState.Location = New System.Drawing.Point(12, 17)
        Me.LabelRTDState.Name = "LabelRTDState"
        Me.LabelRTDState.Size = New System.Drawing.Size(117, 43)
        Me.LabelRTDState.TabIndex = 1
        Me.LabelRTDState.Text = "State"
        Me.LabelRTDState.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'FormMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(352, 319)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "FormMain"
        Me.Text = "Form1"
        Me.GroupBox1.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents ButtonRTDInit As Button
    Friend WithEvents LabelRTDState As Label
End Class
