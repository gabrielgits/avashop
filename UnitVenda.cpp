//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitVenda.h"
#include "UnitDB.h"
#include "UnitProduto.h"
#include "UnitCliente.h"
#include "UnitReport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormVenda *FormVenda;
//---------------------------------------------------------------------------
__fastcall TFormVenda::TFormVenda(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormVenda::Button1Click(TObject *Sender)
{
	PRODUTO tempPRODUTO = FormProduto->MostrarForm();
	IdProduto = tempPRODUTO.getPRODUTOID();
	Edit1->Text  =  tempPRODUTO.getPRODUTONOME();
	Label1->Text = "Preço do Produto: "+FloatToStr(tempPRODUTO.getPRODUTOPRECO())+".00 AKZ";
}
//---------------------------------------------------------------------------
void TFormVenda::MostrarForm()
{
    ShowModal();
}

void __fastcall TFormVenda::Button2Click(TObject *Sender)
{
	CLIENTE tempCLIENTE = FormCliente->MostrarForm();
	IdCliente =  tempCLIENTE.getCLIENTEID();
	Edit2->Text  =  tempCLIENTE.getPESSOANOME();
	Label2->Text = "Valor na Conta: "+FloatToStr(tempCLIENTE.getCLIENTECONTA())+".00 AKZ";
}
//---------------------------------------------------------------------------

void __fastcall TFormVenda::Button3Click(TObject *Sender)
{
  if (StrToInt(EditQuant->Text) < 1)
  {
	ShowMessage("Quantidade de produto invalida");
	return;
  }
	if (MessageDlg("Adicionar "+Edit1->Text+" ao carrinho?\n"+
		"Quantidade: "+StrToInt(EditQuant->Text),TMsgDlgType::mtInformation,
	TMsgDlgButtons()<< TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0) == mrYes)
	{
		AnsiString SQL = "INSERT INTO vendatemp (PRODUTOID, CLIENTEID,VENDAQUANTIDADE) "
		"VALUES ("+IntToStr(IdProduto)+","+IntToStr(IdCliente)+","+EditQuant->Text+")";
		if (!DataModuleDB->Conexao.QExecuteSQL(SQL))
		{
			return;
		}

		DataModuleDB->FDQueryVendaTemp->Refresh();
	}
	Edit1->Text = "";
	Label1->Text = "";
	EditQuant->Text = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormVenda::ButtonNomeClick(TObject *Sender)
{
   DataModuleDB->FDQueryVendaTemp->Refresh();
	while (!DataModuleDB->FDQueryVendaTemp->Eof)
	{
		VENDA tempVENDA;
		tempVENDA.setPRODUTOID(DataModuleDB->FDQueryVendaTemp->FieldByName("PRODUTOID")->AsInteger);
		tempVENDA.setCLIENTEID(DataModuleDB->FDQueryVendaTemp->FieldByName("CLIENTEID")->AsInteger);
		tempVENDA.setVENDAQUANTIDADE(DataModuleDB->FDQueryVendaTemp->FieldByName("VENDAQUANTIDADE")->AsInteger);
		tempVENDA.setVENDADATA(Date().CurrentDate());
		tempVENDA.setUSUARIOID(DataModuleDB->Conexao.GetUsuarioActual().getUSUARIOID());
		DataModuleDB->Conexao.AddVENDA(tempVENDA);

		STOCK tempSTOCK = DataModuleDB->Conexao.FoundSTOCK(DataModuleDB->
		FDQueryVendaTemp->FieldByName("PRODUTOID")->AsInteger);

		tempSTOCK.setSTOCKQUANTIA(tempSTOCK.getSTOCKQUANTIA() - DataModuleDB->
		FDQueryVendaTemp->FieldByName("VENDAQUANTIDADE")->AsInteger);

		tempSTOCK.setSTOCKUPDATE(Date().CurrentDate());

		tempSTOCK.setPRODUTOID(DataModuleDB->
		FDQueryVendaTemp->FieldByName("PRODUTOID")->AsInteger);

		DataModuleDB->Conexao.ModSTOCK(tempSTOCK,tempSTOCK.getSTOCKID());


		DataModuleDB->FDQueryVendaTemp->Next();

	}

	DataModuleReport->frxReport1->Clear();

	DataModuleReport->frxReport1->Report->LoadFromFile("..\\..\\relatorios\\faturavenda.fr3");

	DataModuleReport->frxReport1->ShowReport();

	DataModuleDB->Conexao.QExecuteSQL("delete from vendatemp");
	Button4Click(Sender);
	ButtonAlterarClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormVenda::Button4Click(TObject *Sender)
{
	DataModuleDB->FDQueryVendaTemp->Active = false;
	DataModuleDB->FDQueryVendaTemp->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormVenda::ButtonImprimirClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormVenda::ButtonAlterarClick(TObject *Sender)
{
	DataModuleDB->Conexao.QExecuteSQL("delete from vendatemp");
	Button4Click(Sender);
	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------



