
// testMfcDoc.cpp : implementation of the CtestMfcDoc class
//

#include "stdafx.h"
#include "testMfc.h"

#include "testMfcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMfcDoc

IMPLEMENT_DYNCREATE(CtestMfcDoc, CDocument)

BEGIN_MESSAGE_MAP(CtestMfcDoc, CDocument)
END_MESSAGE_MAP()


// CtestMfcDoc construction/destruction

CtestMfcDoc::CtestMfcDoc()
{
	// TODO: add one-time construction code here

}

CtestMfcDoc::~CtestMfcDoc()
{
}

BOOL CtestMfcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CtestMfcDoc serialization

void CtestMfcDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CtestMfcDoc diagnostics

#ifdef _DEBUG
void CtestMfcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtestMfcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtestMfcDoc commands
