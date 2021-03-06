#pragma once

#include "GdipButton.h"

#include "GdiImageDrawer.h"

#define BUTTON_CLOSE 1
#define BUTTON_CHEVRON 2
#define BUTTON_MINIMIZE 3
#define BUTTON_MAXIMIZE 4

class CDittoWindow
{
public:
	CDittoWindow(void);
	~CDittoWindow(void);

	void DoNcPaint(CWnd *pWnd);
	void DrawChevronBtn(CWindowDC &dc, CWnd *pWnd);
	void DrawCloseBtn(CWindowDC &dc, CWnd *pWnd);
	void DrawMaximizeBtn(CWindowDC &dc, CWnd *pWnd);
	void DrawMinimizeBtn(CWindowDC &dc);

	void DoCreate(CWnd *pWnd);
	void DoNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	UINT DoNcHitTest(CWnd *pWnd, CPoint point);
	void DoSetRegion(CWnd *pWnd);
	long DoNcLButtonUp(CWnd *pWnd, UINT nHitTest, CPoint point);
	void DoNcLButtonDown(CWnd *pWnd, UINT nHitTest, CPoint point);
	void DoNcMouseMove(CWnd *pWnd, UINT nHitTest, CPoint point) ;
	bool DoPreTranslateMessage(MSG* pMsg);
	void SetCaptionOn(CWnd *pWnd, int nPos, bool bOnstartup);
	bool SetCaptionColors(COLORREF left, COLORREF right);
	void SetCaptionTextColor(COLORREF color);

	long m_lTopBorder;
	long m_lRightBorder;
	long m_lBottomBorder;
	long m_lLeftBorder;

	bool m_bDrawClose;
	bool m_sendWMClose;
	bool m_bDrawChevron;
	bool m_bDrawMaximize;
	bool m_bDrawMinimize;

	CRect m_crCloseBT;
	CRect m_crChevronBT;
	CRect m_crMaximizeBT;
	CRect m_crMinimizeBT;

	CFont m_VertFont;
	CFont m_HorFont;

	bool m_bMinimized;

	bool m_bMouseDownOnChevron;
	bool m_bMouseOverChevron;
	bool m_bMouseDownOnClose;
	bool m_bMouseOverClose;
	bool m_bMouseDownOnCaption;
	bool m_bMouseDownOnMinimize;
	bool m_bMouseOverMinimize;
	bool m_bMouseDownOnMaximize;
	bool m_bMouseOverMaximize;

	COLORREF m_CaptionColorLeft;
	COLORREF m_CaptionColorRight;
	COLORREF m_CaptionTextColor;
	
	CGdiImageDrawer m_closeButton;
	CGdiImageDrawer m_chevronRightButton;
	CGdiImageDrawer m_chevronLeftButton;
	CGdiImageDrawer m_chevronTopButton;
	CGdiImageDrawer m_chevronBottomButton;
	CGdiImageDrawer m_maximizeButton;
};
