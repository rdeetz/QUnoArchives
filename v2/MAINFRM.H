//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  mainfrm.h
// Description:  definition of the main window class CMainFrame
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

//////////////////////////////////////////////////////////////////////////
// CMainFrame 
//   the main window class

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CMainFrame)

public:
	// attributes
    CRect m_rectDeck;
	CRect m_rectStack;
	CRect m_rectRoger;
	CRect m_rectCards[10];
    
protected:
    // overrides
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    
public:          
	// construction and destruction
	CMainFrame();
	virtual ~CMainFrame();

	// diagnostics
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// message map functions
	//{{AFX_MSG(CMainFrame)
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnGameDraw();
	afx_msg void OnGameForce();
	afx_msg void OnUpdateGameDraw(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameForce(CCmdUI* pCmdUI);
	afx_msg void OnGameNew();
	afx_msg void OnGameOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
private:
	void BlastBitmap(CRect rect, UINT img);
};
//////////////////////////////////////////////////////////////////////////
