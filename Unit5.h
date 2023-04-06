//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H


  struct Test5
  {
    int nID;
    AnsiString strIP;
  };

  class Cls5
  {
    public:
      __fastcall Cls5();
      __fastcall ~Cls5(void);
      Test5 tstData[10];
      void Test_f();

  };
//---------------------------------------------------------------------------
#endif
 