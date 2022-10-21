//---------------------------------------------------------------------------

#ifndef UnitAvashopDBH
#define UnitAvashopDBH
#include "VENDA.h"
#include "chandsfilelog.h"
#include "UnitDBInfo.h"
#include "COMPRA.h"
#include "STOCK.h"

//---------------------------------------------------------------------------

class AvaConexao
{
private:
	TFDConnection *FDConexao;
	USUARIO UserLogin;
	ArchiveLog Log;
	TFDConnection *ConectarDB();

public:
	// METODOS BASE
	AvaConexao();
	~AvaConexao();


	// METODOS DE CONEXAO
	TFDConnection *ConectarDB(AvaInfoDB PInfoConexao);
	void Disconect();
	TFDQuery *QConsultaSQL(AnsiString SQL);
	TFDQuery *QExecuteSQL(TFDQuery *SQLQuery1);
	int QExecuteSQL(AnsiString SQL);
	TFDConnection *SetInfoDB(AvaInfoDB PInfoConexao);
	int TestaDB(AvaInfoDB PInfoConexao);
	TFDConnection *GetFDConexao();

	// Arquivo de Log
	void InserirLog(AnsiString Ex);
	void InserirLogErro(AnsiString Ex);

	// CATEGORIA
	int AddCategoria(CATEGORIA pCATEGORIAS);
	int ModCategoria(CATEGORIA pCATEGORIA, int idCATEGORIA);
	int DeleteCategoria(int idCATEGORIA);
	CATEGORIA FoundCategoria(int idCATEGORIA);

	// CLIENTE
	int AddCliente(CLIENTE pCLIENTE, PESSOA pPESSOA);
	int ModCliente(CLIENTE pCLIENTE, int idCLIENTE);
	int DeleteCliente(int idCLIENTE);
	CLIENTE FoundCliente(int idCLIENTE);

	// COMPRA
	int AddCOMPRA(COMPRA pCOMPRA);
	int ModCOMPRA(COMPRA pCOMPRA, int idCOMPRA);
	int DeleteCOMPRA(int idCOMPRA);
	COMPRA FoundCOMPRA(int idCOMPRA);

	// FORNECEDORE
	int AddFORNECEDORE(FORNECEDORE pFORNECEDORE);
	int ModFORNECEDORE(FORNECEDORE pFORNECEDORE, int idFORNECEDORE);
	int DeleteFORNECEDORE(int idFORNECEDORE);
	FORNECEDORE FoundFORNECEDORE(int idFORNECEDORE);

	// PESSOA
	int AddPESSOA(PESSOA pPESSOA);
	int ModPESSOA(PESSOA pPESSOA, int idPESSOA);
	int DeletePESSOA(int idPESSOA);
	PESSOA FoundPESSOA(int idPESSOA);

	// PREVILEGIO
	int AddPREVILEGIO(PREVILEGIO pPREVILEGIO);
	int ModPREVILEGIO(PREVILEGIO pPREVILEGIO, int idPREVILEGIO);
	int DeletePREVILEGIO(int idPREVILEGIO);
	PREVILEGIO FoundPREVILEGIO(int idPREVILEGIO);

	// PRODUTO
	int AddPRODUTO(PRODUTO pPRODUTO);
	int ModPRODUTO(PRODUTO pPRODUTO, int idPRODUTO);
	int DeletePRODUTO(int idPRODUTO);
	PRODUTO FoundPRODUTO(int idPRODUTO);

	// TIPOCLIENTE
	int AddTIPOCLIENTE(TIPOCLIENTE pTIPOCLIENTE);
	int ModTIPOCLIENTE(TIPOCLIENTE pTIPOCLIENTE, int idTIPOCLIENTE);
	int DeleteTIPOCLIENTE(int idTIPOCLIENTE);
	TIPOCLIENTE FoundTIPOCLIENTE(int idTIPOCLIENTE);

	// USUARIO
	int AddUSUARIO(USUARIO pUSUARIO);
	int ModUSUARIO(USUARIO pUSUARIO, int idUSUARIO);
	int DeleteUSUARIO(int idUSUARIO);
	USUARIO FoundUSUARIO(int idUSUARIO);

	// VENDA
	int AddVENDA(VENDA pVENDA);
	int ModVENDA(VENDA pVENDA, int idVENDA);
	int DeleteVENDA(int idVENDA);
	VENDA FoundVENDA(int idVENDA);
	int AddVENDAKILAP(VENDA pVENDA);

	// STOCK
	int AddSTOCK(STOCK pSTOCK);
	int ModSTOCK(STOCK pSTOCK, int idSTOCK);
	int DeleteSTOCK(int idSTOCK);
	STOCK FoundSTOCK(int idSTOCK);

	// OUTROS METODOS
	void SetUsuarioActual(USUARIO pUSUARIO);
	USUARIO GetUsuarioActual();
};

#endif


