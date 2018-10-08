VERSION 5.00
Object = "{9F88C833-49F7-457A-9ABF-9EB3461B93BE}#1.0#0"; "QCONTROL.DLL"
Begin VB.Form FCardView 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "CardView Test"
   ClientHeight    =   4695
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6030
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "CardView.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4695
   ScaleWidth      =   6030
   StartUpPosition =   2  'CenterScreen
   Begin VB.PictureBox picCard 
      Height          =   1335
      Left            =   4440
      MousePointer    =   2  'Cross
      ScaleHeight     =   1275
      ScaleWidth      =   1395
      TabIndex        =   1
      Top             =   3240
      Width           =   1455
   End
   Begin QControlLibCtl.UnoCardView cvwCard 
      Height          =   2535
      Left            =   240
      OleObjectBlob   =   "CardView.frx":0442
      TabIndex        =   0
      Top             =   120
      Width           =   3015
   End
End
Attribute VB_Name = "FCardView"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

