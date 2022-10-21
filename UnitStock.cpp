//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitStock.h"
#include "UnitDB.h"
#include "UnitCompra.h"
#include "UnitVenda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormStock *FormStock;
//---------------------------------------------------------------------------
__fastcall TFormStock::TFormStock(TComponent* Owner)
	: TForm(Owner)
{
}
void TFormStock::MostrarForm()
{

	Button1Click(NULL);
	ShowModal();
}

//---------------------------------------------------------------------------


void __fastcall TFormStock::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdProduto = StrToInt(AItem->Detail);
	STOCK tempSTOCK;
	tempSTOCK = DataModuleDB->Conexao.FoundSTOCK(IdProduto);
	Memo1->Lines->Clear();
	IdStock = tempSTOCK.getSTOCKID();
	Memo1->Lines->Add("ID do Stock: "+IntToStr(tempSTOCK.getSTOCKID()));
	Memo1->Lines->Add("ID do Produto: "+IntToStr(tempSTOCK.getPRODUTOID()));
	Memo1->Lines->Add("Nome do Produto: "+tempSTOCK.getPRODUTONOME());
	Memo1->Lines->Add("Preço de Venda: "+FloatToStr(tempSTOCK.getPRODUTOPRECO()));
	Memo1->Lines->Add("Categotia do Produto: "+tempSTOCK.getCATEGORIANOME());
	Memo1->Lines->Add("Quant Disponivel: "+IntToStr(tempSTOCK.getSTOCKQUANTIA()));
	Memo1->Lines->Add("Ultima Mudança(Venda/Compra) do Produto no Stock: "+tempSTOCK.getSTOCKUPDATE());

}
//---------------------------------------------------------------------------


void __fastcall TFormStock::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar do stock o produto com ID: "+IntToStr(IdStock)+
	"\nPretendes eliminar este produto do stock?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
		DataModuleDB->Conexao.DeleteSTOCK(IdStock);
	   ///	Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------




void __fastcall TFormStock::Button1Click(TObject *Sender)
{
DataModuleDB->FDQueryStock->Active = false;
DataModuleDB->FDQueryStock->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormStock::ButtonNomeClick(TObject *Sender)
{
	FormCompra->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormStock::ButtonAlterarClick(TObject *Sender)
{
	FormVenda->MostrarForm();
}
//---------------------------------------------------------------------------

