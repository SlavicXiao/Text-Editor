#include"MainFrame.h"
#include<wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxTextCtrl* textCTRL = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 350), wxSize(300, -1));
};
