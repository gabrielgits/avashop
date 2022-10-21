//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitCliente.h"
#include "UnitDB.h"
#include "UnitPessoa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormCliente *FormCliente;
//---------------------------------------------------------------------------
__fastcall TFormCliente::TFormCliente(TComponent* Owner)
	: TForm(Owner)
{
	IdCliente = 0;
	Alterar= 0;
	Panel3->Visible = false;
}
//---------------------------------------------------------------------------
CLIENTE TFormCliente::MostrarForm()
{
	ShowModal();
	return DataModuleDB->Conexao.FoundCliente(IdCliente);
}

void __fastcall TFormCliente::ButtonAlterarClick(TObject *Sender)
{
	Alterar = 1;
	Panel3->Visible = True;
	Panel2->Visible = False;
	CLIENTE temCLIENTE = DataModuleDB->Conexao.FoundCliente(IdCliente);
	EditConta->Text = temCLIENTE.getCLIENTECONTA();
	IPessoa = temCLIENTE.getPESSOAID();
	pPESSOA = DataModuleDB->Conexao.FoundPESSOA(IPessoa);
	ListView1->Enabled = False;
	Rectangle1->Visible = False;

}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::ButtonEliminarClick(TObject *Sender)
{
	if (MessageDlg("O sistema irá eliminar o cliente "+IntToStr(IdCliente)+
	"\nPretendes eliminar este cliente?" ,TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{

	DataModuleDB->Conexao.DeleteCliente(IdCliente);
	ButtonAtualizarClick(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::ButtonAtualizarClick(TObject *Sender)
{
	DataModuleDB->FDQueryCliente->Active = false;
	DataModuleDB->FDQueryCliente->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	EditConta->Text = "";
	ListView1->Enabled = True;
	Rectangle1->Visible = True;
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::SalvarClick(TObject *Sender)
{
	CLIENTE newCliente;
	newCliente.setCLIENTECONTA(StrToFloat(EditConta->Text));
	newCliente.setTIPOCLIENTEID(DataModuleDB->FDQueryTipoCliente->
	FieldByName("TIPOCLIENTEID")->AsInteger);
	newCliente.setPESSOAID(IPessoa);
	if (newCliente.IsEmpty())
	{
		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddCliente(newCliente,pPESSOA);
	}
	else
	{
		DataModuleDB->Conexao.ModCliente(newCliente,IdCliente);
		DataModuleDB->Conexao.ModPESSOA(pPESSOA,pPESSOA.getPESSOAID());
		Alterar =0;
	}
	ButtonAtualizarClick(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::Button1Click(TObject *Sender)
{
	pPESSOA = FormPessoa->MostrarForm(pPESSOA);
	Label3->Text = "Nome do Cliente: "+pPESSOA.getPESSOANOME();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::ButtonTipoClienteClick(TObject *Sender)
{
	Panel3->Visible = True;
	Panel2->Visible = False;
	pPESSOA = PESSOA();
	ListView1->Enabled = False;
	Rectangle1->Visible = False;
}
//---------------------------------------------------------------------------


void __fastcall TFormCliente::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdCliente = StrToInt(AItem->Detail);
	CLIENTE tempCLIENTE = DataModuleDB->Conexao.FoundCliente(IdCliente);
	Edit2->Text = tempCLIENTE.getCLIENTECONTA();
	Edit1->Text = tempCLIENTE.getTIPOCLIENTENOME();
	Memo1->Lines->Clear();
	Memo1->Lines->Add("Nome do Cliente: "+tempCLIENTE.getPESSOANOME());
	Memo1->Lines->Add("Número do BI: "+tempCLIENTE.getPESSOABI());
	Memo1->Lines->Add("Conatcto: "+tempCLIENTE.getPESSOACONTACTO());
	Memo1->Lines->Add("Morada: "+tempCLIENTE.getPESSOAMORADA());
	Memo1->Lines->Add("Data de Nascimento: "+tempCLIENTE.getPESSOADATA());

}
//---------------------------------------------------------------------------




void __fastcall TFormCliente::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::ListView1DblClick(TObject *Sender)
{
		Close();
}
//---------------------------------------------------------------------------

