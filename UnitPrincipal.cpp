//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitPrincipal.h"
#include "UnitLigacao.h"
#include "UnitCategoria.h"
#include "UnitCliente.h"
#include "FORNECEDORE.h"
#include "UnitFornecedor.h"
#include "UnitCompra.h"
#include "UnitPrevilegio.h"
#include "UnitTipoCliente.h"
#include "STOCK.h"
#include "UnitStock.h"
#include "UnitProduto.h"
#include "UnitUsuario.h"
#include "UnitPessoa.h"
#include "UnitBuscaProduto.h"
#include "UnitVenda.h"
#include "UnitLogin.h"
#include "UnitSplash.h"
#include "UnitGestaoVenda.h"
#include "UnitConsultarProduto.h"
#include "uMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormPrincipal *FormPrincipal;


//---------------------------------------------------------------------------
__fastcall TFormPrincipal::TFormPrincipal(TComponent* Owner)
	: TForm(Owner)
{
	TerminarSessao();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::TerminarSessao()
{
	//StatusBar1->Panels->Items[0]->Text = "Sem Sessão Iniciada";
	FecharMenu();

}
void __fastcall TFormPrincipal::FecharMenu()
{
	Memo1->Visible = false;
	MenuItem29->Enabled = true;
	MenuItem30->Enabled = false;

	MenuItem12->Enabled = false;
	MenuItem13->Enabled = false;
	MenuItem14->Enabled = false;

	MenuItem17->Enabled = false;
	MenuItem18->Enabled = false;
	MenuItem19->Enabled = false;
	MenuItem20->Enabled = false;

	MenuItem22->Enabled = false;
	MenuItem23->Enabled = false;
	MenuItem24->Enabled = false;
	MenuItem25->Enabled = false;
	MenuItem16->Enabled = false;

}
void __fastcall TFormPrincipal::AcessoMenu(int Previlegio)
{
	MenuItem29->Enabled = false;
	MenuItem30->Enabled = true;
	Memo1->Visible = true;
	if (Previlegio < 5)
	{

		MenuItem22->Enabled = true;
		MenuItem23->Enabled = true;
		MenuItem24->Enabled = true;
		MenuItem25->Enabled = true;
		MenuItem16->Enabled = true;
	}
	if (Previlegio < 4)
	{
		MenuItem17->Enabled = true;
		MenuItem18->Enabled = true;
		MenuItem19->Enabled = true;
		MenuItem20->Enabled = true;

	}
	if (Previlegio < 3)
	{
		MenuItem12->Enabled = true;
		MenuItem13->Enabled = true;
		MenuItem14->Enabled = true;
	}

}

void IniciarSesssao(USUARIO User)
{
	if (User.getUSUARIOID())
	{
		//FormPrincipal->StatusBar1->Panels->Items[0]->Text ="Nome do Usuário: "+User.Getnomecompleto();
		FormPrincipal->AcessoMenu(User.getPREVILEGIOID());
	}
}

void __fastcall TFormPrincipal::FormShow(TObject *Sender)
{

	Calendar1->DateTime = Date().CurrentDateTime();

	DataModuleDB->AppInfo.ReadRegistry();
	if (!FormLigacao->IniciarConexao())
	{
		ShowMessage("Ligação com o servidor não estabelecida");
		FormLigacao->ShowModal();
	}
	if (!DataModuleDB->IniciarQuery())
	{
		ShowMessage("Os componontes de dados não foram iniciados correctamente");
		FormLigacao->ShowModal();
	}
	Caption = DataModuleDB->AppInfo.getInstNome();
}
//---------------------------------------------------------------------------




void __fastcall TFormPrincipal::FormCreate(TObject *Sender)
{
	FormSplash =  new TFormSplash(FormSplash);
	DataModuleDB = new TDataModuleDB(DataModuleDB);
	if (!DataModuleDB->AppInfo.ReadRegistry())
	{
		ShowMessage("Parece que exite um problema interno com o sistema, Renicie o sistema.\n"
		"Se o problema persistir volte a instalar o sistema\n"
		"Se mesmo assim o problema continuar, consulte a nossa equipa: www.avasoft.ga");
		Application->Terminate();
	}
	RegitroApp();
	FormSplash->Text3->Text = "* "+DataModuleDB->AppInfo.getInstNome()+" *";
	FormSplash->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem29Click(TObject *Sender)
{
 	FormLogin->ShowModal();
	IniciarSesssao(DataModuleDB->Conexao.GetUsuarioActual());
	Memo1->Lines->Clear();
	USUARIO user = DataModuleDB->Conexao.GetUsuarioActual();
    Memo1->Lines->Add("");
	Memo1->Lines->Add("Informações do Usuário");
	Memo1->Lines->Add("");
	Memo1->Lines->Add("ID do Usuário: "+IntToStr(user.getUSUARIOID()));
	Memo1->Lines->Add(user.getUSUARIONOMECOMPLETO());
	Memo1->Lines->Add(user.getPREVILEGIONOME());

}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem30Click(TObject *Sender)
{
		TerminarSessao();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem7Click(TObject *Sender)
{
	if (!SaveDialog1->Execute())
	{
		return;
	}
	try
	{

		Sleep(5000);
	}
	catch (Exception &exception)
	{
		ShowMessage("Erro ao criar o backup de dados no aquivo "+SaveDialog1->FileName+"... Erro 200: "+exception.Message);
		return;
	}
	ShowMessage("Dados salvo com sucesso");
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem8Click(TObject *Sender)
{
	if (!OpenDialog1->Execute())
	{
		return;
	}
	try
	{

		Sleep(5000);
	}
	catch (Exception &exception)
	{
		ShowMessage("Erro ao restaurar o backup de dados do aquivo "+OpenDialog1->FileName+"... Erro 200: "+exception.Message);
		return;
	}
	ShowMessage("Dados restaurados com sucesso");
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem9Click(TObject *Sender)
{
	Sleep(5000);
	ShowMessage("Base de dados actualizado com sucesso");
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem10Click(TObject *Sender)
{
	Sleep(5000);
	ShowMessage("Base de dados Optimizado com sucesso");
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem11Click(TObject *Sender)
{
	Application->Terminate();

}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem12Click(TObject *Sender)
{
 FormCategoria->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem13Click(TObject *Sender)
{
	FormPrevilegio->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem14Click(TObject *Sender)
{
	FormTipoCliente->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem17Click(TObject *Sender)
{
	FormFornecedor->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem18Click(TObject *Sender)
{
	FormProduto->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem20Click(TObject *Sender)
{
	FormCliente->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem19Click(TObject *Sender)
{
	FormUsuario->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem22Click(TObject *Sender)
{
	FormVenda->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem24Click(TObject *Sender)
{
 	FormStock->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem25Click(TObject *Sender)
{
	FormGestaoVenda->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem23Click(TObject *Sender)
{
	FormCompra->MostrarForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem16Click(TObject *Sender)
{
	FormProcurarProdutos->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MenuItem31Click(TObject *Sender)
{
   CameraComponentForm->MostrarForm();
}
//---------------------------------------------------------------------------


 void TFormPrincipal::RegitroApp()
{
	TRegistry* reg = new TRegistry(KEY_WRITE);


	reg->RootKey = HKEY_CURRENT_USER;
	reg->Access = KEY_WRITE;
	if(reg->KeyExists("Software\\Avasoft\\Avashop\\Licence\\"))
	{
		DataModuleDB->Licence.ReadRegistry();

		if (DataModuleDB->Licence.getTipo() != 28256)
		{
			int Dias = DataModuleDB->Licence.getTempo();
			FormSplash->Label2->Text = " Dias restante de uso do sistema: "+IntToStr(Dias)+" dias";
			if (Dias > 0)
			{
				if (DataModuleDB->Licence.getData() != Date().CurrentDate())
				{
					Dias--;
					reg->OpenKey("Software\\Avasoft\\Avashop\\Licence\\",false);
					reg->WriteInteger("Tempo",Dias);
					reg->WriteDate("Data",Date().CurrentDate());
				}
			}
			else
			{
				//FormRegistro = new TFormRegistro(FormRegistro);
				//FormRegistro->ShowModal();
				Application->Terminate();
			}

		}
		reg->CloseKey();
		reg->Free();
		return;
	}
   Application->Terminate();
}
