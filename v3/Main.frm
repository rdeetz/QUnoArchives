VERSION 5.00
Begin VB.Form FMain 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "RogCorp QUno Engine Test"
   ClientHeight    =   3150
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4350
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3150
   ScaleWidth      =   4350
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdCardView 
      Caption         =   "CardView Test"
      Height          =   495
      Left            =   1560
      TabIndex        =   4
      Top             =   840
      Width           =   1215
   End
   Begin VB.CommandButton cmdGame 
      Caption         =   "Game Test"
      Height          =   495
      Left            =   120
      TabIndex        =   3
      Top             =   840
      Width           =   1215
   End
   Begin VB.CommandButton cmdDeck 
      Caption         =   "Deck Test"
      Height          =   495
      Left            =   3000
      TabIndex        =   2
      Top             =   120
      Width           =   1215
   End
   Begin VB.CommandButton cmdExit 
      Caption         =   "Exit"
      Height          =   495
      Left            =   3000
      TabIndex        =   5
      Top             =   2520
      Width           =   1215
   End
   Begin VB.CommandButton cmdHand 
      Caption         =   "Hand Test"
      Enabled         =   0   'False
      Height          =   495
      Left            =   1560
      TabIndex        =   1
      Top             =   120
      Width           =   1215
   End
   Begin VB.CommandButton cmdPlayer 
      Caption         =   "Player Test"
      Height          =   495
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "FMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdPlayer_Click()
    FPlayer.Show vbModal
    
End Sub

Private Sub cmdHand_Click()
    FHand.Show vbModal
    
End Sub

Private Sub cmdDeck_Click()
    FDeck.Show vbModal
    
End Sub

Private Sub cmdGame_Click()
    FGame.Show vbModal
    
End Sub

Private Sub cmdCardView_Click()
    FCardView.Show vbModal
    
End Sub

Private Sub cmdExit_Click()
    Unload Me
    
End Sub
