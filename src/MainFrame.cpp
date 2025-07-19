#include"MainFrame.h"
#include<wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxTextCtrl* textCTRL = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(0, 20), wxSize(800, 600), wxTE_MULTILINE | wxHSCROLL);
};
