//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitLogin.h"
#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormLogin *FormLogin;
//---------------------------------------------------------------------------
__fastcall TFormLogin::TFormLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::Button3Click(TObject *Sender)
{
	AnsiString sql = "select * from viewusuarios where USUARIONOME = \""+EditUserName->Text+"\" and USUARIOSENHA = \""+EditSenha->Text+"\";";
	TFDQuery *FDQuery1 = DataModuleDB->Conexao.QConsultaSQL(sql);
	if (!FDQuery1->Eof)
		UserLogin.SetQuery(FDQuery1);
	FDQuery1->Close();
	FDQuery1->Free();
	if (UserLogin.getUSUARIOID())
	{
		{
			Close();
			ShowMessage("Bem Vindo "+UserLogin.getUSUARIONOMECOMPLETO()+"\nPrevilegio: "+UserLogin.getPREVILEGIONOME()) ;
			DataModuleDB->Conexao.SetUsuarioActual(UserLogin);
			return;
		}

   }
   else
   {
	   ShowMessage("Nome do usuário ou senha incorrecta.\nPor favor tente novamente...");
	   Button1Click(Sender);
   }
   EditUserName->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::Button1Click(TObject *Sender)
{
	EditUserName->Text = "";
	EditSenha->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::Button2Click(TObject *Sender)
{
	Button1Click(Sender);
	Close();
}
//---------------------------------------------------------------------------


