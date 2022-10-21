//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitCompra.h"
#include "UnitDB.h"
#include "COMPRA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormCompra *FormCompra;

void __fastcall TFormCompra::MostrarForm()
{

	ShowModal();
}

//---------------------------------------------------------------------------
__fastcall TFormCompra::TFormCompra(TComponent* Owner)
	: TForm(Owner)
{

	Panel3->Visible = false;
	Panel2->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormCompra::ButtonNomeClick(TObject *Sender)
{
	Panel3->Visible = True;
	Panel2->Visible = False;
}
//---------------------------------------------------------------------------

void __fastcall TFormCompra::ButtonAlterarClick(TObject *Sender)
{
	Alterar =1;
	Panel3->Visible = true;
	Panel2->Visible = false;
	COMPRA tempCOMPRA = DataModuleDB->Conexao.FoundCOMPRA(IdCompra);
	Edit2->Text = tempCOMPRA.getCOMPRAQUANTIDADE();
}
//---------------------------------------------------------------------------

void __fastcall TFormCompra::ButtonEliminarClick(TObject *Sender)
{
	DataModuleDB->Conexao.DeleteCOMPRA(IdCompra);
	Button1Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TFormCompra::Button1Click(TObject *Sender)
{
	DataModuleDB->FDQueryCompra->Active = false;
	DataModuleDB->FDQueryCompra->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormCompra::CancelarClick(TObject *Sender)
{
	Panel3->Visible = false;
	Panel2->Visible = true;
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormCompra::SalvarClick(TObject *Sender)
{
	try
	{
		StrToFloat(Edit1->Text);
		StrToInt(Edit2->Text);
	}
	catch (Exception &exception)
	{
		ShowMessage("Existe campos não preenchidos, por favor verifique a escrita: "
		+exception.Message);
		return;
	}



	COMPRA newCompra;
	newCompra.setUSUARIOID(1);
	newCompra.setCOMPRAQUANTIDADE(StrToInt(Edit2->Text));
	newCompra.setCOMPRADATA(Date().CurrentDate());
	newCompra.setCOMPRAPRECO(StrToFloat(Edit1->Text));
	newCompra.setFORNECEDORID(DataModuleDB->FDQueryFornecedor->FieldByName("FORNECEDORID")->AsInteger);
	newCompra.setPRODUTOID(DataModuleDB->FDQueryProduto->FieldByName("PRODUTOID")->AsInteger);
	if (newCompra.IsEmpty())
	{
		return;
	}
	if (!Alterar)
	{
		DataModuleDB->Conexao.AddCOMPRA(newCompra);

		STOCK tempSTOCK = DataModuleDB->Conexao.FoundSTOCK(newCompra.getPRODUTOID());

		tempSTOCK.setSTOCKQUANTIA(newCompra.getCOMPRAQUANTIDADE()+tempSTOCK.getSTOCKQUANTIA());
		tempSTOCK.setSTOCKUPDATE(newCompra.getCOMPRADATA());
		tempSTOCK.setPRODUTOID(newCompra.getPRODUTOID());

		if (tempSTOCK.getSTOCKID() > 0)
		{
			DataModuleDB->Conexao.ModSTOCK(tempSTOCK,tempSTOCK.getSTOCKID());
		}
		else
		{
			DataModuleDB->Conexao.AddSTOCK(tempSTOCK);
		}
	}
	else
	{
	DataModuleDB->Conexao.ModCOMPRA(newCompra,IdCompra);
	Alterar =0;
	}
	Button1Click(Sender);
	CancelarClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TFormCompra::ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	IdCompra = StrToInt(AItem->Detail);
	COMPRA tempCOMPRA;
	tempCOMPRA = DataModuleDB->Conexao.FoundCOMPRA(IdCompra);
	Memo1->Lines->Clear();
	Memo1->Lines->Add("ID da Compra: "+IntToStr(tempCOMPRA.getCOMPRAID()));

	Memo1->Lines->Add("Nome do Produto: "+tempCOMPRA.getPRODUTONOME());
	Memo1->Lines->Add("Preço de Compra: "+FloatToStr(tempCOMPRA.getCOMPRAPRECO()));
	Memo1->Lines->Add("Preço de Venda: "+FloatToStr(tempCOMPRA.getPRODUTOPRECO()));
	Memo1->Lines->Add("Categotia do Produto: "+tempCOMPRA.getCATEGORIANOME());
	Memo1->Lines->Add("Quant da Compra: "+IntToStr(tempCOMPRA.getCOMPRAQUANTIDADE()));
	Memo1->Lines->Add("Data da Compra: "+tempCOMPRA.getCOMPRADATA());
	Memo1->Lines->Add("Nome do Fornecedor: "+tempCOMPRA.getFORNECEDORNOME());
	Memo1->Lines->Add("Contacto do Fornecedor: "+tempCOMPRA.getFORNECEDORCONTACTO());
	Memo1->Lines->Add("Endereço do Fornecedor: "+tempCOMPRA.getFORNECEDORENDERECO());
	Memo1->Lines->Add("ID do Operador: "+IntToStr(tempCOMPRA.getUSUARIOID()));
	Memo1->Lines->Add("Nome do Operador: "+tempCOMPRA.getUSUARIONOME());

}
//---------------------------------------------------------------------------



void __fastcall TFormCompra::Panel3Click(TObject *Sender)
{
	FormCompra->MostrarForm();

}
//---------------------------------------------------------------------------

