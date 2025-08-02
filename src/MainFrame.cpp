#include"MainFrame.h"
#include<wx/wx.h>
#include<fstream>
#include<iostream>

enum IDS
{
    ID_SAVE = 1,
    ID_SAVE_AS = 2,
    ID_OPEN = 3,
    ID_NEW_FILE = 4
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
    MenuFile->Append(ID_NEW_FILE, "&New File...\tCtrl+N");
    MenuFile->Append(ID_OPEN, "&Open...\tCtrl+O");
    MenuFile->Append(ID_SAVE, "&Save...\tCtrl+S");
    MenuFile->Append(ID_SAVE_AS, "&Save As...\tCtrl+Shift+S");

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
        if(FilePath == "")
        {
            FilePath = SaveAs(textCTRL);
        }

        else
        {
            Save(textCTRL, FilePath);
        }

    }, ID_SAVE);

    Bind(wxEVT_MENU, [this, textCTRL](wxCommandEvent& event) 
    {
        FilePath = SaveAs(textCTRL);
    },ID_SAVE_AS);

    Bind(wxEVT_MENU, [this, textCTRL](wxCommandEvent& event)
    {
        FilePath = Open(textCTRL);
    },ID_OPEN);

    Bind(wxEVT_MENU, [this, textCTRL](wxCommandEvent& event)
    {
        FilePath = "";
        textCTRL->SetValue(wxEmptyString);
    },ID_NEW_FILE);

};

wxString MainFrame::SaveAs(wxTextCtrl* TextBox)
{
    wxFileDialog* SaveFileDialog = new wxFileDialog(this, _("Save File"), "", "", "Text Files: (*.txt)|*.txt|All files (*.*)|*.*", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    wxString FilePath;
    
    if(SaveFileDialog->ShowModal() != wxID_CANCEL)
    {
        FilePath = SaveFileDialog->GetPath();
        MainFrame::Save(TextBox, FilePath);
    }

    else 
    {
        FilePath = "";
    }

    return FilePath;
}

void MainFrame::Save(wxTextCtrl* TextBox, wxString FilePath)
{
    wxString text = TextBox->GetValue();

    std::ofstream OutFile(FilePath.ToStdString());

    if (OutFile.is_open()) 
    {
        OutFile << text;
        OutFile.close();
    }
}

wxString MainFrame::Open(wxTextCtrl* TextBox)
{
    wxFileDialog* OpenFileDialog = new wxFileDialog(this, _("Choose a file to open"), wxEmptyString, wxEmptyString, 
    _("Text files (*.txt)|*.txt|All files (*.*)|*.*"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    wxString FilePath;
    if(OpenFileDialog->ShowModal() != wxID_CANCEL)
    {
        FilePath = OpenFileDialog->GetPath();
        std::ifstream File(FilePath.ToStdString());
        std::string line;
        std::string text;

        if(File.is_open())
        {
            while(File.good())
            {
                getline(File, line);
                text += line + "\n";
            }
            TextBox->SetValue(text);
            File.close();
        }
    }

    else 
    {
        FilePath = "";
    }

    return FilePath;

}