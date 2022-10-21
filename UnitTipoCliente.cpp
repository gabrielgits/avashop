//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitTipoCliente.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormTipoCliente *FormTipoCliente;
//---------------------------------------------------------------------------
__fastcall TFormTipoCliente::TFormTipoCliente(TComponent* Owner)
	: TForm(Owner)
{
	Panel3->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormTipoCliente::ButtonNomeClick(TObject *Sender)
{
	Panel3->Visible = true;
	Panel2->Visible = false;
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormTipoCliente::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	Edit2->Text = DataModuleDB->Conexao.FoundTIPOCLIENTE(IdTipoCliente).getTIPOCLIENTENOME();
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------
void TFormTipoCliente::MostrarForm()
{
    ShowModal();
}
void __fastcall TFormTipoCliente::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar o tipo de cliente "+IntToStr(IdTipoCliente)+
	"\nPretendes eliminar este tipo de cliente?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
	DataModuleDB->Conexao.DeleteTIPOCLIENTE(IdTipoCliente);
	Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTipoCliente::SalvarClick(TObject *Sender)
{

	TIPOCLIENTE newTIPOCLIENTE;
	newTIPOCLIENTE.setTIPOCLIENTENOME(Edit2->Text);
	if (newTIPOCLIENTE.IsEmpty())
	{

		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddTIPOCLIENTE(newTIPOCLIENTE);
	}
	else
	{
	DataModuleDB->Conexao.ModTIPOCLIENTE(newTIPOCLIENTE,IdTipoCliente);
	Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormTipoCliente::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
	ListView1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormTipoCliente::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryTipoCliente->Active = false;
	DataModuleDB->FDQueryTipoCliente->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormTipoCliente::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdTipoCliente = StrToInt(AItem->Detail);

}
//---------------------------------------------------------------------------


