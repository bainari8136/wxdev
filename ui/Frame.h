#include <wx/wx.h>
#include <wx/notebook.h>
#include "../app/SSLVersion.h"
class MyFrame : public wxFrame {
    public:
    MyFrame(const wxString& title);

    private:
    void OnButtonClicked(wxCommandEvent& event);

};

class VersionPanel : public wxPanel {
    public:
    VersionPanel(wxWindow *parent,wxWindowID=wxID_ANY);
    wxStaticText *label_;
    wxButton *button;
};

class OpensslThread:public wxThread{
    public:
    explicit OpensslThread(wxFrame* frame);
     wxFrame *frame_;

    protected:
    virtual ExitCode Entry() override;
};