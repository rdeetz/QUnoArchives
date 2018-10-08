VERSION 5.00
Begin VB.Form FGame 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Game Test"
   ClientHeight    =   5775
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6270
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Game.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5775
   ScaleWidth      =   6270
   StartUpPosition =   2  'CenterScreen
   Begin VB.ListBox lstStillPlaying 
      ForeColor       =   &H80000011&
      Height          =   840
      Left            =   4320
      TabIndex        =   25
      TabStop         =   0   'False
      Top             =   1920
      Width           =   1815
   End
   Begin VB.CommandButton cmdPass 
      Caption         =   "Pass"
      Height          =   375
      Left            =   4920
      TabIndex        =   18
      Top             =   5280
      Width           =   1215
   End
   Begin VB.CheckBox chkPlayAfterDraw 
      Caption         =   "Play After Draw"
      Height          =   255
      Left            =   4320
      TabIndex        =   23
      Top             =   120
      Width           =   1575
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   2
      Left            =   4200
      TabIndex        =   14
      Top             =   3120
      Width           =   1935
   End
   Begin VB.ListBox lstHand 
      Height          =   1620
      Index           =   2
      Left            =   4200
      TabIndex        =   15
      Top             =   3480
      Width           =   1935
   End
   Begin VB.Frame fraDeck 
      Caption         =   "Deck Info"
      Height          =   1935
      Left            =   120
      TabIndex        =   1
      Top             =   480
      Width           =   3975
      Begin VB.Label Label1 
         Caption         =   "Draw Count"
         Height          =   255
         Left            =   360
         TabIndex        =   2
         Top             =   360
         Width           =   1095
      End
      Begin VB.Label Label2 
         Caption         =   "Played Count"
         Height          =   255
         Left            =   360
         TabIndex        =   4
         Top             =   720
         Width           =   1095
      End
      Begin VB.Label Label3 
         Caption         =   "Active Card"
         Height          =   255
         Left            =   360
         TabIndex        =   6
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label4 
         Caption         =   "Wild Color"
         Height          =   255
         Left            =   360
         TabIndex        =   8
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label lblDrawStackCount 
         Caption         =   "0"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   3
         Top             =   360
         Width           =   1935
      End
      Begin VB.Label lblPlayedStackCount 
         Caption         =   "0"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   5
         Top             =   720
         Width           =   1935
      End
      Begin VB.Label lblActiveCard 
         Caption         =   "<No Active Card>"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   7
         Top             =   1080
         Width           =   1935
      End
      Begin VB.Label lblWildColor 
         Caption         =   "<No Wild Color>"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   9
         Top             =   1440
         Width           =   1935
      End
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   0
      Left            =   120
      TabIndex        =   10
      Top             =   3120
      Width           =   1935
   End
   Begin VB.ListBox lstHand 
      Height          =   1620
      Index           =   0
      Left            =   120
      TabIndex        =   11
      Top             =   3480
      Width           =   1935
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   1
      Left            =   2160
      TabIndex        =   12
      Top             =   3120
      Width           =   1935
   End
   Begin VB.ListBox lstHand 
      Height          =   1620
      Index           =   1
      Left            =   2160
      TabIndex        =   13
      Top             =   3480
      Width           =   1935
   End
   Begin VB.CommandButton cmdDraw 
      Caption         =   "Draw"
      Height          =   375
      Left            =   2280
      TabIndex        =   16
      Top             =   5280
      Width           =   1215
   End
   Begin VB.CommandButton cmdPlay 
      Caption         =   "Play"
      Height          =   375
      Left            =   3600
      TabIndex        =   17
      Top             =   5280
      Width           =   1215
   End
   Begin VB.Label lblPlayerUno 
      Caption         =   "<Player> has UNO!"
      Height          =   255
      Left            =   120
      TabIndex        =   22
      Top             =   5280
      Visible         =   0   'False
      Width           =   2055
   End
   Begin VB.Label lblPlayerOut 
      Caption         =   "<Player> is out!"
      ForeColor       =   &H0000C000&
      Height          =   495
      Left            =   4320
      TabIndex        =   21
      Top             =   1080
      Visible         =   0   'False
      Width           =   1815
   End
   Begin VB.Label lblGameOver 
      Caption         =   "Game Over!"
      ForeColor       =   &H0000C000&
      Height          =   255
      Left            =   4320
      TabIndex        =   20
      Top             =   600
      Visible         =   0   'False
      Width           =   1815
   End
   Begin VB.Label lblGameTitle 
      Caption         =   "<Game>"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   3975
   End
   Begin VB.Label lblCantPass 
      Caption         =   "You can't pass!"
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   240
      TabIndex        =   24
      Top             =   2640
      Visible         =   0   'False
      Width           =   3735
   End
   Begin VB.Label lblCantPlay 
      Caption         =   "You can't play that card!"
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   240
      TabIndex        =   19
      Top             =   2640
      Visible         =   0   'False
      Width           =   3735
   End
