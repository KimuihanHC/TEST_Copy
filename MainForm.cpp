//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "CL.h"
#include "define.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "XGemPro3Lib_OCX"
#pragma link "lmdstdcA"
#pragma resource "*.dfm"
TMainFrm *MainFrm;

CL* C[C_M];
tCl clcfg;
//---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner)
        : TForm(Owner)
{
  for (int  i = 0; i< C_M; i++) {
    C[i] = NULL;
  }
  ClientSocket = NULL;
}
//---------------------------------------------------------------------------

__fastcall TMainFrm::ClientConnectTo()
{
    AnsiString str;
    if(ClientSocket == NULL){
        ClientSocket = new TClientSocket(MainFrm);
    }
    ClientSocket->Port = edt_Port->Value;
    ClientSocket->Address = "127.0.0.1";
    ClientSocket->Active = true;

    str = "ClientConnectTo";
    lboxLog0->Items->Add(str);
}
__fastcall TMainFrm::ClientDisconnectTo()
{
  AnsiString str;

  if (ClientSocket != NULL) {
    ClientSocket->Active = false;
    delete ClientSocket;
    ClientSocket = NULL;
    str = "ClientDisconnectTo";
    lboxLog0->Items->Add(str);
  }
}
__fastcall TMainFrm::ConnectTo()
{
  for (int nIndex = 0 ; nIndex < C_M ; nIndex++)
    if (clcfg[nIndex].bUse) {
      if(C[nIndex] == NULL){
        C[nIndex] = new CL(false, nIndex, clcfg[nIndex].cIP, clcfg[nIndex].nPort);
        C[nIndex]->Resume();
        cl_St[nIndex].isAlloc = true;
      }
    }
}

__fastcall TMainFrm::DisconnectTo()
{
  for (int nIndex = 0 ; nIndex < C_M ; nIndex++){
    if(C[nIndex] != NULL && cl_St[nIndex].isAlloc )
    {
      C[nIndex]->ChildDisconnect();
      C[nIndex]->Terminate();
      C[nIndex]->WaitFor();
      delete C[nIndex];
      C[nIndex] = NULL;
      cl_St[nIndex].isAlloc = false;
    }
  }
}

