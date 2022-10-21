//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitAvashopDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------

AvaConexao::AvaConexao()
{
	Log.SetName("avashop ver 0.4 - Copyright © 2017 Avasoft, Todos os Direitos Reservado");
	Log.CreateLogFile();
	Log.AddLog("Iniciar o Sistema");
	FDConexao = new TFDConnection(FDConexao);
}

TFDConnection *AvaConexao::GetFDConexao()
{
	return FDConexao;
}

void AvaConexao::Disconect()
{
	if (FDConexao->Connected == true)
	 {
		FDConexao->Connected = false;
	}
	InserirLog("Ligação com a base de dados terminada com sucesso");
}


AvaConexao::~AvaConexao()
{
	Disconect();
}

// METODOS DE CONEXAO

TFDConnection *AvaConexao::ConectarDB()
{
	InserirLog("Ligar a base de dados");
	try
	{
		FDConexao->Connected = true;
	}
	catch (EDatabaseError &e)
	{

		InserirLogErro("Não foi possivel ligar a base de dados: "+e.Message);
		return NULL;
	}
	InserirLog("Ligação com a base de dados estabelecida com sucesso");
	return FDConexao;
}

TFDConnection *AvaConexao::ConectarDB(AvaInfoDB InfoConexao)
{
   // FDConexao = new TFDConnection(FDConexao);
	SetInfoDB(InfoConexao);
	return ConectarDB();
}

int AvaConexao::TestaDB(AvaInfoDB PInfoConexao)
{
	PInfoConexao.Setbasedados("mysql");
	SetInfoDB(PInfoConexao);
	if(ConectarDB() == NULL)
		return 0;
	return 1;
}

TFDConnection *AvaConexao::SetInfoDB(AvaInfoDB InfoConexao)
{
	InserirLog("Aplicar informações do servidor de base de dados");

	try
	{

		FDConexao->LoginPrompt = InfoConexao.Getpront();
		FDConexao->DriverName = InfoConexao.Getdrive();
		//FDConexao->Params->Add("Password="+InfoConexao.Getsenha());
		//FDConexao->Params->Add("Server="+InfoConexao.Getservidor());
		//FDConexao->Params->Add("Port="+InfoConexao.Getporta());
		//FDConexao->Params->Add("User_Name="+InfoConexao.Getusername());
		FDConexao->Params->Add("Database="+InfoConexao.Getbasedados());

	}
	catch (Exception &e)
	{

		InserirLogErro("Problema ao aplicar informações do servidor de base de dados: "+e.Message);
		return NULL;
	}

   return FDConexao;
}


TFDQuery *AvaConexao::QConsultaSQL(texto SQL)
{
	InserirLog("Iniciar consulta");
	TFDQuery *SQLQuery1;
	if ((!FDConexao->Connected) && (SQL != ""))
	{
		InserirLogErro("Consulta cancelada: A ligação com servidor de base de dados esta fechata");
		return NULL;
	}
	try
	{
		// Assign the query to the object SQLQuery1.
		SQLQuery1 = new TFDQuery(NULL);
		SQLQuery1->Connection = FDConexao;
		SQLQuery1->SQL->Text = SQL;
		SQLQuery1->Active = true;
	}
	catch (EDatabaseError &e)
	{

		InserirLogErro("Problema ao efectuar a consulta: "+e.Message);
		return NULL;
	}
	InserirLog("Consulta realizado com sucesso");
	return SQLQuery1;
}

int AvaConexao::QExecuteSQL(texto SQL)
{
	TFDQuery *SQLQuery1;
	SQLQuery1 = new TFDQuery(NULL);
	SQLQuery1->SQL->Add(SQL);
	SQLQuery1 = QExecuteSQL(SQLQuery1);

	if (SQLQuery1 == NULL)
	{
		return 0;
	}
	SQLQuery1->Free();
	return 1;
}

TFDQuery *AvaConexao::QExecuteSQL(TFDQuery *SQLQuery1)
{
	InserirLog("Executar a query");
	if (!FDConexao->Connected)
	{
		InserirLog("Query cancelada: A ligação com servidor de base de dados esta fechata");
		return NULL;
	}
	try
	{
		// Assign the query to the object SQLQuery1.
		SQLQuery1->Connection = FDConexao;
		SQLQuery1->ExecSQL();
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao executar a query: "+e.Message);
		return NULL;
	}
	InserirLog("Query Executado");
	return SQLQuery1;
}


