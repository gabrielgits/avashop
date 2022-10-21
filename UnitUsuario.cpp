//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitUsuario.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormUsuario *FormUsuario;
//---------------------------------------------------------------------------
__fastcall TFormUsuario::TFormUsuario(TComponent* Owner)
	: TForm(Owner)
{
Panel3->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormUsuario::ButtonNomeClick(TObject *Sender)
{
	Panel3->Visible = true;
	Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormUsuario::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	USUARIO tempUSUARIO = DataModuleDB->Conexao.FoundUSUARIO(idUsuario);
	Edit2->Text = tempUSUARIO.getUSUARIONOME();
	Edit3->Text = tempUSUARIO.getUSUARIOSENHA();
	Edit1->Text = tempUSUARIO.getUSUARIONOMECOMPLETO();
}
//---------------------------------------------------------------------------
void TFormUsuario::MostrarForm()
{
    ShowModal();
}
void __fastcall TFormUsuario::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar o usuário "+IntToStr(idUsuario)+
	"\nPretendes eliminar este usuário?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{

	DataModuleDB->Conexao.DeleteUSUARIO(idUsuario);
	Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormUsuario::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryUsuario->Active = false;
	DataModuleDB->FDQueryUsuario->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormUsuario::SalvarClick(TObject *Sender)
{
	USUARIO newUSUARIO;
	newUSUARIO.setUSUARIONOME(Edit2->Text);
	newUSUARIO.setUSUARIONOMECOMPLETO(Edit1->Text);
	newUSUARIO.setUSUARIOSENHA(Edit1->Text);
	newUSUARIO.setPREVILEGIOID(DataModuleDB->FDQueryPrevilegio->
	FieldByName("PREVILEGIOID")->AsInteger);
	if (newUSUARIO.IsEmpty())
	{

		return;
	}
	if (!Alterar)
	{
	   DataModuleDB->Conexao.AddUSUARIO(newUSUARIO);
	}
	else
	{
		DataModuleDB->Conexao.ModUSUARIO(newUSUARIO,idUsuario);
		Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormUsuario::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormUsuario::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
idUsuario = StrToInt(AItem->Detail);
}
//---------------------------------------------------------------------------

