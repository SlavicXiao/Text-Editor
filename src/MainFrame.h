#pragma once
#include<wx/wx.h>
#include<fstream>
#include<iostream>

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);
    private:
        wxString FilePath;
        
        wxString SaveAs(wxTextCtrl* TextBox);
        void Save(wxTextCtrl* TextBox, wxString FilePath);
        wxString Open(wxTextCtrl* Textbox);
};