//	ARQUIVOS DE LOGS
void AvaConexao::InserirLog(AnsiString Ex)
{

		Log.AddLog(Ex.c_str());
}
void AvaConexao::InserirLogErro(AnsiString Ex)
{
	const AnsiString erro = "Ocorreu um problema no sistema\n"+Ex;
	InserirLog(erro);
}

// CATEGORIA

int AvaConexao::AddCategoria(CATEGORIA pCATEGORIAS)
{
	InserirLog("Add nova categoria");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into categoria (CATEGORIANOME) values(:CATEGORIANOME);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pCATEGORIAS.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add categoria: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add a categoria não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("categoria add com sucesso");
	return 1;
}
int AvaConexao::ModCategoria(CATEGORIA pCATEGORIA, int idCATEGORIA)
{
	InserirLog("Alterar informações da categoria ID: "+IntToStr(idCATEGORIA));
	TFDQuery * FDQuery;
	AnsiString SQL;
	SQL = "update categoria set CATEGORIANOME = :CATEGORIANOME where CATEGORIAID = "+IntToStr(idCATEGORIA);
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pCATEGORIA.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar categoria: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar a categoria não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Categoria modificada com sucesso");
	return 1;

}

int AvaConexao::DeleteCategoria(int idCATEGORIA)
{
	InserirLog("Deletar categoria ID:"+IntToStr(idCATEGORIA));
	if (idCATEGORIA < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from categoria where CATEGORIAID = "+IntToStr(idCATEGORIA);
	return QExecuteSQL(SQL);
}

CATEGORIA AvaConexao::FoundCategoria(int idCATEGORIA)
{
	InserirLog("Procurar informações da categoria ID:"+IntToStr(idCATEGORIA));
	CATEGORIA tempCATEGORIA;
	if (idCATEGORIA > 0)
	{
		AnsiString SQL = "select * from categoria where CATEGORIAID = "+IntToStr(idCATEGORIA);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempCATEGORIA.SetQuery(FDQuery);
			InserirLog("Categoria encotrado");
		}
		else
			InserirLogErro("Categoria não encotrado");
		FDQuery->Free();
	}
	return tempCATEGORIA;
}

// CLIENTE

int AvaConexao::AddCliente(CLIENTE pCLIENTE, PESSOA pPESSOA)
{
	InserirLog("Add novo cliente");
	TFDQuery * FDQuery;
	pCLIENTE.setPESSOAID(AddPESSOA(pPESSOA));
	AnsiString SQL = "insert into cliente (PESSOAID, TIPOCLIENTEID, CLIENTECONTA)"
	" values(:PESSOAID, :TIPOCLIENTEID, :CLIENTECONTA);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pCLIENTE.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add cliente: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add a cliente não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("cliente add com sucesso");
	return 1;
}
int AvaConexao::ModCliente(CLIENTE pCLIENTE, int idCLIENTE)
{
	InserirLog("Alterar informações do cliente ID: "+IntToStr(idCLIENTE));
	TFDQuery * FDQuery;
	AnsiString SQL;
	SQL = "update cliente set PESSOAID = :PESSOAID, TIPOCLIENTEID = :TIPOCLIENTEID, "
	"CLIENTECONTA = :CLIENTECONTA where CLIENTEID = "+IntToStr(idCLIENTE);

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pCLIENTE.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar cliente: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar a cliente não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("cliente modificada com sucesso");
	return 1;

}

int AvaConexao::DeleteCliente(int idCLIENTE)
{
	InserirLog("Deletar cliente ID:"+IntToStr(idCLIENTE));
	if (idCLIENTE < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from cliente where CLIENTEID = "+IntToStr(idCLIENTE);
	return QExecuteSQL(SQL);
}

CLIENTE AvaConexao::FoundCliente(int idCLIENTE)
{
	InserirLog("Procurar informações da cliente ID:"+IntToStr(idCLIENTE));
	CLIENTE tempCLIENTE;
	if (idCLIENTE > 0)
	{
		AnsiString SQL = "select * from viewclientes where CLIENTEID = "+IntToStr(idCLIENTE);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempCLIENTE.SetQuery(FDQuery);
			InserirLog("cliente encotrado");
		}
		else
			InserirLogErro("cliente não encotrado");
		FDQuery->Free();
	}
	return tempCLIENTE;
}

