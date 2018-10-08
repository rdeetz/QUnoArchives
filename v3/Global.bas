Attribute VB_Name = "MGlobal"
Option Explicit

Public Function PlayerToString(oPlayer As UnoPlayer) As String
    Dim s As String
    
    If oPlayer Is Nothing Then
        PlayerToString = ""
        Exit Function
    End If
    
    s = oPlayer.Name
    
    Select Case oPlayer.Type
        Case UnoComputer
            s = s & " (Computer)"
        Case UnoHuman
            s = s & " (Human)"
    End Select
    
    PlayerToString = s
    
End Function

Public Function CardToString(oCard As UnoCard) As String
    Dim s As String
    
    If oCard Is Nothing Then
        CardToString = ""
        Exit Function
    End If
    
    If (oCard.Color = UnoNoColor) And (oCard.Value = UnoNoValue) Then
        CardToString = "<Not Initialized>"
        Exit Function
    End If
    
    s = CardColorToString(oCard.Color)
    s = s & " " & CardValueToString(oCard.Value)
    
    CardToString = s
    
End Function

Public Function CardColorToString(eColor As UnoColor) As String
    Dim s As String
    
    Select Case eColor
        Case UnoNoColor
            s = "No Color"
        Case UnoRed
            s = "Red"
        Case UnoBlue
            s = "Blue"
        Case UnoYellow
            s = "Yellow"
        Case UnoGreen
            s = "Green"
        Case Else
            s = "<Invalid Color>"
    End Select
    
    CardColorToString = s
    
End Function

Public Function CardValueToString(eValue As UnoValue) As String
    Dim s As String
    
    Select Case eValue
        Case UnoNoValue
            s = "No Value"
        Case UnoZero
            s = "0"
        Case UnoOne
            s = "1"
        Case UnoTwo
            s = "2"
        Case UnoThree
            s = "3"
        Case UnoFour
            s = "4"
        Case UnoFive
            s = "5"
        Case UnoSix
            s = "6"
        Case UnoSeven
            s = "7"
        Case UnoEight
            s = "8"
        Case UnoNine
            s = "9"
        Case UnoDrawTwo
            s = "Draw Two"
        Case UnoSkip
            s = "Skip"
        Case UnoReverse
            s = "Reverse"
        Case UnoWild
            s = "Wild"
        Case UnoWildDrawFour
            s = "Wild Draw Four"
        Case Else
            s = "<Invalid Value>"
    End Select
    
    CardValueToString = s
    
End Function

Public Function PromptForWildColor() As UnoColor
    Dim f As New FWildColor
    f.Show vbModal
    
    PromptForWildColor = f.m_eWildColor
    
End Function
