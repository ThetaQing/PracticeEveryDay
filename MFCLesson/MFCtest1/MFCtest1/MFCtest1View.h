
// MFCtest1View.h : CMFCtest1View ��Ľӿ�
//

#pragma once


class CMFCtest1View : public CView
{
protected: // �������л�����
	CMFCtest1View();
	DECLARE_DYNCREATE(CMFCtest1View)

// ����
public:
	CMFCtest1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCtest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCtest1View.cpp �еĵ��԰汾
inline CMFCtest1Doc* CMFCtest1View::GetDocument() const
   { return reinterpret_cast<CMFCtest1Doc*>(m_pDocument); }
#endif

