#ifndef _MERRY_LIST_BOX_PANEL_H_
#define _MERRY_LIST_BOX_PANEL_H_

#include "MerryCommandManager.h"
#include "MerryConfig.h"

#ifdef __WXMSW__
#include <wx/dcbuffer.h>
typedef wxBufferedPaintDC MerryPaintDC;
#else
typedef wxPaintDC MerryPaintDC;
#endif

class MerryListBoxPanel : public wxPanel
{
public:
	MerryListBoxPanel(wxWindow* parent);

	void SetCommandArray(const MerryCommandArray& commands);
	void SelectNext();
	void SelectPrev();
	const MerryCommand* GetSelectionCommand() const;

	bool IsPopup() const;
	void Popup();
	void Dismiss();

private:
	void OnMouseEvent(wxMouseEvent& e);
	void OnPaintEvent(wxPaintEvent& e);

private:
	void DrawBorder(MerryPaintDC& dc) const;
	void DrawBackground(MerryPaintDC& dc) const;
	void DrawItems(MerryPaintDC& dc) const;

	void SetHeight(int height);
	int CalcHeight() const;
	void SetSelection(int index);
	void SetSelection(const wxPoint& pos);
	int GetVisibleItemNum() const;

private:
	MerryCommandArray m_commands;
	int m_topCommandIndex;
	int m_selectionCommandIndex;

	struct ListBoxItem
	{
		wxRect rect;
		wxRect mainRect;
		wxRect subRect;
	};
	ListBoxItem m_items[MERRY_DEFAULT_LIST_BOX_ITEM_MAX_NUM];
	wxBitmap m_selectionItemBackground;

	bool m_isPopup;

private:
	DECLARE_EVENT_TABLE()
};

#endif
