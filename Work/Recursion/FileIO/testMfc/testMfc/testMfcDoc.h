
// testMfcDoc.h : interface of the CtestMfcDoc class
//


#pragma once


class CtestMfcDoc : public CDocument
{
protected: // create from serialization only
	CtestMfcDoc();
	DECLARE_DYNCREATE(CtestMfcDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CtestMfcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