// COMPRA

int AvaConexao::AddCOMPRA(COMPRA pCOMPRA)
{
	InserirLog("Add nova compra");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into compra (USUARIOID, PRODUTOID, COMPRADATA, "
	"COMPRAQUANTIDADE, FORNECEDORID, COMPRAPRECO) values(:USUARIOID, :PRODUTOID, :COMPRADATA, "
	":COMPRAQUANTIDADE, :FORNECEDORID, :COMPRAPRECO);";

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pCOMPRA.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add compra: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add a compra não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("compra add com sucesso");
	return 1;
}
int AvaConexao::ModCOMPRA(COMPRA pCOMPRA, int idCOMPRA)
{
	InserirLog("Alterar informações da compra ID: "+IntToStr(idCOMPRA));
	TFDQuery * FDQuery;
	AnsiString SQL;
	SQL = "update compra set USUARIOID = :USUARIOID, PRODUTOID = :PRODUTOID, "
	"COMPRADATA = :COMPRADATA, COMPRAQUANTIDADE = :COMPRAQUANTIDADE, "
	"FORNECEDORID = :FORNECEDORID, COMPRAPRECO = :COMPRAPRECO) where COMPRAID = "+IntToStr(idCOMPRA);
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pCOMPRA.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar compra: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar a compra não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Categoria compra com sucesso");
	return 1;

}

int AvaConexao::DeleteCOMPRA(int idCOMPRA)
{
	InserirLog("Deletar compra ID:"+IntToStr(idCOMPRA));
	if (idCOMPRA < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from compra where COMPRAID = "+IntToStr(idCOMPRA);
	return QExecuteSQL(SQL);
}

COMPRA AvaConexao::FoundCOMPRA(int idCOMPRA)
{
	InserirLog("Procurar informações da compra ID:"+IntToStr(idCOMPRA));
	COMPRA tempCOMPRA;
	if (idCOMPRA > 0)
	{
		AnsiString SQL = "select * from viewcompras where COMPRAID = "+IntToStr(idCOMPRA);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempCOMPRA.SetQuery(FDQuery);
			InserirLog("Compra encotrado");
		}
		else
		InserirLogErro("Compra não encotrado");
		FDQuery->Free();
	}
	return tempCOMPRA;
}

// FORNECEDORE

int AvaConexao::AddFORNECEDORE(FORNECEDORE pFORNECEDORE)
{
	InserirLog("Add novo fornecedor");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into fornecedore (FORNECEDORCONTACTO, FORNECEDORNOME, "
	"FORNECEDORENDERECO) values(:FORNECEDORCONTACTO, :FORNECEDORNOME, :FORNECEDORENDERECO);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pFORNECEDORE.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add fornecedor: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o fornecedor não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Fornecedor add com sucesso");
	return 1;
}
int AvaConexao::ModFORNECEDORE(FORNECEDORE pFORNECEDORE, int idFORNECEDORE)
{
	InserirLog("Alterar informações do fornecedor ID: "+IntToStr(idFORNECEDORE));
	TFDQuery * FDQuery;
	AnsiString SQL;

	SQL = "update fornecedore set FORNECEDORCONTACTO = :FORNECEDORCONTACTO, "
	"FORNECEDORNOME = :FORNECEDORNOME, FORNECEDORENDERECO = :FORNECEDORENDERECO "
	"where FORNECEDORID = "+IntToStr(idFORNECEDORE);
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pFORNECEDORE.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar fornecedor: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o fornecedor não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Fornecedor alterado com sucesso");
	return 1;

}

int AvaConexao::DeleteFORNECEDORE(int idFORNECEDORE)
{
	InserirLog("Deletar fornecedor ID:"+IntToStr(idFORNECEDORE));
	if (idFORNECEDORE < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from fornecedore where FORNECEDORID = "+IntToStr(idFORNECEDORE);
	return QExecuteSQL(SQL);
}

FORNECEDORE AvaConexao::FoundFORNECEDORE(int idFORNECEDORE)
{
	InserirLog("Procurar informações do fornecedor ID:"+IntToStr(idFORNECEDORE));
	FORNECEDORE tempFORNECEDORE;
	if (idFORNECEDORE > 0)
	{
		AnsiString SQL = "select * from fornecedore where FORNECEDORID = "+IntToStr(idFORNECEDORE);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempFORNECEDORE.SetQuery(FDQuery);
			InserirLog("Fornecedor encotrado");
		}
		else
			InserirLogErro("Fornecedor não encotrado");
		FDQuery->Free();
	}
	return tempFORNECEDORE;
}

// PESSOA

int AvaConexao::AddPESSOA(PESSOA pPESSOA)
{
	InserirLog("Add nova pessoa");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into pessoa (PESSOANOME, PESSOADATA, PESSOACONTACTO, "
	"PESSOAMORADA, PESSOABI) values(:PESSOANOME, :PESSOADATA, :PESSOACONTACTO, "
	":PESSOAMORADA, :PESSOABI);";

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pPESSOA.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add pessoa: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o pessoa não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Pessoa add com sucesso");

	AnsiString SQL2 = "select PESSOAID from pessoa;";
	TFDQuery * FDQuery2 = QConsultaSQL(SQL2);
	FDQuery2->Last();
	return FDQuery2->FieldByName("PESSOAID")->AsInteger;
}
int AvaConexao::ModPESSOA(PESSOA pPESSOA, int idPESSOA)
{
	InserirLog("Alterar informações do fornecedor ID: "+IntToStr(idPESSOA));
	TFDQuery * FDQuery;
	AnsiString SQL;

	SQL = "update pessoa set PESSOANOME = :PESSOANOME, PESSOADATA = :PESSOADATA, "
	"PESSOACONTACTO = :PESSOACONTACTO, PESSOAMORADA = :PESSOAMORADA, PESSOABI = :PESSOABI "
	"where PESSOAID = "+IntToStr(idPESSOA);

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pPESSOA.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar fornecedor: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o fornecedor não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Pessoa modificado com sucesso");
	return idPESSOA;

}

int AvaConexao::DeletePESSOA(int idPESSOA)
{
	InserirLog("Deletar pessoa ID:"+IntToStr(idPESSOA));
	if (idPESSOA < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from pessoa where PESSOAID = "+IntToStr(idPESSOA);
	return QExecuteSQL(SQL);
}

PESSOA AvaConexao::FoundPESSOA(int idPESSOA)
{
	InserirLog("Procurar informações do fornecedor ID:"+IntToStr(idPESSOA));
	PESSOA tempPESSOA;
	if (idPESSOA > 0)
	{
		AnsiString SQL = "select * from pessoa where PESSOAID = "+IntToStr(idPESSOA);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempPESSOA.SetQuery(FDQuery);
			InserirLog("Fornecedor encotrado");
		}
		else
			InserirLogErro("Fornecedor não encotrado");
		FDQuery->Free();
	}
	return tempPESSOA;
}

// PREVILEGIO

int AvaConexao::AddPREVILEGIO(PREVILEGIO pPREVILEGIO)
{
	InserirLog("Add nova previlegio");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into previlegio (PREVILEGIONOME) values(:PREVILEGIONOME);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pPREVILEGIO.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add previlegio: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o previlegio não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("categoria add com sucesso");
	return 1;
}
int AvaConexao::ModPREVILEGIO(PREVILEGIO pPREVILEGIO, int idPREVILEGIO)
{
	InserirLog("Alterar informações da categoria ID: "+IntToStr(idPREVILEGIO));
	TFDQuery * FDQuery;
	AnsiString SQL;
	SQL = "update previlegio set PREVILEGIONOME = :PREVILEGIONOME where PREVILEGIOID = "+IntToStr(idPREVILEGIO);
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pPREVILEGIO.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar previlegio: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar a previlegio não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Previlegio modificada com sucesso");
	return 1;

}

int AvaConexao::DeletePREVILEGIO(int idPREVILEGIO)
{
	InserirLog("Deletar categoria ID:"+IntToStr(idPREVILEGIO));
	if (idPREVILEGIO < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from previlegio where PREVILEGIOID = "+IntToStr(idPREVILEGIO);
	return QExecuteSQL(SQL);
}

PREVILEGIO AvaConexao::FoundPREVILEGIO(int idPREVILEGIO)
{
	InserirLog("Procurar informações do previlegio ID:"+IntToStr(idPREVILEGIO));
	PREVILEGIO tempPREVILEGIO;
	if (idPREVILEGIO > 0)
	{
		AnsiString SQL = "select * from previlegio where PREVILEGIOID = "+IntToStr(idPREVILEGIO);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempPREVILEGIO.SetQuery(FDQuery);
			InserirLog("Previlegio encotrado");
		}
		else
			InserirLogErro("Previlegio não encotrado");
		FDQuery->Free();
	}
	return tempPREVILEGIO;
}

// PRODUTO

int AvaConexao::AddPRODUTO(PRODUTO pPRODUTO)
{
	InserirLog("Add novo produto");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into produto (PRODUTONOME, PRODUTOPRECO, CATEGORIAID)"
	" values (:PRODUTONOME, :PRODUTOPRECO, :CATEGORIAID);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pPRODUTO.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add produto: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o produto não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Produto add com sucesso");
	return 1;
}
int AvaConexao::ModPRODUTO(PRODUTO pPRODUTO, int idPRODUTO)
{
	InserirLog("Alterar informações do produto ID: "+IntToStr(idPRODUTO));
	TFDQuery * FDQuery;
	AnsiString SQL;
	SQL = "update produto set PRODUTONOME = :PRODUTONOME, "
	"PRODUTOPRECO = :PRODUTOPRECO, CATEGORIAID = :CATEGORIAID "
	"where PRODUTOID = "+IntToStr(idPRODUTO);

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pPRODUTO.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar produto: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o produto não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Produto compra com sucesso");
	return 1;

}

int AvaConexao::DeletePRODUTO(int idPRODUTO)
{
	InserirLog("Deletar fornecedor ID:"+IntToStr(idPRODUTO));
	if (idPRODUTO < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from produto where PRODUTOID = "+IntToStr(idPRODUTO);
	return QExecuteSQL(SQL);
}

PRODUTO AvaConexao::FoundPRODUTO(int idPRODUTO)
{
	InserirLog("Procurar informações do produto ID:"+IntToStr(idPRODUTO));
	PRODUTO tempPRODUTO;
	if (idPRODUTO > 0)
	{
		AnsiString SQL = "select * from viewprodutos where PRODUTOID = "+IntToStr(idPRODUTO);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempPRODUTO.SetQuery(FDQuery);
			InserirLog("Produto encotrado");
		}
		else
			InserirLogErro("Produto não encotrado");
		FDQuery->Free();
	}
	return tempPRODUTO;
}

// TIPO DE CLIENTE

int AvaConexao::AddTIPOCLIENTE(TIPOCLIENTE pTIPOCLIENTE)
{
	InserirLog("Add novo tipo de cliente");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into tipocliente (TIPOCLIENTENOME) values(:TIPOCLIENTENOME);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pTIPOCLIENTE.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add tipo de cliente: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o tipo de cliente não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Tipo de cliente add com sucesso");
	return 1;
}
int AvaConexao::ModTIPOCLIENTE(TIPOCLIENTE pTIPOCLIENTE, int idTIPOCLIENTE)
{
	InserirLog("Alterar informações do tipo de cliente ID: "+IntToStr(idTIPOCLIENTE));
	TFDQuery * FDQuery;
	AnsiString SQL;
	SQL = "update tipocliente set TIPOCLIENTENOME = :TIPOCLIENTENOME where TIPOCLIENTEID = "+IntToStr(idTIPOCLIENTE);
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pTIPOCLIENTE.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar tipo de cliente: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o tipo de cliente não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("Tipo de cliente modificada com sucesso");
	return 1;

}

int AvaConexao::DeleteTIPOCLIENTE(int idTIPOCLIENTE)
{
	InserirLog("Deletar tipo de cliente ID:"+IntToStr(idTIPOCLIENTE));
	if (idTIPOCLIENTE < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from tipocliente where PREVILEGIOID = "+IntToStr(idTIPOCLIENTE);
	return QExecuteSQL(SQL);
}

TIPOCLIENTE AvaConexao::FoundTIPOCLIENTE(int idTIPOCLIENTE)
{
	InserirLog("Procurar informações do tipo de cliente ID:"+IntToStr(idTIPOCLIENTE));
	TIPOCLIENTE tempTIPOCLIENTE;
	if (idTIPOCLIENTE > 0)
	{
		AnsiString SQL = "select * from tipocliente where TIPOCLIENTEID = "+IntToStr(idTIPOCLIENTE);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempTIPOCLIENTE.SetQuery(FDQuery);
			InserirLog("tipo de cliente encotrado");
		}
		else
			InserirLogErro("tipo de cliente não encotrado");
		FDQuery->Free();
	}
	return tempTIPOCLIENTE;
}


// PESSOA

int AvaConexao::AddUSUARIO(USUARIO pUSUARIO)
{
	InserirLog("Add novo usuario");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into usuario (USUARIONOME, USUARIOSENHA, PREVILEGIOID, USUARIONOMECOMPLETO) "
	"values(:USUARIONOME, :USUARIOSENHA, :PREVILEGIOID, :USUARIONOMECOMPLETO);";
	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pUSUARIO.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add usuario: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o usuario não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("usuario add com sucesso");
	return 1;
}
int AvaConexao::ModUSUARIO(USUARIO pUSUARIO, int idUSUARIO)
{
	InserirLog("Alterar informações do usuario ID: "+IntToStr(idUSUARIO));
	TFDQuery * FDQuery;
	AnsiString SQL;

	SQL = "update usuario set PREVILEGIOID = :PREVILEGIOID, USUARIONOMECOMPLETO = :USUARIONOMECOMPLETO, "
	"USUARIONOME = :USUARIONOME, USUARIOSENHA = :USUARIOSENHA where USUARIOID = "+IntToStr(idUSUARIO);

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pUSUARIO.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar usuario: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o usuario não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("usuario modificado com sucesso");
	return 1;

}

int AvaConexao::DeleteUSUARIO(int idUSUARIO)
{
	InserirLog("Deletar usuario ID:"+IntToStr(idUSUARIO));
	if (idUSUARIO < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from usuario where USUARIOID = "+IntToStr(idUSUARIO);
	return QExecuteSQL(SQL);
}

USUARIO AvaConexao::FoundUSUARIO(int idUSUARIO)
{
	InserirLog("Procurar informações do usuario ID:"+IntToStr(idUSUARIO));
	USUARIO tempUSUARIO;
	if (idUSUARIO > 0)
	{
		AnsiString SQL = "select * from viewusuarios where USUARIOID = "+IntToStr(idUSUARIO);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempUSUARIO.SetQuery(FDQuery);
			InserirLog("usuario encotrado");
		}
		else
			InserirLogErro("usuario não encotrado");
		FDQuery->Free();
	}
	return tempUSUARIO;
}

// VENDAS

int AvaConexao::AddVENDA(VENDA pVENDA)
{
	InserirLog("Add nova venda");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into venda (PRODUTOID, CLIENTEID, USUARIOID, "
	"VENDAQUANTIDADE, VENDADATA) values(:PRODUTOID, :CLIENTEID, :USUARIOID, "
	":VENDAQUANTIDADE, :VENDADATA);";

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pVENDA.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add venda: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add a venda não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("venda add com sucesso");
	return 1;
}
int AvaConexao::ModVENDA(VENDA pVENDA, int idVENDA)
{
	InserirLog("Alterar informações do venda ID: "+IntToStr(idVENDA));
	TFDQuery * FDQuery;
	AnsiString SQL;

	SQL = "update venda set PRODUTOID = :PRODUTOID, CLIENTEID = :CLIENTEID, "
	"USUARIOID = :USUARIOID, VENDAQUANTIDADE = :VENDAQUANTIDADE, VENDADATA = "
	":VENDADATA, where VENDAID = "+IntToStr(idVENDA);


	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pVENDA.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar venda: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o venda não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("venda modificado com sucesso");
	return 1;

}

int AvaConexao::DeleteVENDA(int idVENDA)
{
	InserirLog("Deletar venda ID:"+IntToStr(idVENDA));
	if (idVENDA < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from venda where VENDAID = "+IntToStr(idVENDA);
	return QExecuteSQL(SQL);
}

VENDA AvaConexao::FoundVENDA(int idVENDA)
{
	InserirLog("Procurar informações do venda ID:"+IntToStr(idVENDA));
	VENDA tempVENDA;
	if (idVENDA > 0)
	{
		AnsiString SQL = "select * from viewvendas where VENDAID = "+IntToStr(idVENDA);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempVENDA.SetQuery(FDQuery);
			InserirLog("usuario encotrado");
		}
		else
			InserirLogErro("venda não encotrado");
		FDQuery->Free();
	}
	return tempVENDA;
}

	// STOCK
int AvaConexao::AddSTOCK(STOCK pSTOCK)
{
	InserirLog("Add nova stock");
	TFDQuery * FDQuery;
	AnsiString SQL = "insert into stock (PRODUTOID, STOCKQUANTIA, STOCKUPDATE) "
	"values(:PRODUTOID, :STOCKQUANTIA, :STOCKUPDATE);";

	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pSTOCK.GetQuery(FDQuery);

	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao add stock: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para add o stock não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("stock add com sucesso");
	return 1;
}

int AvaConexao::ModSTOCK(STOCK pSTOCK, int idSTOCK)
{
	InserirLog("Alterar informações do stock ID: "+IntToStr(idSTOCK));
	TFDQuery * FDQuery;
	AnsiString SQL;

	SQL = "update stock set PRODUTOID = :PRODUTOID, STOCKQUANTIA = :STOCKQUANTIA, "
	"STOCKUPDATE = :STOCKUPDATE where STOCKID = "+IntToStr(idSTOCK);


	try
	{
		FDQuery = new TFDQuery(NULL);
		FDQuery->SQL->Add(SQL);
		FDQuery = pSTOCK.GetQuery(FDQuery);
	}
	catch (EDatabaseError &e)
	{
		InserirLogErro("Problema ao modificar stock: "+e.Message);
		return 0;
	}

	if (QExecuteSQL(FDQuery) == NULL)
	{
		InserirLogErro("A query para modificar o stock não foi executada");
		return 0;
	}

	FDQuery->Free();
	InserirLog("stock modificado com sucesso");
	return 1;

}
int AvaConexao::DeleteSTOCK(int idSTOCK)
{
	InserirLog("Deletar stock ID:"+IntToStr(idSTOCK));
	if (idSTOCK < 1)
	{
		return 0;
	}
	AnsiString SQL = "delete from stock where STOCKID = "+IntToStr(idSTOCK);
	return QExecuteSQL(SQL);
}

STOCK AvaConexao::FoundSTOCK(int idProduto)
{
	InserirLog("Procurar informações do stock ID: "+IntToStr(idProduto));
	STOCK tempSTOCK;
	if (idProduto > 0)
	{
		AnsiString SQL = "select * from viewstock where PRODUTOID = "+IntToStr(idProduto);
		TFDQuery * FDQuery = QConsultaSQL(SQL);
		if(FDQuery != NULL)
		{
			tempSTOCK.SetQuery(FDQuery);
			InserirLog("stock encotrado");
		}
		else
			InserirLogErro("stock não encotrado");
		FDQuery->Free();
	}
	return tempSTOCK;
}

//outors metodos

int AvaConexao::AddVENDAKILAP(VENDA pVENDA)
{

	CLIENTE Cliente = FoundCliente(pVENDA.getCLIENTEID());
	PRODUTO Produto = FoundPRODUTO(pVENDA.getPRODUTOID());
	Cliente.setCLIENTECONTA(Cliente.getCLIENTECONTA()+ Produto.getPRODUTOPRECO());
	if (!ModCliente(Cliente,Cliente.getCLIENTEID()))
		return 0;
	return AddVENDA(pVENDA);
}


void AvaConexao::SetUsuarioActual(USUARIO pUSUARIO)
{
	UserLogin = pUSUARIO;
}
USUARIO AvaConexao::GetUsuarioActual()
{
	return UserLogin;
}
