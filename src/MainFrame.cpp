#include"MainFrame.h"
#include<wx/wx.h>
#include<fstream>

enum IDS
{
    ID_SAVE = 2
};

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxTextCtrl* textCTRL = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 20), wxSize(-1, -1), wxTE_MULTILINE | wxHSCROLL);
    wxPanel* sidePanel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(20,-1));

    wxFont font(12, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Consolas");
    textCTRL->SetFont(font);
    
    wxBoxSizer* horizontal = new wxBoxSizer(wxHORIZONTAL);
    horizontal->Add(sidePanel, 0, wxEXPAND);
    horizontal->Add(textCTRL, 1, wxEXPAND);

    this->SetSizerAndFit(horizontal);
    
    wxMenu* MenuFile = new wxMenu;
    MenuFile->Append(wxID_ANY, "&New File...\tCtrl+N");
    MenuFile->Append(wxID_ANY, "&Open...\tCtrl+O");
    MenuFile->Append(ID_SAVE, "&Save...\tCtrl+S");
    MenuFile->Append(wxID_ANY, "&Save As...\tCtrl+Shift+S");

    wxMenu* MenuEdit = new wxMenu;
    MenuEdit->Append(wxID_ANY, "&Undo");
    MenuEdit->Append(wxID_ANY, "&Redo");

    MenuEdit->AppendSeparator();

    MenuEdit->Append(wxID_ANY, "&Cut\tCtrl+X");
    MenuEdit->Append(wxID_ANY, "&Copy\tCtrl+C");
    MenuEdit->Append(wxID_ANY, "&Paste\tCtrl+V");

    wxMenuBar* MenuBar = new wxMenuBar;

    MenuBar->Append(MenuFile, "&File");
    MenuBar->Append(MenuEdit, "&Edit");
    
    SetMenuBar(MenuBar);
    

    Bind(wxEVT_MENU, [this, textCTRL](wxCommandEvent& event) 
    {
        Save(textCTRL);
    }, ID_SAVE);

};

void MainFrame::Save(wxTextCtrl* TextBox)
{
    wxString text = TextBox->GetValue();

    std::ofstream OutFile("SaveFile.txt");

    if (OutFile.is_open()) 
    {
        OutFile << text;
        OutFile.close();
    }
}