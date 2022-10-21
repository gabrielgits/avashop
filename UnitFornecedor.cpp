//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitFornecedor.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormFornecedor *FormFornecedor;
//---------------------------------------------------------------------------
__fastcall TFormFornecedor::TFormFornecedor(TComponent* Owner)
	: TForm(Owner)
{
 Panel3->Visible = False;
}
//---------------------------------------------------------------------------
void __fastcall TFormFornecedor::ButtonNomeClick(TObject *Sender)
{
    Panel3->Visible = true;
	Panel2->Visible = false;
	ListView1->Enabled = False;
}
//---------------------------------------------------------------------------

void __fastcall TFormFornecedor::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	FORNECEDORE tempFORNECEDORE = DataModuleDB->Conexao.FoundFORNECEDORE(IdFornecedor);
	Edit2->Text = tempFORNECEDORE.getFORNECEDORNOME();
	Edit4->Text = tempFORNECEDORE.getFORNECEDORENDERECO();
	Edit3->Text = tempFORNECEDORE.getFORNECEDORCONTACTO();
	IdFornecedor = tempFORNECEDORE.getFORNECEDORID();
	ListView1->Enabled = false;
}

//---------------------------------------------------------------------------
void TFormFornecedor::MostrarForm()
{
    ShowModal();
}
void __fastcall TFormFornecedor::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar o fornecedor "+IntToStr(IdFornecedor)+
	"\nPretendes eliminar este tipo de fornecedor?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
	DataModuleDB->Conexao.DeleteFORNECEDORE(IdFornecedor);
	Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormFornecedor::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryFornecedor->Active = false;
	DataModuleDB->FDQueryFornecedor->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormFornecedor::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
	ListView1->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TFormFornecedor::SalvarClick(TObject *Sender)
{
	FORNECEDORE newFORNECEDOR;
	newFORNECEDOR.setFORNECEDORNOME(Edit2->Text);
	newFORNECEDOR.setFORNECEDORCONTACTO(Edit3->Text);
	newFORNECEDOR.setFORNECEDORENDERECO(Edit4->Text);
	if (newFORNECEDOR.IsEmpty())
	{

		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddFORNECEDORE(newFORNECEDOR);
	}
	else
	{
	DataModuleDB->Conexao.ModFORNECEDORE(newFORNECEDOR,IdFornecedor);
	Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TFormFornecedor::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdFornecedor = StrToInt(AItem->Detail);
}
//---------------------------------------------------------------------------

