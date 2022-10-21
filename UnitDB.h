//---------------------------------------------------------------------------

#ifndef UnitDBH
#define UnitDBH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include "UnitAvashopDB.h"
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include "AvaAppInfo.h"
#include "AvaLicence.h"
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Comp.UI.hpp>
//---------------------------------------------------------------------------
class TDataModuleDB : public TDataModule
{
__published:	// IDE-managed Components
	TFDQuery *FDQueryCategorias;
	TFDConnection *FDConnection1;
	TFDQuery *FDQueryCliente;
	TFDQuery *FDQueryCompra;
	TFDQuery *FDQueryFornecedor;
	TFDQuery *FDQueryPrevilegio;
	TFDQuery *FDQueryTipoCliente;
	TFDQuery *FDQueryUsuario;
	TFDAutoIncField *FDQueryTipoClienteTIPOCLIENTEID;
	TStringField *FDQueryTipoClienteTIPOCLIENTENOME;
	TFDQuery *FDQueryProduto;
	TFDQuery *FDQueryStock;
	TFDQuery *FDQueryVenda;
	TFDQuery *FDQueryVendaTemp;
	TFDQuery *FDQueryVendaInvetAno;
	TFDQuery *FDQueryVendaInvtDia;
	TFDQuery *FDQueryVendaInvtMes;
	TFDQuery *FDQueryProcurarProduto;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TFDPhysSQLiteDriverLink *FDPhysSQLiteDriverLink1;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	AvaConexao Conexao;
	__fastcall TDataModuleDB(TComponent* Owner);

	int ConectarDB(AvaInfoDB DB);
	int IniciarQuery();
	int DesconectarDB();
		//int MessageAlerta(int tipo);

	AvaAppInfo AppInfo;
	AvaLicence Licence;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleDB *DataModuleDB;
//---------------------------------------------------------------------------
#endif
