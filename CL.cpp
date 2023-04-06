//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CL.h"
#include "MainForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Unit2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall CL::CL(bool CreateSuspended, int nId, AnsiString strAdd, int nPort)
        : TThread(CreateSuspended)
{
    sList = new TStringList();

    sock = new TServerSocket(MainFrm);
    sock->Port = nPort;
    idx = nId;

    sock->OnClientConnect       = onClientConnected;
    sock->OnClientDisconnect    = onClientDisconnected;
    sock->OnClientError         = onClientError;
    sock->OnClientRead          = onClientRead;

    AnsiString  str =   "[ChildConnect#" + IntToStr( idx + 1) +
                        "] Create. Sock Port " + IntToStr( sock->Port);
    sList->Add(str);

    ChildConnect();
}
__fastcall CL::~CL(void)
{
    try {
        if(this->Handle == NULL)
            return;
        if (sock != NULL) {
            sock->Active = false;
            delete sock;
        }
        sock = NULL;
        delete sList;
    } catch(...) {}
}
//---------------------------------------------------------------------------
void __fastcall CL::Execute()
{
  //---- Place thread code here ----
   while (!Terminated)
   {
        WaitForSingleObject((void *)this->Handle, 1);

        try {
            if(this->Handle == NULL) return;
            if(sock == NULL) return;
        } catch(...) {
            return;
        }

        if (sock->Active)
        {
        }
        else
        {
            try {
                //sock->Close();
                //sock->Active = true;
            } catch(...) {}
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall CL::ChildConnect(void)
{
  AnsiString str;
    try {
        if(this->Handle == NULL) return;
        if(sock == NULL) return;
        if(!sock->Active) {
           str ="[ChildConnect#" + IntToStr( idx + 1) +
                "] sock Active.";
           sList->Add(str);
           sock->Active = true;
        }
    } catch(...) {
    }
}
//---------------------------------------------------------------------------
void __fastcall CL::ChildDisconnect(void)
{
    try
    {
        if(this->Handle == NULL) return;
        if(sock == NULL) return;

        if (sock->Active)
            sock->Active = false;
    }
    catch(...)
    {
    }
}

bool __fastcall CL::IsConnectionOk(void)
{
    try {
        if(this->Handle == NULL)
            return false;
    } catch(...) {
        return false;
    }

    try {
        if(sock == NULL)
            return false;
    } catch(...) {
        if(sock != NULL)
            delete sock;
        sock = NULL;
        return false;
    }

    bool result;
    if (sock->Socket->ActiveConnections > 0)
        result = true;
    else
        result = false;

    return result;
}
void __fastcall CL::onClientConnected(TObject *Sender, TCustomWinSocket *Socket)
{
  sList->Add("Connect");
}
//---------------------------------------------------------------------------
void __fastcall CL::onClientDisconnected(TObject *Sender, TCustomWinSocket *Socket)
{
  sList->Add("Disconnect");
}
//---------------------------------------------------------------------------
void __fastcall CL::onClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
  sList->Add("Error");

}

void __fastcall CL::onClientRead(TObject *Sender, TCustomWinSocket *Socket) // child로부터 data receive시
{
  if(this->Handle == NULL) return;
  if(sock == NULL) return;

  if ( !IsConnectionOk())
  {
    ChildDisconnect();
    return;
  }

  if (!sock->Active)
    return;
  AnsiString receiveStr = Socket->ReceiveText();
  if (receiveStr == "")
    return;
  preStr = receiveStr;
  while (1)
  {
    int pos = (preStr.Pos("\n")); // "\n"으로 끝 체크

    if (pos <= 0)
      break;
    AnsiString readStr = preStr.SubString(1, pos-1);
    readStr = readStr.Trim();
    preStr = preStr.SubString(pos+1, receiveStr.Length() - pos);
    sList->Add(readStr);
    
  }
  Socket->SendText(MainFrm->edt_SendData->Text);
}
