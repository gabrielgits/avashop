//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitGestaoVenda.h"
#include "UnitDB.h"
#include "UnitReport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormGestaoVenda *FormGestaoVenda;
//---------------------------------------------------------------------------
__fastcall TFormGestaoVenda::TFormGestaoVenda(TComponent* Owner)
	: TForm(Owner)
{
}
void TFormGestaoVenda::MostrarForm()
{
	DataModuleDB->FDQueryVendaInvetAno->Active = false;
	DataModuleDB->FDQueryVendaInvetAno->Active = true;
	ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormGestaoVenda::Button3Click(TObject *Sender)
{
	//TDate Data = MonthCalendar1->Date;
	DataModuleDB->FDQueryVendaInvetAno->ParamByName("ANO")->AsAnsiString = Button3->TagString;
	DataModuleDB->FDQueryVendaInvetAno->Active = true;
	DataModuleDB->FDQueryVendaInvetAno->Refresh();
	if (DataModuleDB->FDQueryVendaInvetAno->Eof)
	{
		ShowMessage("Não foi efectuada nenhuma venda no ano de "+
		Button3->TagString);
		return;
	}

	DataModuleReport->frxReport1->Clear();

	DataModuleReport->frxReport1->Report->LoadFromFile("..\\..\\relatorios\\iventanual.fr3");

	DataModuleReport->frxReport1->ShowReport();
	DataModuleDB->FDQueryVendaInvetAno->Close();
}
//---------------------------------------------------------------------------



void __fastcall TFormGestaoVenda::Button2Click(TObject *Sender)
{
//TDate Data = MonthCalendar1->Date;
	DataModuleDB->FDQueryVendaInvtMes->ParamByName("ANO")->AsAnsiString = Button3->TagString;
	DataModuleDB->FDQueryVendaInvtMes->ParamByName("MES")->AsAnsiString = ComboBox1->ItemIndex+1;
	DataModuleDB->FDQueryVendaInvtMes->Active = true;
	DataModuleDB->FDQueryVendaInvtMes->Refresh();
	if (DataModuleDB->FDQueryVendaInvtMes->Eof)
	{
		ShowMessage("Não foi efectuda nenhuma venda no mês de "+IntToStr(ComboBox1->ItemIndex+1)
		+" ano de "+Button3->TagString);
		return;
	}

	DataModuleReport->frxReport1->Clear();

	DataModuleReport->frxReport1->Report->LoadFromFile("..\\..\\relatorios\\iventmensal.fr3");

	DataModuleReport->frxReport1->ShowReport();
	DataModuleDB->FDQueryVendaInvtMes->Close();

}
//---------------------------------------------------------------------------


void __fastcall TFormGestaoVenda::Button1Click(TObject *Sender)
{
//TDate Data = MonthCalendar1->Date;
	DataModuleDB->FDQueryVendaInvtDia->ParamByName("DATA")->AsDate = DateEdit1->Date;
	DataModuleDB->FDQueryVendaInvtDia->Active = true;
	DataModuleDB->FDQueryVendaInvtDia->Refresh();
	if (DataModuleDB->FDQueryVendaInvtDia->Eof)
	{
		ShowMessage("Não foi efectuda nenhuma venda no dia "+DateEdit1->Date);
		return;
	}

	DataModuleReport->frxReport1->Clear();

	DataModuleReport->frxReport1->Report->LoadFromFile("..\\..\\relatorios\\iventdiario.fr3");

	DataModuleReport->frxReport1->ShowReport();
	DataModuleDB->FDQueryVendaInvtDia->Close();
}
//---------------------------------------------------------------------------



