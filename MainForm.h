//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include "XGemPro3Lib_OCX.h"
#include <OleCtrls.hpp>
#include <ScktComp.hpp>
#include <Buttons.hpp>

#include "define.h"
#include <ExtCtrls.hpp>
#include "CL.h"
#include <Grids.hpp>
#include "lmdstdcA.hpp"

struct tCl{
  bool bUse;
  int nPort;
  char cIP[32];
};
struct tCl_State{
  bool isAlloc;
};

//---------------------------------------------------------------------------
class TMainFrm : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TListBox *lboxLog0;
        TTimer *Timer1;
        TStringGrid *GridReport;
        TEdit *edt_SendData;
        TButton *etn_REQUEST_LINK_TEST;
        TServerSocket *ServerSocket1;
        TClientSocket *ClientSocket;
        TButton *Button2;
        TButton *Button3;
        TButton *Button5;
        TLMDSpinEdit *edt_Port;
        TCheckBox *chk_NoReturn;
        TButton *btn_REQUEST_ALARM_LIST;
        TButton *btn_REQUEST_UNITID_READ;
        TButton *btn_REQUEST_SET_DATETIME;
        TButton *btn_REQUEST_TERMINAL_MESSAGE;
        TStringGrid *GridRequest;
        TStringGrid *GridReply;
        TEdit *edt_LOTID;
        TEdit *edt_APPLICATION;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *edt_transactionId;
        TLabel *Label3;
        TEdit *edt_EQUIPMENTID;
        TLabel *Label4;
        TEdit *edt_IPADDRESS;
        TLabel *Label5;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall lboxLog0Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ClientSocketConnecting(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocketDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocketError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall ClientSocketLookup(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocketRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocketWrite(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocketConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall etn_REQUEST_LINK_TESTClick(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall btn_REQUEST_ALARM_LISTClick(TObject *Sender);
        void __fastcall btn_REQUEST_UNITID_READClick(TObject *Sender);
        void __fastcall btn_REQUEST_SET_DATETIMEClick(TObject *Sender);
        void __fastcall btn_REQUEST_TERMINAL_MESSAGEClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainFrm(TComponent* Owner);
        TListBox* pLog[C_M];
        tCl clcfg[C_M];
        tCl_State cl_St[C_M];
        __fastcall ConnectTo();
        __fastcall DisconnectTo();
        __fastcall ClientConnectTo();
        __fastcall ClientDisconnectTo();

        void GridMassageShow(TStringGrid *grid, AnsiString str);
        void GridMassageClear(TStringGrid *grid);

        void Set_REPORT_ONLINE_STATE(AnsiString str);
        void Set_REPORT_USER_CHANGE(AnsiString str);
        void Set_REPORT_ALARM_STATE(AnsiString str);
        void Set_REPLY_LINK_TEST(AnsiString str);
        void Set_REPLY_ALARM_LIST(AnsiString str);
        void Set_REPLY_SET_DATETIME(AnsiString str);
        void Set_REPLY_TERMINAL_MESSAGE(AnsiString str);
        void Set_REPLY_UNITID_READ(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
extern tCl clcfg;
//---------------------------------------------------------------------------
#endif
