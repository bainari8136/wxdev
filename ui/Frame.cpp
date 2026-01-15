#include "Frame.h"

MyFrame::MyFrame(const wxString &title):wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
        wxNotebook *notebook=new wxNotebook(this,wxID_ANY);


       VersionPanel *versionPanel=new VersionPanel(notebook);
       notebook->AddPage(versionPanel,"Openssl Version");

       wxBoxSizer *rootSizer=new wxBoxSizer(wxVERTICAL);
       rootSizer->Add(notebook,1,wxEXPAND|wxALL,5);
       this->SetSizer(rootSizer);
       versionPanel->button->Bind(wxEVT_BUTTON,&MyFrame::OnButtonClicked,this);
}

void MyFrame::OnButtonClicked(wxCommandEvent &event)
{
     OpensslThread* thread = new OpensslThread(this);
            if (thread->Create() != wxTHREAD_NO_ERROR) {
                wxLogError("Could not create the thread!");
                delete thread;
                return;
            }
            thread->Run();
}

OpensslThread::OpensslThread(wxFrame *frame):wxThread(wxTHREAD_DETACHED),frame_(frame)
{
}

wxThread::ExitCode OpensslThread::Entry()
{
    SSLVersion sslversion;
    wxString result = wxString::Format("OpenSSL Version: %s", sslversion.GetVersion());
    frame_->CallAfter([this,result](){

            wxStaticText *label=dynamic_cast<wxStaticText*>(frame_->FindWindowByName("version_label"));

            if(label){

                label->SetLabel(result);

            }
        });
    return (wxThread::ExitCode)0;
}

VersionPanel::VersionPanel(wxWindow*parent,wxWindowID id):wxPanel(parent,id)
{
    wxBoxSizer *sizer=new wxBoxSizer(wxVERTICAL);

        label_=new wxStaticText(
            this,wxID_ANY,"click the button to check openssl version",
            wxDefaultPosition,
            wxDefaultSize,wxALIGN_CENTER
         );
        label_->SetName("version_label");

        button=new wxButton(
            this,wxID_ANY,"Check Openssl version"
        );
        sizer->Add(label_,1,wxEXPAND|wxALL,10);
        sizer->Add(button,0,wxALIGN_CENTER|wxALL,10);
        this->SetSizer(sizer);
}
