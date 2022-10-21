//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitPessoa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormPessoa *FormPessoa;
//---------------------------------------------------------------------------
__fastcall TFormPessoa::TFormPessoa(TComponent* Owner)
	: TForm(Owner)
{
}

PESSOA TFormPessoa::MostrarForm(PESSOA IdPessoa)
{
	if (IdPessoa.getPESSOAID() > 0)
	{
		Alterar = IdPessoa;
		Edit2->Text = Alterar.getPESSOANOME();
		Edit3->Text = Alterar.getPESSOACONTACTO();
		Edit4->Text = Alterar.getPESSOAMORADA();
		Edit5->Text = Alterar.getPESSOABI();
		DateEdit1->Date = Alterar.getPESSOADATA();

	}

	ShowModal();
	return Alterar;

}
//---------------------------------------------------------------------------
void TFormPessoa::MostrarForm()
{
	ShowModal();
}

void __fastcall TFormPessoa::CancelarClick(TObject *Sender)
{
	Edit2->Text = "";
	Edit3->Text	= "";
	Edit4->Text = "";
	Edit5->Text = "";
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPessoa::SalvarClick(TObject *Sender)
{
	Alterar.setPESSOANOME(Edit2->Text);
	Alterar.setPESSOACONTACTO(Edit3->Text);
	Alterar.setPESSOAMORADA(Edit4->Text);
	Alterar.setPESSOABI(Edit5->Text);
	Alterar.setPESSOADATA(DateEdit1->Date);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------





void __fastcall TFormPessoa::Button1Click(TObject *Sender)
{
	if (!OpenDialog1->Execute())
	{
		return;
    }
	try
	{

		Image1->Bitmap->LoadFromFile(OpenDialog1->FileName);
	}
	catch (Exception &exception)
	{
		ShowMessage("Erro ao abrir arquivo a foto "+OpenDialog1->FileName+"... Erro 200: "+exception.Message);
		return;
	}

}
//---------------------------------------------------------------------------

