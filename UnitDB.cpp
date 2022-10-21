//---------------------------------------------------------------------------


#pragma hdrstop

#include "UnitDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
TDataModuleDB *DataModuleDB;


int TDataModuleDB::ConectarDB(AvaInfoDB DB)
{
	Conexao.InserirLog("Estabelendo ligação principal da base de dados");

		try
		{
			FDConnection1->Params->Add("Database="+DB.Getbasedados());
			FDConnection1->Connected = true;
		}
		catch (EDatabaseError& E)
		{
			Conexao.InserirLogErro("Erro ao ligar a base de dados: "+E.Message);
			return 0;
		}
		if (Conexao.ConectarDB(DB) == NULL)
		{
			Conexao.InserirLogErro("Erro ao ligar a base de dados...");

			return 0;
		}
	Conexao.InserirLog("Ligação principal da base de dados estabelecida com sucesso");
	return 1;

}

int TDataModuleDB::DesconectarDB()
{
	Conexao.InserirLog("Terminado ligação principal da base de dados");
	try
	{
		Conexao.Disconect();
		FDConnection1->Connected = false;
	}
	catch (EDatabaseError& E)
	{

		Conexao.InserirLogErro("Erro ao terminar base de dados: "+E.Message);
		return 0;
	}
	Conexao.InserirLog("Ligação principal da base de dados terminado");
	return 1;

}

int  TDataModuleDB::IniciarQuery()
{
	Conexao.InserirLog("Iniciando todos os componetes de dados");
	try
	{
		FDQueryCategorias->Connection = Conexao.GetFDConexao();
		FDQueryCategorias->Active = true;

		/*FDTableAnoLectivos->Connection = Conexao2.GetFDConexao();
		FDTableClasses->Connection = Conexao2.GetFDConexao();
		FDTableConfig->Connection = Conexao2.GetFDConexao();
		FDTableCursos->Connection = Conexao2.GetFDConexao();
		FDTableEncarregados->Connection = Conexao2.GetFDConexao();
		FDTablePeriodos->Connection = Conexao2.GetFDConexao();
		FDTableSalas->Connection = Conexao2.GetFDConexao();
		FDTableTipoMatriculas->Connection = Conexao2.GetFDConexao();
		FDTableTipoPagamento->Connection = Conexao2.GetFDConexao();
        FDTableUserEstado->Connection = Conexao2.GetFDConexao();
		FDTableUserPrevilegios->Connection = Conexao2.GetFDConexao();

		FDQueryAllEstudantes->Connection = Conexao2.GetFDConexao();
		FDQueryAllPropinas->Connection = Conexao2.GetFDConexao();
		FDQueryEstExpot->Connection = Conexao2.GetFDConexao();
		FDQueryEstPropinaAtraso->Connection = Conexao2.GetFDConexao();
		FDQueryEstudantes->Connection = Conexao2.GetFDConexao();
		FDQueryEstudantesTurma->Connection = Conexao2.GetFDConexao();
		FDQueryFacturaPropina->Connection = Conexao2.GetFDConexao();
		FDQueryFaturaPagamento->Connection = Conexao2.GetFDConexao();
		FDQueryFaturaPropinaEst->Connection = Conexao2.GetFDConexao();
		FDQueryGeneros->Connection = Conexao2.GetFDConexao();
		FDQueryMatriculaEst->Connection = Conexao2.GetFDConexao();
		FDQueryMatriculas->Connection = Conexao2.GetFDConexao();
		FDQueryPagamento->Connection = Conexao2.GetFDConexao();
		FDQueryPropinas->Connection = Conexao2.GetFDConexao();
		FDQueryTurmas->Connection = Conexao2.GetFDConexao();
		FDQueryUsuarios->Connection = Conexao2.GetFDConexao();


		FDTableConfig->Active = true;
		FDTableUserPrevilegios->Active = true;
		FDTableUserEstado->Active = true;
		FDTableTipoPagamento->Active = true;
		FDTableClasses->Active = true;
		FDTablePeriodos->Active = true;
		FDTableCursos->Active = true;
		FDTableSalas->Active = true;
		FDTableAnoLectivos->Active = true;
		FDTableAllAno->Active = true;
		FDTableEncarregados->Active = true;
		FDTableTipoMatriculas->Active = true;

		FDQueryPropinas->Active = true;
		FDQueryUsuarios->Active = true;
		FDQueryEstudantes->Active = true;
		FDQueryPagamento->Active = true;
		FDQueryAllPropinas->Active = true;
		FDQueryEstudantesTurma->Active = true;
		FDQueryEstPropinaAtraso->Active = true;
		FDQueryFacturaPropina->Active = true;
		FDQueryAllEstudantes->Active = true;
		FDQueryFaturaPagamento->Active = true;
		FDQueryGeneros->Active = true;
		FDQueryMatriculas->Active = true;
		FDQueryFaturaPropinaEst->Active = true;
		FDQueryTurmas->Active = true;
		*/

	}
	catch (Exception& E)
	{
		Conexao.InserirLogErro("Erro ao inicar os componetes de dados: "+E.Message);

		return 0;
	}
	Conexao.InserirLog("Todos os componetes de dados foram inicados com sucesso");
	return 1;
}

//---------------------------------------------------------------------------
__fastcall TDataModuleDB::TDataModuleDB(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDataModuleDB::DataModuleCreate(TObject *Sender)
{
	FDConnection1->Connected = true;
}
//---------------------------------------------------------------------------

