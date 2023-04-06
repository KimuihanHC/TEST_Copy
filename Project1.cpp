//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEUNIT("CL.cpp");
USEFORM("MainForm.cpp", MainFrm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainFrm), &MainFrm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
