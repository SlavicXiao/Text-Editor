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
        void Save(wxTextCtrl* TextBox);
};