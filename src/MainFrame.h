#pragma once
#include<wx/wx.h>
#include<filesystem>
#include<fstream>
#include<algorithm>

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);
    private:
        wxString FilePath;
        
        wxString SaveAs(wxTextCtrl* TextBox);
        void Save(wxTextCtrl* TextBox, wxString FilePath);
};