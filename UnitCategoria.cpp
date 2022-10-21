//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitCategoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormCategoria *FormCategoria;
//---------------------------------------------------------------------------
__fastcall TFormCategoria::TFormCategoria(TComponent* Owner)
	: TForm(Owner)
{
	IdCategoria = 0;
	Alterar= 0;
	Panel3->Visible = false;
}
//---------------------------------------------------------------------------

void TFormCategoria::MostrarForm()
{
  ShowModal();
}

void __fastcall TFormCategoria::SalvarClick(TObject *Sender)
{
	CATEGORIA newCATEGORIA;
	newCATEGORIA.setCATEGORIANOME(Edit2->Text);
	if (newCATEGORIA.IsEmpty())
	{

		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddCategoria(newCATEGORIA);
	}
	else
	{
	DataModuleDB->Conexao.ModCategoria(newCATEGORIA,IdCategoria);
	Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TFormCategoria::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdCategoria = StrToInt(AItem->Detail);
}
//---------------------------------------------------------------------------

void __fastcall TFormCategoria::ButtonEliminarClick(TObject *Sender)
{

	if (MessageDlg("O sistema irá eliminar a categoria "+IntToStr(IdCategoria)+
	"\nPretendes eliminar esta categoria?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
		DataModuleDB->Conexao.DeleteCategoria(IdCategoria);
		Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormCategoria::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryCategorias->Active = false;
	DataModuleDB->FDQueryCategorias->Active = true;
}
//---------------------------------------------------------------------------



void __fastcall TFormCategoria::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	Edit2->Text = DataModuleDB->Conexao.FoundCategoria(IdCategoria).getCATEGORIANOME();
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormCategoria::ButtonNomeClick(TObject *Sender)
{
	Panel3->Visible = true;
	Panel2->Visible = false;
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormCategoria::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
	ListView1->Enabled = true;
}
//---------------------------------------------------------------------------





