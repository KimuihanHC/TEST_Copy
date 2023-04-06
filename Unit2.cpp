//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "CL.h"

__fastcall Cls::Cls(){
  //tstData[0].TestCL = new CL(true,0,"192.168.0.1",6000);

};
__fastcall Cls::~Cls(void){

};

void Cls::Test_f(){
  AnsiString strIP = "192.168.0.1";
  CL * t = NULL;
  t = new CL(true,0,strIP,6000);
  delete t;
};

//---------------------------------------------------------------------------

#pragma package(smart_init)
