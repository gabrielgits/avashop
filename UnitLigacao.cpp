//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitLigacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormLigacao *FormLigacao;

int TFormLigacao::CriarConexao()
{
	if (!InfoDB.WriteRegistry())
	{
		return 0;
	}
   if (!DataModuleDB->Conexao.TestaDB(InfoDB))
   {
	   return 0;

   }
   TFDQuery * FDQuery = new TFDQuery(NULL);
   FDQuery->SQL->LoadFromFile(DataModuleDB->AppInfo.getApp()+
   DataModuleDB->AppInfo.getScripts()+"dbavaschool.sql");
   DataModuleDB->Conexao.QExecuteSQL(FDQuery);
   return IniciarConexao();
}

int TFormLigacao::IniciarConexao()
{
	DataModuleDB->Conexao.InserirLog("Carregar Arquivo de Configura��es");
	if (!InfoDB.ReadRegistry())
	{
		return 0;
	}
	Edit1->Text = InfoDB.Getservidor();
	Edit2->Text = InfoDB.Getusername();
	Edit3->Text = InfoDB.Getsenha();

	return AplicarConexao();

}

int TFormLigacao::AplicarConexao()
{
	DataModuleDB->DesconectarDB();

	InfoDB.Setservidor(Edit1->Text);
	InfoDB.Setusername(Edit2->Text);
	InfoDB.Setsenha(Edit3->Text);

	if (!DataModuleDB->ConectarDB(InfoDB))
	{
		return 0;
	}
	if (!InfoDB.WriteRegistry())
	{
		return 0;
	}
	return 1;

}

void __fastcall TFormLigacao::MostrarLigacao()
{

	ShowModal();

}
//---------------------------------------------------------------------------
__fastcall TFormLigacao::TFormLigacao(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLigacao::Button1Click(TObject *Sender)
{

	if (MessageDlg("O sistema ir� terminar para que as novas configura��es de "
	"conex�o de base de dados sejam Aplicadas\n"
	"As novas configura��es ser�o apreentadas a proxima vez que inicar o aplicativo"
	"Terminar e aplicar as configura��es?", TMsgDlgType::mtInformation,
	TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbCancel,0) == mrYes)
	{
		if (AplicarConexao())
		{
			ShowMessage("Liga��o com o servidor estabelecida com sucesso");
				DataModuleDB->IniciarQuery();
			Close();
		}
		else
		{
		ShowMessage("Problema ao estabelecer uma liga��o com o servidor.\n"
		"Verifique as configura��es e tente novamente");
		}
	}
}
//---------------------------------------------------------------------------
