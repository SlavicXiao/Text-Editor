#include"MainFrame.h"
#include<wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this); 
    wxButton* button = new wxButton(panel, wxID_ANY, "My funny button", wxPoint(50,50), wxSize(100,50));
};
