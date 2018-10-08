VERSION 5.00
Begin VB.Form FPlayer 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Player Test"
   ClientHeight    =   5670
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5775
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Player.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5670
   ScaleWidth      =   5775
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdFree 
      Caption         =   "Free"
      Height          =   375
      Left            =   4440
      TabIndex        =   17
      Top             =   5160
      Width           =   1215
   End
   Begin VB.CommandButton cmdStrand 
      Caption         =   "Strand"
      Height          =   375
      Left            =   4440
      TabIndex        =   16
      Top             =   4680
      Width           =   1215
   End
   Begin VB.Frame fraPlayer 
      Caption         =   "Player"
      Height          =   1335
      Left            =   2520
      TabIndex        =   8
      Top             =   2160
      Width           =   3135
      Begin VB.CommandButton cmdSavePlayer 
         Caption         =   "Save"
         Height          =   375
         Left            =   1800
         TabIndex        =   11
         Top             =   840
         Width           =   1215
      End
      Begin VB.CheckBox chkComputer 
         Caption         =   "Computer"
         Height          =   255
         Left            =   1920
         TabIndex        =   10
         Top             =   360
         Width           =   1095
      End
      Begin VB.TextBox txtPlayer 
         Height          =   285
         Left            =   240
         TabIndex        =   9
         Top             =   360
         Width           =   1575
      End
   End
   Begin VB.CommandButton cmdClear 
      Caption         =   "Clear"
      Height          =   375
      Left            =   4440
      TabIndex        =   15
      Top             =   4200
      Width           =   1215
   End
   Begin VB.CommandButton cmdRemove 
      Caption         =   "Remove"
      Height          =   375
      Left            =   4440
      TabIndex        =   14
      Top             =   3720
      Width           =   1215
   End
   Begin VB.ListBox lstPlayers 
      Height          =   1815
      Left            =   120
      TabIndex        =   13
      Top             =   3720
      Width           =   4095
   End
   Begin VB.TextBox txtPlayerItem 
      Height          =   285
      Left            =   1440
      TabIndex        =   7
      Top             =   2160
      Width           =   855
   End
   Begin VB.Frame fraNewPlayer 
      Caption         =   "New Player"
      Height          =   1815
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   5535
      Begin VB.CheckBox chkNewComputer 
         Caption         =   "Computer"
         Height          =   255
         Left            =   1080
         TabIndex        =   4
         Top             =   960
         Width           =   2535
      End
      Begin VB.CommandButton cmdNewPlayer 
         Caption         =   "New"
         Height          =   375
         Left            =   4200
         TabIndex        =   5
         Top             =   1320
         Width           =   1215
      End
      Begin VB.TextBox txtNewPlayer 
         Height          =   285
         Left            =   1080
         TabIndex        =   2
         Top             =   480
         Width           =   2535
      End
      Begin VB.Label Label2 
         Caption         =   "Type"
         Height          =   255
         Left            =   240
         TabIndex        =   3
         Top             =   960
         Width           =   735
      End
      Begin VB.Label Label1 
         Caption         =   "Name"
         Height          =   255
         Left            =   240
         TabIndex        =   1
         Top             =   480
         Width           =   735
      End
   End
   Begin VB.Label Label5 
      Caption         =   "Players"
      Height          =   255
      Left            =   120
      TabIndex        =   12
      Top             =   3360
      Width           =   1695
   End
   Begin VB.Label Label4 
      Caption         =   "Current Player"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Label lblPlayerCount 
      Caption         =   "0"
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   1320
      TabIndex        =   19
      Top             =   2880
      Width           =   495
   End
   Begin VB.Label Label3 
      Caption         =   "Player Count"
      Height          =   255
      Left            =   120
      TabIndex        =   18
      Top             =   2880
      Width           =   1095
   End
End
Attribute VB_Name = "FPlayer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public m_Players As UnoPlayers
Public m_CurrentPlayer As UnoPlayer
Public m_StrandedPlayer As UnoPlayer

Private Sub Form_Load()
    Set m_Players = New UnoPlayers

End Sub

Private Sub Form_Unload(Cancel As Integer)
    Set m_StrandedPlayer = Nothing
    Set m_CurrentPlayer = Nothing
    
    m_Players.Clear
    
    Set m_Players = Nothing
    
End Sub

Private Sub cmdNewPlayer_Click()
    Dim p As UnoPlayer
    Set p = New UnoPlayer
    
    p.Name = txtNewPlayer.Text
    
    If chkNewComputer.Value = vbChecked Then
        p.Type = UnoComputer
    Else
        p.Type = UnoHuman
    End If
    
    m_Players.Add p
    
    RefreshP
    
End Sub

Private Sub txtPlayerItem_LostFocus()
    Dim p As UnoPlayer
    Set p = m_Players.Item(CLng(txtPlayerItem.Text))
    
    Set m_CurrentPlayer = p
    
    LoadPlayer
    
End Sub

Private Sub cmdSavePlayer_Click()
    SavePlayer
    
End Sub

Private Sub cmdRemove_Click()
    m_Players.Remove lstPlayers.ListIndex
    
    RefreshP
    
End Sub

Private Sub cmdClear_Click()
    m_Players.Clear
    
    RefreshP
    
End Sub

Private Sub cmdStrand_Click()
    Set m_StrandedPlayer = m_Players.Remove(lstPlayers.ListIndex)
    
    RefreshP
    
End Sub

Private Sub cmdFree_Click()
    Set m_StrandedPlayer = Nothing
    
End Sub

Private Sub RefreshP()
    lstPlayers.Clear
    lblPlayerCount.Caption = CStr(m_Players.Count)
    
    Dim p As UnoPlayer
    For Each p In m_Players
        lstPlayers.AddItem PlayerToString(p)
    Next
    
    Set m_CurrentPlayer = Nothing
    
    txtPlayerItem.Text = ""
    txtPlayer.Text = ""
    chkComputer.Value = vbUnchecked
    
    txtNewPlayer.Text = ""
    chkNewComputer.Value = vbUnchecked
    
End Sub

Private Sub LoadPlayer()
    If m_CurrentPlayer Is Nothing Then
        txtPlayer.Text = ""
        chkComputer.Value = vbUnchecked
        Exit Sub
    End If
    
    txtPlayer.Text = m_CurrentPlayer.Name
    
    If m_CurrentPlayer.Type = UnoComputer Then
        chkComputer.Value = vbChecked
    Else
        chkComputer.Value = vbUnchecked
    End If
    
End Sub

Private Sub SavePlayer()
    If m_CurrentPlayer Is Nothing Then
        Exit Sub
    End If
    
    m_CurrentPlayer.Name = txtPlayer.Text
    
    If chkComputer.Value = vbChecked Then
        m_CurrentPlayer.Type = UnoComputer
    Else
        m_CurrentPlayer.Type = UnoHuman
    End If
    
    RefreshP
    
End Sub

