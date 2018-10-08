//////////////////////////////////////////////////////////////////////////
// QUno
// Roger Deetz, 1997
//
// mainfrm.h - definition of the main window class CMainFrame

//////////////////////////////////////////////////////////////////////////
// CMainFrame 
//   the main window class

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CMainFrame)

	// attributes
public:
    CRect m_rectStack;
	CRect m_rectCards[10];
    
    // overrides
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    
	// implementation
public:          
	// construction and destruction
	CMainFrame();
	virtual ~CMainFrame();

	// diagnostics
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNewGame();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
private:
	void UpdateStack();
};
//////////////////////////////////////////////////////////////////////////