End
Attribute VB_Name = "FGame"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' NOTE: in all of these cases, rather than always Refresh when
'       something interesting has happened, i could just update
'       when needed, based on what happened

Option Explicit

Public WithEvents m_Game As UnoGame
Attribute m_Game.VB_VarHelpID = -1

Private m_lPlayerIndex As Integer
Private m_clStillPlaying As Collection

Private Sub Form_Load()
    Set m_Game = New UnoGame
    Set m_clStillPlaying = New Collection
    
    m_Game.Title = "My New Game"
    m_Game.PlayAfterDraw = False
    
    m_Game.CreatePlayer "Roger", UnoHuman
    m_Game.CreatePlayer "Nadine", UnoHuman
    m_Game.CreatePlayer "Livy", UnoHuman
    
    Dim i As Integer
    For i = 0 To (m_Game.Players.Count - 1)
        optPlayer(i).Caption = PlayerToString(m_Game.Players(i))
        m_clStillPlaying.Add i, "p" & i
    Next i
    
    m_Game.Start
    
    RefreshDeck
    RefreshHands
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    m_Game.Stop
    
    Set m_Game = Nothing
    
End Sub

Private Sub cmdDraw_Click()
    m_Game.Players(m_lPlayerIndex).Draw
    
    RefreshHands
    RefreshDeck
    
End Sub

Private Sub cmdPlay_Click()
    Dim lCard As Integer
    lCard = lstHand(m_lPlayerIndex).ListIndex
    
    Dim pCard As UnoCard
    Set pCard = m_Game.Players(m_lPlayerIndex).Hand(lCard)

    If pCard Is Nothing Then
        Exit Sub
    End If

    Dim bPlayed As Boolean
    bPlayed = m_Game.Players(m_lPlayerIndex).Play(lCard)
    
    If bPlayed Then
        RefreshHands
        RefreshDeck
    Else
        lblCantPlay.Visible = True
    End If
    
End Sub

Private Sub cmdPass_Click()
    Dim bPassed As Boolean
    bPassed = m_Game.Players(m_lPlayerIndex).Pass()
    
    If bPassed Then
        RefreshHands
        RefreshDeck
    Else
        lblCantPass.Visible = True
    End If
    
End Sub

Private Sub lstHand_Click(Index As Integer)
    lblCantPlay.Visible = False
    lblCantPass.Visible = False
    
End Sub

Private Sub chkPlayAfterDraw_Click()
    If chkPlayAfterDraw.Value = vbChecked Then
        m_Game.PlayAfterDraw = True
    Else
        m_Game.PlayAfterDraw = False
    End If
    
End Sub