void __fastcall TMainFrm::FormShow(TObject *Sender)
{
  //LPCSTR str = "1123";
  const char * str = "1123";
  AnsiString a = AnsiString (str);
  WideString b = WideString (str);

  //ConnectTo();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::FormDestroy(TObject *Sender)
{
  DisconnectTo();
}
//---------------------------------------------------------------------------


void __fastcall TMainFrm::lboxLog0Click(TObject *Sender)
{
  if (C[0] != NULL) {
    C[0]->sList->Clear();
  }
  lboxLog0->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::Timer1Timer(TObject *Sender)
{
  int nCnt;
  char cStx = 0x02, cEtx = 0x03;
    int nStart, nEnd;
  static AnsiString strAfterText = "";
  AnsiString strBeforeText = "";
  if (C[0] != NULL) {
    nCnt = C[0]->sList->Count;
    for (int nIndex = lboxLog0->Items->Count ; nIndex < nCnt ; nIndex++){
        lboxLog0->Items->Insert(nIndex, C[0]->sList->Strings[nIndex]);
        AnsiString str = C[0]->sList->Strings[nIndex];
    }
  }

  if (ClientSocket != NULL) {
    AnsiString str = ClientSocket->Socket->ReceiveText();
    str = strAfterText + str;
    int size = str.Length();
      if (str.Pos(cEtx)> 0){
          nStart = str.Pos(cEtx);
          nEnd   = str.Length() - nStart;
          strAfterText  = str.SubString(nStart+1, nEnd+1);
          strBeforeText = str.SubString(1, nStart);
      } else {
          nStart = 0;
          nEnd   = str.Length();
          strAfterText = str.SubString(nStart+1, nEnd+1);
      }
    while (size) {
      if (strBeforeText != "") {
        if (!chk_NoReturn->Checked) {
          Set_REPORT_ONLINE_STATE(strBeforeText);
          Set_REPORT_USER_CHANGE(strBeforeText);
          Set_REPORT_ALARM_STATE(strBeforeText);
          Set_REPLY_LINK_TEST(strBeforeText);
          Set_REPLY_ALARM_LIST(strBeforeText);
          Set_REPLY_SET_DATETIME(strBeforeText);
          Set_REPLY_TERMINAL_MESSAGE(strBeforeText);
          Set_REPLY_UNITID_READ(strBeforeText);
          if (strBeforeText.Pos("REPORT_EQUIPMENT_STATE")> 0){
            strBeforeText = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_EQUIPMENT_STATE_DISPLAY</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n<body>\r\n<EQUIPMENTID></EQUIPMENTID>\r\n<IPADDRESS></IPADDRESS>\r\n<APPLICATIONID></APPLICATIONID>\r\n</body>\r\n<return>\r\n<returnCode></returnCode>\r\n<IPADDRESS></IPADDRESS>\r\n</return>\r\n</message>" + AnsiString(cEtx);
            ClientSocket->Socket->SendText(strBeforeText);
            lboxLog0->Items->Add(strBeforeText);
          }
          if (strBeforeText.Pos("REPORT_LOSS_STATE")> 0){
            strBeforeText = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_LOSS_WINDOW</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n<body>\r\n<EQUIPMENTID></EQUIPMENTID>\r\n<IPADDRESS></IPADDRESS>\r\n<APPLICATIONID></APPLICATIONID>\r\n</body>\r\n<return>\r\n<returnCode></returnCode>\r\n<IPADDRESS></IPADDRESS>\r\n</return>\r\n</message>" + AnsiString(cEtx);
            ClientSocket->Socket->SendText(strBeforeText);
            lboxLog0->Items->Add(strBeforeText);
          }

        }
      }
      str = strAfterText;
      if (str.Pos(cEtx)> 0){
          nStart = str.Pos(cEtx);
          nEnd   = str.Length() - nStart;
          strAfterText  = str.SubString(nStart+1, nEnd+1);
          strBeforeText = str.SubString(1, nStart);
      } else {
          nStart = 0;
          nEnd   = str.Length();
          strAfterText = str.SubString(nStart+1, nEnd+1);
          break;
      }
    }

  }

}
//---------------------------------------------------------------------------
void TMainFrm::Set_REPORT_ONLINE_STATE(AnsiString str){
  if (str.Pos("REPORT_ONLINE_STATE")> 0){
    GridMassageClear(GridReport);
    GridMassageShow(GridReport,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPORT_USER_CHANGE(AnsiString str){
  char cStx = 0x02, cEtx = 0x03;
  if (str.Pos("REPORT_USER_CHANGE")> 0){
    GridMassageClear(GridReport);
    GridMassageClear(GridRequest);
    GridMassageShow(GridReport,str);
    str = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_USER_COMMAND</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n<body>\r\n<EQUIPMENTID>TEST1</EQUIPMENTID>\r\n<IPADDRESS>192.168.0.1</IPADDRESS>\r\n<APPLICATIONID>APPLICATIONID_TEST</APPLICATIONID>\r\n</body>\r\n<return>\r\n<returnCode>0</returnCode>\r\n<returnMessage>none</returnMessage>\r\n</return>\r\n</message>" + AnsiString(cEtx);
    ClientSocket->Socket->SendText(str);
    lboxLog0->Items->Add(str);
    GridMassageShow(GridRequest, str);
  } else if (str.Pos("REPLY_USER_COMMAND")> 0){
    GridMassageClear(GridReply);
    GridMassageShow(GridReply,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPORT_ALARM_STATE(AnsiString str){
  char cStx = 0x02, cEtx = 0x03;
  if (str.Pos("REPORT_ALARM_STATE")> 0){
    GridMassageClear(GridReport);
    GridMassageShow(GridReport,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPLY_LINK_TEST(AnsiString str){
  if (str.Pos("REPLY_LINK_TEST")> 0){
    GridMassageClear(GridReply);
    GridMassageShow(GridReply,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPLY_ALARM_LIST(AnsiString str){
  if (str.Pos("REPLY_ALARM_LIST")> 0){
    GridMassageClear(GridReply);
    GridMassageShow(GridReply,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPLY_SET_DATETIME(AnsiString str){
  if (str.Pos("REPLY_SET_DATETIME")> 0){
    GridMassageClear(GridReply);
    GridMassageShow(GridReply,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPLY_TERMINAL_MESSAGE(AnsiString str){
  if (str.Pos("REPLY_TERMINAL_MESSAGE")> 0){
    GridMassageClear(GridReply);
    GridMassageShow(GridReply,str);
    lboxLog0->Items->Add(str);
  }
}

void TMainFrm::Set_REPLY_UNITID_READ(AnsiString str){
  if (str.Pos("REPLY_UNITID_READ")> 0){
    GridMassageClear(GridReply);
    GridMassageShow(GridReply,str);
    lboxLog0->Items->Add(str);
  }
}

void __fastcall TMainFrm::BitBtn1Click(TObject *Sender)
{
  //ConnectTo();
}
//---------------------------------------------------------------------------

void TMainFrm::GridMassageClear(TStringGrid *grid) {
  for (int i = 0; i < grid->RowCount; i++){
    grid->Cells[0][i] = "";
  }
}
void TMainFrm::GridMassageShow(TStringGrid *grid, AnsiString str){
  AnsiString Test;
  AnsiString strSpace = "";
  int length = str.Length();
  int cnt = 0;
  int start_found = 0;
  int end_found   = str.Pos(("\n</"));
  for (int index = 0; index < length; )
  {
    int index_found = str.Pos(("\n"));

    if (index_found == 0)
    {
      index_found = length;
      break;
    }
    if (index_found > 0)
    {
      AnsiString strSubPath = str.SubString(1, (index_found - 1));
      int test = strSubPath.Pos(("</"));
      if (test > 0) {
        start_found--;
        strSpace = "";
        for (int i = 0; i < start_found;i++){
          strSpace += " ";
        }
      }

      str = str.SubString((index_found + 1), (length - index));
      AnsiString text = strSubPath;
      grid->Cells[0][cnt] = strSpace + text;
      cnt++;
      grid->RowCount = cnt;

      if ((test == 0)){
        strSpace = "";
        for (int i = 0; i < start_found;i++){
          strSpace += " ";
        }
        start_found++;
      }
    }
    index = index_found +2;
  }
} 

void __fastcall TMainFrm::Button2Click(TObject *Sender)
{
    ClientConnectTo();
}
//---------------------------------------------------------------------------



void __fastcall TMainFrm::ClientSocketConnecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
   //
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ClientSocketDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
   //
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ClientSocketError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    AnsiString str = "Error (" + IntToStr(ErrorCode) + ")" ;
    lboxLog0->Items->Add(str);
    ClientDisconnectTo();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ClientSocketLookup(TObject *Sender,
      TCustomWinSocket *Socket)
{
   //
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
   AnsiString str = "ClientSocketRead";
   AnsiString receiveStr = Socket->ReceiveText();
   lboxLog0->Items->Add(receiveStr);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ClientSocketWrite(TObject *Sender,
      TCustomWinSocket *Socket)
{
   //
   AnsiString str = "ClientSocketWrite";
   lboxLog0->Items->Add(str);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ClientSocketConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
   //
   AnsiString str = "ClientSocketConnect";
   lboxLog0->Items->Add(str);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::Button3Click(TObject *Sender)
{
  ClientDisconnectTo();
}
//---------------------------------------------------------------------------


void __fastcall TMainFrm::etn_REQUEST_LINK_TESTClick(TObject *Sender)
{
  char cStx = 0x02, cEtx = 0x03;
  GridMassageClear(GridRequest);
  AnsiString strHeader = "<header>\r\n<messageName>REQUEST_LINK_TEST</messageName>\r\n<transactionId>" + edt_transactionId->Text + "</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>";
  AnsiString strbody =  "<body>\r\n<EQUIPMENTID>" + edt_EQUIPMENTID->Text +
                        "</EQUIPMENTID>\r\n<IPADDRESS>" + edt_IPADDRESS->Text +
                        "</IPADDRESS>\r\n<APPLICATIONID>" + edt_APPLICATION->Text +
                        "</APPLICATIONID>\r\n</body>";
  AnsiString str = AnsiString(cStx)+ "<message>\r\n" + strHeader + "\r\n" + strbody + "\r\n</message>" + AnsiString(cEtx);
  ClientSocket->Socket->SendText(str);
  lboxLog0->Items->Add("Send : " + str);
  GridMassageShow(GridRequest, str);

}
//---------------------------------------------------------------------------


void __fastcall TMainFrm::Button5Click(TObject *Sender)
{
  char cStx = 0x02, cEtx = 0x03;
  AnsiString str = AnsiString(cStx)+ edt_SendData->Text + AnsiString(cEtx);

  ClientSocket->Socket->SendText(str);
  lboxLog0->Items->Add("Send : " + str);
  GridMassageClear(GridRequest);
}
//---------------------------------------------------------------------------




void __fastcall TMainFrm::btn_REQUEST_ALARM_LISTClick(TObject *Sender)
{
  char cStx = 0x02, cEtx = 0x03;
  GridMassageClear(GridRequest);
  AnsiString str = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_ALARM_LIST</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n<body>\r\n<EQUIPMENTID>EES</EQUIPMENTID>\r\n<SUBEQPID>001</SUBEQPID>\r\n<IPADDRESS>192.168.0.1</IPADDRESS>\r\n</body>\r\n<return>\r\n<returnCode></returnCode>\r\n<IPADDRESS></IPADDRESS>\r\n</return>\r\n</message>" + AnsiString(cEtx);
  ClientSocket->Socket->SendText(str);
  lboxLog0->Items->Add("Send : " + str);
  GridMassageShow(GridRequest, str);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::btn_REQUEST_UNITID_READClick(TObject *Sender)
{
  char cStx = 0x02, cEtx = 0x03;
  GridMassageClear(GridRequest);
  AnsiString strMODULEIDLIST    = "<MODULEIDLIST>\r\n<M1>\r\n<MODULETYPE></MODULETYPE>\r\n<MODULEID></MODULEID>\r\n<MAINYN></MAINYN>\r\n</M1>\r\n</MODULEIDLIST>";
  AnsiString strSENSORIDLIST    = "<SENSORIDLIST>\r\n<S1>\r\n<SENSORTYPE></SENSORTYPE>\r\n<SENSORID></SENSORID>\r\n<MAINYN></MAINYN>\r\n</S1>\r\n</SENSORIDLIST>";
  AnsiString strSHEILDCANIDLIST = "<SHEILDCANIDLIST>\r\n<C1>\r\n<SHEILDCANTYPE></SHEILDCANTYPE>\r\n<SHEILDCANID></SHEILDCANID>\r\n<MAINYN></MAINYN>\r\n</C1>\r\n</SHEILDCANIDLIST>";
  AnsiString strPCBLIST         = "<PCBIDLIST>\r\n<C1>\r\n<PCBID></PCBID>\r\n<MAINYN></MAINYN>\r\n</C1>\r\n</PCBIDLIST>";  
  AnsiString strbody =  "<body>\r\n<EQUIPMENTID>EES</EQUIPMENTID>\r\n<IPADDRESS>192.168.0.1</IPADDRESS>\r\n<USERID>TEST_1</USERID>\r\n<PORTID>IP01</PORTID>\r\n<STEPID></STEPID>\r\n<LOTID>" + edt_LOTID->Text +
                        "</LOTID>\r\n<PRODUCTID></PRODUCTID>\r\n<CONSUNLIST></CONSUNLIST>\r\n" + strMODULEIDLIST +
                        "\r\n " + strSENSORIDLIST +
                        "\r\n" + strSHEILDCANIDLIST +
                        "\r\n" + strPCBLIST + "\r\n</body>";

  AnsiString str = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_UNITID_READ</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n" + strbody + "\r\n<return>\r\n<returnCode>1</returnCode>\r\n</return>\r\n</message>" + AnsiString(cEtx);
  ClientSocket->Socket->SendText(str);
  lboxLog0->Items->Add("Send : " + str);
  GridMassageShow(GridRequest, str);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::btn_REQUEST_SET_DATETIMEClick(TObject *Sender)
{
  char cStx = 0x02, cEtx = 0x03;
  GridMassageClear(GridRequest);
  AnsiString str = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_SET_DATETIME</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n<body>\r\n<EQUIPMENTID>EES</EQUIPMENTID>\r\n<SUBEQPID>001</SUBEQPID>\r\n<IPADDRESS>192.168.0.1</IPADDRESS>\r\n<DATETIME></DATETIME>\r\n</body>\r\n<return>\r\n<returnCode>1</returnCode>\r\n</return>\r\n</message>" + AnsiString(cEtx);
  ClientSocket->Socket->SendText(str);
  lboxLog0->Items->Add("Send : " + str);
  GridMassageShow(GridRequest, str);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::btn_REQUEST_TERMINAL_MESSAGEClick(TObject *Sender)
{
  char cStx = 0x02, cEtx = 0x03;
  GridMassageClear(GridRequest);
  AnsiString str = AnsiString(cStx)+"<message>\r\n<header>\r\n<messageName>REQUEST_TERMINAL_MESSAGE</messageName>\r\n<transactionId>ec4682e8-00ed-4bac</transactionId>\r\n<timeStamp>20221223151253</timeStamp>\r\n</header>\r\n<body>\r\n<EQUIPMENTID>EES</EQUIPMENTID>\r\n<SUBEQPID>001</SUBEQPID>\r\n<IPADDRESS>192.168.0.1</IPADDRESS>\r\n<TERMINALMESSAGE>TEST_MESSAGE</TERMINALMESSAGE>\r\n</body>\r\n</message>" + AnsiString(cEtx);
  ClientSocket->Socket->SendText(str);
  lboxLog0->Items->Add("Send : " + str);
  GridMassageShow(GridRequest, str);
}
//---------------------------------------------------------------------------


