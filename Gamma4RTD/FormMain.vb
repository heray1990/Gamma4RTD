Public Class FormMain
    Public Declare Function RTD2758Init Lib "rtddll.dll" () As Boolean
    Private Sub ButtonRTDInit_Click(sender As Object, e As EventArgs) Handles ButtonRTDInit.Click
        If RTD2758Init Then
            LabelRTDState.Text = "初始化成功"
        Else
            LabelRTDState.Text = "初始化失败"
        End If
    End Sub
End Class
