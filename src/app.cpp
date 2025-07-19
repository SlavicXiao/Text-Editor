#include<wx/wx.h>
#include"MainFrame.h"
#include"app.h"

bool App::OnInit()
{
    MainFrame* mainframe = new MainFrame("Text Editor");
    mainframe->SetClientSize(800,600);
    mainframe->Center();
    mainframe->Show();
    return true;
}

wxIMPLEMENT_APP(App);