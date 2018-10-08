VERSION 5.00
Begin VB.Form FDeck 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Deck Test"
   ClientHeight    =   5430
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4215
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Deck.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5430
   ScaleWidth      =   4215
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdPlay 
      Caption         =   "Play"
      Height          =   375
      Left            =   2880
      TabIndex        =   14
      Top             =   4920
      Width           =   1215
   End
   Begin VB.CommandButton cmdDraw 
      Caption         =   "Draw"
      Height          =   375
      Left            =   1560
      TabIndex        =   13
      Top             =   4920
      Width           =   1215
   End
   Begin VB.ListBox lstHand 
      Height          =   1620
      Index           =   1
      Left            =   2160
      TabIndex        =   12
      Top             =   3120
      Width           =   1935
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   1
      Left            =   2160
      TabIndex        =   11
      Top             =   2760
      Width           =   1935
   End
   Begin VB.ListBox lstHand 
      Height          =   1620
      Index           =   0
      Left            =   120
      TabIndex        =   10
      Top             =   3120
      Width           =   1935
   End
   Begin VB.OptionButton optPlayer 
      Caption         =   "Option1"
      Height          =   255
      Index           =   0
      Left            =   120
      TabIndex        =   9
      Top             =   2760
      Width           =   1935
   End
   Begin VB.Frame fraDeck 
      Caption         =   "Deck Info"
      Height          =   1935
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   3975
      Begin VB.Label lblWildColor 
         Caption         =   "<No Wild Color>"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   8
         Top             =   1440
         Width           =   1935
      End
      Begin VB.Label lblActiveCard 
         Caption         =   "<No Active Card>"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   6
         Top             =   1080
         Width           =   1935
      End
      Begin VB.Label lblPlayedStackCount 
         Caption         =   "0"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   4
         Top             =   720
         Width           =   1935
      End
      Begin VB.Label lblDrawStackCount 
         Caption         =   "0"
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   1680
         TabIndex        =   2
         Top             =   360
         Width           =   1935
      End
      Begin VB.Label Label4 
         Caption         =   "Wild Color"
         Height          =   255
         Left            =   360
         TabIndex        =   7
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label Label3 
         Caption         =   "Active Card"
         Height          =   255
         Left            =   360
         TabIndex        =   5
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label2 
         Caption         =   "Played Count"
         Height          =   255
         Left            =   360
         TabIndex        =   3
         Top             =   720
         Width           =   1095
      End
      Begin VB.Label Label1 
         Caption         =   "Draw Count"
         Height          =   255
         Left            =   360
         TabIndex        =   1
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Label lblCantPlay 
      Caption         =   "You can't play that card!"
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   240
      TabIndex        =   15
      Top             =   2280
      Visible         =   0   'False
      Width           =   3735
   End
End
Attribute VB_Name = "FDeck"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public m_Deck As UnoDeck
Public m_Players As UnoPlayers
Public m_eWildColor As UnoColor
Public m_lPlayerIndex As Integer

Private Sub Form_Load()
    Set m_Deck = New UnoDeck
    Set m_Players = New UnoPlayers
    
    Dim a As UnoPlayer
    Set a = New UnoPlayer
    a.Name = "Roger"
    a.Type = UnoComputer
    m_Players.Add a
    optPlayer(0).Caption = PlayerToString(a)
    
    Dim b As UnoPlayer
    Set b = New UnoPlayer
    b.Name = "Nadine"
    b.Type = UnoHuman
    m_Players.Add b
    optPlayer(1).Caption = PlayerToString(b)
    
    DealCards
    
    m_eWildColor = UnoNoColor
    m_lPlayerIndex = 0
    
    optPlayer(m_lPlayerIndex).Value = True
    
    RefreshDeck
    RefreshHands
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    m_Players.Clear
    
    Set m_Players = Nothing
    Set m_Deck = Nothing
    
End Sub

Private Sub cmdDraw_Click()
    Dim pCard As UnoCard
    Set pCard = m_Deck.Draw()
    
    If pCard Is Nothing Then
        Exit Sub
    End If
    
    m_Players(m_lPlayerIndex).Hand.Add pCard
    
    RefreshHands
    RefreshDeck
    
End Sub

Private Sub cmdPlay_Click()
    Dim lCard As Integer
    lCard = lstHand(m_lPlayerIndex).ListIndex
    
    Dim pCard As UnoCard
    Set pCard = m_Players(m_lPlayerIndex).Hand(lCard)
    
    If pCard Is Nothing Then
        Exit Sub
    End If
    
    Dim bPlayable As Boolean
    bPlayable = IsCardPlayable(pCard)
    
    If bPlayable Then
        m_Deck.Play pCard
        m_Players(m_lPlayerIndex).Hand.Remove lCard
        
        If IsCardWild(pCard) Then
            m_eWildColor = PromptForWildColor()
        Else
            m_eWildColor = UnoNoColor
        End If
        
        RefreshHands
        RefreshDeck
    
    Else
        lblCantPlay.Visible = True
    End If
    
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
    
    lblCantPlay.Visible = False
    
End Sub

Private Sub lstHand_Click(Index As Integer)
    lblCantPlay.Visible = False
    
End Sub

Private Sub DealCards()
    Dim j As Integer
    For j = 0 To 4
        Dim i As Integer
        For i = 0 To (m_Players.Count - 1)
            Dim pCard As UnoCard
            Set pCard = m_Deck.Draw()
            
            If Not (pCard Is Nothing) Then
                m_Players(i).Hand.Add pCard
            End If
            
        Next i
    Next j
    
    Dim pActiveCard As UnoCard
    Set pActiveCard = m_Deck.Draw()
    
    If pActiveCard Is Nothing Then
        Exit Sub
    End If
    
    m_Deck.Play pActiveCard

End Sub

Private Function IsCardWild(pCard As UnoCard) As Boolean
    Dim bWild As Boolean
    bWild = False
    
    If (pCard.Value = UnoWild) Or (pCard.Value = UnoWildDrawFour) Then
        bWild = True
    End If
    
    IsCardWild = bWild

End Function

Private Function IsCardPlayable(pCard As UnoCard) As Boolean
    Dim bPlayable As Boolean
    bPlayable = True
    
    Dim pActiveCard As UnoCard
    Set pActiveCard = m_Deck.ActiveCard
    
    If Not IsCardWild(pCard) Then
        If IsCardWild(pActiveCard) Then
            If pCard.Color <> m_eWildColor Then
                bPlayable = False
            End If
        Else
            If Not ((pCard.Value = pActiveCard.Value) Or (pCard.Color = pActiveCard.Color)) Then
                bPlayable = False
            End If
        End If
    End If
    
    IsCardPlayable = bPlayable

End Function

Private Sub RefreshDeck()
    lblDrawStackCount.Caption = m_Deck.DrawCount
    lblPlayedStackCount.Caption = m_Deck.PlayedCount
    lblActiveCard.Caption = CardToString(m_Deck.ActiveCard)
    lblWildColor.Caption = CardColorToString(m_eWildColor)
    
    lblCantPlay.Visible = False
    
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

