//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitPrevilegio.h"
#include "PREVILEGIO.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormPrevilegio *FormPrevilegio;
//---------------------------------------------------------------------------
__fastcall TFormPrevilegio::TFormPrevilegio(TComponent* Owner)
	: TForm(Owner)
{ 	Panel3->Visible = False;

}
//---------------------------------------------------------------------------
void __fastcall TFormPrevilegio::ButtonNomeClick(TObject *Sender)
{
	Panel3->Visible = True;
	Panel2->Visible = False;
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrevilegio::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	Edit2->Text = DataModuleDB->Conexao.FoundPREVILEGIO(IdPrevilegio).getPREVILEGIONOME();
	ListView1->Enabled = false;
}
//---------------------------------------------------------------------------
void TFormPrevilegio::MostrarForm()
{
    ShowModal();
}
void __fastcall TFormPrevilegio::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar o previlegio "+IntToStr(IdPrevilegio)+
	"\nPretendes eliminar este tipo de previlegio?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
	DataModuleDB->Conexao.DeletePREVILEGIO(IdPrevilegio);
	Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrevilegio::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryPrevilegio->Active = false;
	DataModuleDB->FDQueryPrevilegio->Active = true;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrevilegio::SalvarClick(TObject *Sender)
{
PREVILEGIO newPREVILEGIO;
	newPREVILEGIO.setPREVILEGIONOME(Edit2->Text);
	if (newPREVILEGIO.IsEmpty())
	{

		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddPREVILEGIO(newPREVILEGIO);
	}
	else
	{
	DataModuleDB->Conexao.ModPREVILEGIO(newPREVILEGIO,IdPrevilegio);
	Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormPrevilegio::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
	ListView1->Enabled = true;;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrevilegio::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdPrevilegio = StrToInt(AItem->Detail);
}
//---------------------------------------------------------------------------

