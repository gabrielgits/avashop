//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitBuscaProduto.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormBuscaProduto *FormBuscaProduto;
//---------------------------------------------------------------------------
__fastcall TFormBuscaProduto::TFormBuscaProduto(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormBuscaProduto::StringGridBindSourceDB1SelectCell(TObject *Sender,
          const int ACol, const int ARow, bool &CanSelect)
{
  //	IdProduto = Column[0].Field->AsInteger;
  //	ShowMessage("coluna"+IntToStr(IdProduto));
}
//---------------------------------------------------------------------------






