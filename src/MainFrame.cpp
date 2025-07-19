#include"MainFrame.h"
#include<wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(-1, 20));
    wxTextCtrl* textCTRL = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 20), wxSize(-1, -1), wxTE_MULTILINE | wxHSCROLL);
    wxPanel* sidePanel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(20,-1));

    wxFont font(12, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Consolas");
    textCTRL->SetFont(font);
    
    panel->SetBackgroundColour(wxColor(255, 186, 206));
    
    wxBoxSizer* vertical = new wxBoxSizer(wxVERTICAL);
    vertical->Add(panel, 0, wxEXPAND);

    wxBoxSizer* horizontal = new wxBoxSizer(wxHORIZONTAL);
    horizontal->Add(sidePanel, 0, wxEXPAND);
    horizontal->Add(textCTRL, 1, wxEXPAND);

    vertical->Add(horizontal, 1, wxEXPAND);

    this->SetSizerAndFit(vertical);


};