Private Sub RefreshDeck()
    lblGameTitle.Caption = m_Game.Title

    If m_Game.PlayAfterDraw Then
        chkPlayAfterDraw.Value = vbChecked
    Else
        chkPlayAfterDraw.Value = vbUnchecked
    End If
    
    lblDrawStackCount.Caption = m_Game.Deck.DrawCount
    lblPlayedStackCount.Caption = m_Game.Deck.PlayedCount
    lblActiveCard.Caption = CardToString(m_Game.Deck.ActiveCard)
    lblWildColor.Caption = CardColorToString(m_Game.WildColor)
    
    lblCantPlay.Visible = False
    lblCantPass.Visible = False
    
    lstStillPlaying.Clear
    
    Dim l As Variant
    For Each l In m_clStillPlaying
        lstStillPlaying.AddItem PlayerToString(m_Game.Players(l))
    Next l
    
End Sub

Private Sub RefreshHands()
    Dim i As Integer
    For i = 0 To (m_Game.Players.Count - 1)
        lstHand(i).Clear
        
        Dim c As UnoCard
        For Each c In m_Game.Players(i).Hand
            lstHand(i).AddItem CardToString(c)
        Next c
        
    Next i
    
End Sub

Private Sub ChangePlayerTurn(ByVal lIndex As Integer)
    m_lPlayerIndex = lIndex
    
    Dim i As Integer
    For i = 0 To (m_Game.Players.Count - 1)
        optPlayer(i).ForeColor = vbBlack
        lstHand(i).Enabled = False
    Next i
    
    optPlayer(m_lPlayerIndex).ForeColor = vbRed
    optPlayer(m_lPlayerIndex).Value = True
    
    With lstHand(m_lPlayerIndex)
        .Enabled = True
        
        If (.ListCount > 0) Then
            .ListIndex = 0
        End If
        
    End With
    
    lblCantPlay.Visible = False
    lblCantPass.Visible = False
    
End Sub

Private Sub m_Game_PlayerTurn(ByVal lPlayer As Long)
    Dim pPlayer As UnoPlayer
    Set pPlayer = m_Game.Players(lPlayer)
    
    If pPlayer Is Nothing Then
        Exit Sub
    End If

    ChangePlayerTurn lPlayer
    
End Sub

Private Sub m_Game_PlayerChooseWildColor(ByVal lPlayer As Long, peColor As QEngineLib.UnoColor)
    Dim pPlayer As UnoPlayer
    Set pPlayer = m_Game.Players(lPlayer)
    
    If pPlayer Is Nothing Then
        Exit Sub
    End If
    
    peColor = PromptForWildColor()
    
End Sub

Private Sub m_Game_PlayerUno(ByVal lPlayer As Long)
    Dim pPlayer As UnoPlayer
    Set pPlayer = m_Game.Players(lPlayer)
    
    If pPlayer Is Nothing Then
        Exit Sub
    End If
    
    Dim s As String
    s = (PlayerToString(pPlayer) & " has UNO!")
    
    lblPlayerUno.Caption = s
    lblPlayerUno.Visible = True
    
End Sub

Private Sub m_Game_PlayerOut(ByVal lPlayer As Long, pbKeepPlaying As Boolean)
    Dim pPlayer As UnoPlayer
    Set pPlayer = m_Game.Players(lPlayer)
    
    If pPlayer Is Nothing Then
        Exit Sub
    End If
    
    Dim s As String
    s = (PlayerToString(pPlayer) & " is out!")
    
    lblPlayerOut.Caption = s
    lblPlayerOut.Visible = True
    
    m_clStillPlaying.Remove "p" & lPlayer
    
    If m_clStillPlaying.Count() <= 1 Then
        pbKeepPlaying = False
        Exit Sub
    End If
    
    Dim nResult As VbMsgBoxResult
    nResult = MsgBox("Do you want to keep playing?", vbYesNo + vbQuestion, "RogCorp QUno Engine Test")
    
    If nResult = vbYes Then
        pbKeepPlaying = True
    Else
        pbKeepPlaying = False
    End If
    
End Sub

Private Sub m_Game_GameOver()
    lblGameOver.Visible = True

    Dim i As Integer
    For i = 0 To (m_Game.Players.Count - 1)
        optPlayer(i).ForeColor = vbBlack
        optPlayer(i).Enabled = False
        lstHand(i).Enabled = False
    Next i

End Sub
