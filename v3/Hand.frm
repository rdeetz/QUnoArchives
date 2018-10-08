VERSION 5.00
Begin VB.Form FHand 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Hand Test"
   ClientHeight    =   3645
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8670
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Hand.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3645
   ScaleWidth      =   8670
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdClear 
      Caption         =   "Clear"
      Height          =   375
      Left            =   7320
      TabIndex        =   11
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton cmdRemove 
      Caption         =   "Remove"
      Height          =   375
      Left            =   7320
      TabIndex        =   10
      Top             =   720
      Width           =   1215
   End
   Begin VB.CommandButton cmdMove 
      Caption         =   "Move"
      Height          =   375
      Left            =   7320
      TabIndex        =   9
      Top             =   120
      Width           =   1215
   End
   Begin VB.ComboBox cboPlayers 
      Height          =   315
      Left            =   5400
      Style           =   2  'Dropdown List
      TabIndex        =   8
      Top             =   120
      Width           =   1815
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   3
      Left            =   2760
      TabIndex        =   6
      Top             =   1920
      Width           =   2415
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   2
      Left            =   120
      TabIndex        =   4
      Top             =   1920
      Width           =   2415
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   1
      Left            =   2760
      TabIndex        =   2
      Top             =   120
      Width           =   2415
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   0
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2415
   End
   Begin VB.ListBox lstHand 
      Height          =   1230
      Index           =   3
      Left            =   2760
      TabIndex        =   7
      Top             =   2280
      Width           =   2415
   End
   Begin VB.ListBox lstHand 
      Height          =   1230
      Index           =   2
      Left            =   120
      TabIndex        =   5
      Top             =   2280
      Width           =   2415
   End
   Begin VB.ListBox lstHand 
      Height          =   1230
      Index           =   1
      Left            =   2760
      TabIndex        =   3
      Top             =   480
      Width           =   2415
   End
   Begin VB.ListBox lstHand 
      Height          =   1230
      Index           =   0
      Left            =   120
      TabIndex        =   1
      Top             =   480
      Width           =   2415
   End
End
Attribute VB_Name = "FHand"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public m_Players As UnoPlayers
Public m_lPlayerIndex As Integer

Private Sub Form_Load()
    Set m_Players = New UnoPlayers
    
    Dim s As String
    
    Dim a As UnoPlayer
    Set a = New UnoPlayer
    a.Name = "Roger"
    a.Type = UnoComputer
    m_Players.Add a
    s = PlayerToString(a)
    optPlayer(0).Caption = s
    cboPlayers.AddItem s
    
        Dim c1 As UnoCard
        Set c1 = New UnoCard
        a.Hand.Add c1
        a.Hand.InitCard 0, UnoWild, UnoNoColor
    
        Dim c2 As UnoCard
        Set c2 = New UnoCard
        a.Hand.Add c2
        a.Hand.InitCard 1, UnoFive, UnoRed
    
    Dim b As UnoPlayer
    Set b = New UnoPlayer
    b.Name = "Nadine"
    b.Type = UnoHuman
    m_Players.Add b
    s = PlayerToString(b)
    optPlayer(1).Caption = s
    cboPlayers.AddItem s
    
        Dim c3 As UnoCard
        Set c3 = New UnoCard
        b.Hand.Add c3
        b.Hand.InitCard 0, UnoDrawTwo, UnoYellow
    
        Dim c4 As UnoCard
        Set c4 = New UnoCard
        b.Hand.Add c4
        b.Hand.InitCard 1, UnoSeven, UnoBlue
        
    Dim c As UnoPlayer
    Set c = New UnoPlayer
    c.Name = "Livy"
    c.Type = UnoHuman
    m_Players.Add c
    s = PlayerToString(c)
    optPlayer(2).Caption = s
    cboPlayers.AddItem s
    
        Dim c5 As UnoCard
        Set c5 = New UnoCard
        c.Hand.Add c5
        c.Hand.InitCard 0, UnoWildDrawFour, UnoNoColor
    
        Dim c6 As UnoCard
        Set c6 = New UnoCard
        c.Hand.Add c6
        c.Hand.InitCard 1, UnoSkip, UnoGreen
        
    Dim d As UnoPlayer
    Set d = New UnoPlayer
    d.Name = "Sally"
    d.Type = UnoComputer
    m_Players.Add d
    s = PlayerToString(d)
    optPlayer(3).Caption = s
    cboPlayers.AddItem s
    
        Dim c7 As UnoCard
        Set c7 = New UnoCard
        d.Hand.Add c7
        d.Hand.InitCard 0, UnoNine, UnoRed
    
        Dim c8 As UnoCard
        Set c8 = New UnoCard
        d.Hand.Add c8
        d.Hand.InitCard 1, UnoReverse, UnoBlue
        
    RefreshHands
    
    optPlayer(0).Value = True
    cboPlayers.ListIndex = 0
    m_lPlayerIndex = 0
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    m_Players.Clear
    
    Set m_Players = Nothing
    
End Sub

Private Sub optPlayer_Click(Index As Integer)
    Dim i As Integer
    For i = 0 To (m_Players.Count - 1)
        lstHand(i).Enabled = False
    Next i
    
    With lstHand(Index)
        .Enabled = True
        
        If (.ListCount > 0) Then
            .ListIndex = 0
        End If
        
    End With
    
    m_lPlayerIndex = Index
    
End Sub

Private Sub cmdMove_Click()
    Dim lTarget As Integer
    lTarget = cboPlayers.ListIndex
    
    If m_lPlayerIndex = lTarget Then
        Exit Sub
    End If
    
    Dim lCard As Integer
    lCard = lstHand(m_lPlayerIndex).ListIndex
    
    ' explicitly using Item
    Dim pCard As UnoCard
    Set pCard = m_Players.Item(m_lPlayerIndex).Hand.Item(lCard)
    
    If pCard Is Nothing Then
        Exit Sub
    End If
    
    ' using default value
    m_Players(lTarget).Hand.Add m_Players(m_lPlayerIndex).Hand.Remove(lCard)
    
    RefreshHands
    
End Sub

Private Sub cmdRemove_Click()
    Dim lCard As Integer
    lCard = lstHand(m_lPlayerIndex).ListIndex
    
    m_Players(m_lPlayerIndex).Hand.Remove lCard

    RefreshHands

End Sub

Private Sub cmdClear_Click()
    m_Players(m_lPlayerIndex).Hand.Clear
    
    RefreshHands

End Sub

Private Sub RefreshHands()
    Dim i As Integer
    For i = 0 To (m_Players.Count - 1)
        lstHand(i).Clear
        
        Dim c As UnoCard
        For Each c In m_Players(i).Hand
            lstHand(i).AddItem CardToString(c)
        Next c
        
    Next i
    
End Sub
