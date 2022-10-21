//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitConsultarProduto.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormProcurarProdutos *FormProcurarProdutos;
//---------------------------------------------------------------------------
__fastcall TFormProcurarProdutos::TFormProcurarProdutos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormProcurarProdutos::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryProcurarProduto->Active = false;
	DataModuleDB->FDQueryProcurarProduto->ParamByName("CATEGORIANOME")->AsAnsiString =  "%"+Edit1->Text+"%";
	DataModuleDB->FDQueryProcurarProduto->Active = true;
	if (DataModuleDB->FDQueryProcurarProduto->FieldByName("CATEGORIANOME")->AsAnsiString == "")
	{
		ShowMessage("Não existe nenhum produto com esta categoria");
		return;
	}
}
//---------------------------------------------------------------------------
