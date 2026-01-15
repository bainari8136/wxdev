#include <wx/wx.h>
#include "ui/Frame.h"

class MyApp : public wxApp {
public:
    bool OnInit() override {
        MyFrame* frame = new MyFrame("OpenSSL Demo");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
