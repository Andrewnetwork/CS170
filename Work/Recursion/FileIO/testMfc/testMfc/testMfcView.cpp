
// testMfcView.cpp : implementation of the CtestMfcView class
//

#include "stdafx.h"
#include "testMfc.h"

#include "testMfcDoc.h"
#include "testMfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMfcView

IMPLEMENT_DYNCREATE(CtestMfcView, CView)

BEGIN_MESSAGE_MAP(CtestMfcView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CtestMfcView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtestMfcView construction/destruction

CtestMfcView::CtestMfcView()
{
	// TODO: add construction code here

}

CtestMfcView::~CtestMfcView()
{
}

BOOL CtestMfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CtestMfcView drawing

void CtestMfcView::OnDraw(CDC* /*pDC*/)
{
	CtestMfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CtestMfcView printing


void CtestMfcView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CtestMfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CtestMfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CtestMfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CtestMfcView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CtestMfcView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CtestMfcView diagnostics

#ifdef _DEBUG
void CtestMfcView::AssertValid() const
{
	CView::AssertValid();
}

void CtestMfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestMfcDoc* CtestMfcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestMfcDoc)));
	return (CtestMfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestMfcView message handlers
