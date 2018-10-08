VERSION 5.00
Begin VB.Form FWildColor 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Choose Wild Color"
   ClientHeight    =   1695
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   2910
   ControlBox      =   0   'False
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "WildColor.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1695
   ScaleWidth      =   2910
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdGreen 
      Caption         =   "Green"
      Height          =   375
      Left            =   1560
      TabIndex        =   5
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton cmdYellow 
      Caption         =   "Yellow"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton cmdBlue 
      Caption         =   "Blue"
      Height          =   375
      Left            =   1560
      TabIndex        =   3
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton cmdRed 
      Caption         =   "Red"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   600
      Width           =   1215
   End
   Begin VB.Label lblWildColor 
      Caption         =   "<No Wild Color>"
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   840
      TabIndex        =   1
      Top             =   120
      Width           =   1935
   End
   Begin VB.Label Label1 
      Caption         =   "Color:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   615
   End
End
Attribute VB_Name = "FWildColor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public m_eWildColor As UnoColor

Private Sub Form_Load()
    m_eWildColor = UnoNoColor
    
End Sub

Private Sub cmdRed_Click()
    m_eWildColor = UnoRed
    
    lblWildColor.Caption = CardColorToString(m_eWildColor)
    
    Unload Me

End Sub

Private Sub cmdBlue_Click()
    m_eWildColor = UnoBlue
    
    lblWildColor.Caption = CardColorToString(m_eWildColor)
    
    Unload Me

End Sub

Private Sub cmdYellow_Click()
    m_eWildColor = UnoYellow
    
    lblWildColor.Caption = CardColorToString(m_eWildColor)
    
    Unload Me

End Sub

Private Sub cmdGreen_Click()
    m_eWildColor = UnoGreen
    
    lblWildColor.Caption = CardColorToString(m_eWildColor)
    
    Unload Me

End Sub

