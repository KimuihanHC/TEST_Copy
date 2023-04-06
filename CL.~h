//---------------------------------------------------------------------------

#ifndef CLH
#define CLH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------

class CL : public TThread
{
public:
    int idx;
    TServerSocket* sock;    
private:
protected:
        void __fastcall Execute();
public:
    __fastcall CL(  bool CreateSuspended,
                        int nId,
                        AnsiString strAdd,
                        int nPort);
    __fastcall ~CL(void);                        
    AnsiString preStr;
    AnsiString strRecvText;
    void __fastcall ChildConnect(void);
    void __fastcall ChildDisconnect(void);

    bool __fastcall IsConnectionOk(void);

    TStringList* sList;

    void __fastcall onClientConnected(TObject *Sender, TCustomWinSocket *Socket);
    void __fastcall onClientDisconnected(TObject *Sender, TCustomWinSocket *Socket);
    void __fastcall onClientError(TObject *Sender,
                    TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode);
    void __fastcall onClientRead(TObject *Sender, TCustomWinSocket *Socket);
};
//---------------------------------------------------------------------------
#endif
