//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitProduto.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormProduto *FormProduto;
//---------------------------------------------------------------------------
__fastcall TFormProduto::TFormProduto(TComponent* Owner)
	: TForm(Owner)
{
	IdProduto = 0;
	Alterar= 0;
	Panel3->Visible = false;
}
//---------------------------------------------------------------------------
PRODUTO TFormProduto::MostrarForm()
{
	ShowModal();
	return DataModuleDB->Conexao.FoundPRODUTO(IdProduto);
}
void __fastcall TFormProduto::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryProduto->Active = false;
	DataModuleDB->FDQueryProduto->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormProduto::ButtonNomeClick(TObject *Sender)
{
	Panel3->Visible = true;
	Panel2->Visible = false;
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormProduto::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	PRODUTO tempPRODUTO = DataModuleDB->Conexao.FoundPRODUTO(IdProduto);
	Edit2->Text = tempPRODUTO.getPRODUTONOME();
	Edit3->Text = tempPRODUTO.getPRODUTOPRECO();
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormProduto::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar o produto "+IntToStr(IdProduto)+
	"\nPretendes eliminar este produto?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
		DataModuleDB->Conexao.DeletePRODUTO(IdProduto);
		Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormProduto::SalvarClick(TObject *Sender)
{
	PRODUTO newPRODUTO;
	newPRODUTO.setPRODUTONOME(Edit2->Text);
	newPRODUTO.setPRODUTOPRECO(StrToFloat(Edit3->Text));
	newPRODUTO.setCATEGORIAID(DataModuleDB->FDQueryCategorias->
	FieldByName("CATEGORIAID")->AsInteger);
	if (newPRODUTO.IsEmpty())
	{
		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddPRODUTO(newPRODUTO);
	}
	else
	{
	DataModuleDB->Conexao.ModPRODUTO(newPRODUTO,IdProduto);
	Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormProduto::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
	Edit3->Text = "";
	ListView1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormProduto::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdProduto = StrToInt(AItem->Detail);
}
//---------------------------------------------------------------------------

void __fastcall TFormProduto::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormProduto::ListView1DblClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

