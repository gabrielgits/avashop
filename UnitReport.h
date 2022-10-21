//---------------------------------------------------------------------------

#ifndef UnitReportH
#define UnitReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "FMX.frxClass.hpp"
#include "FMX.frxDBSet.hpp"
#include "FMX.frxExportPDF.hpp"
#include "FMX.frxExportRTF.hpp"
//---------------------------------------------------------------------------
class TDataModuleReport : public TDataModule
{
__published:	// IDE-managed Components
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDatasetVendaInvetAno;
	TfrxDBDataset *frxDBDatasetVendaInvetMes;
	TfrxDBDataset *frxDBDatasetVendaInvetDia;
	TfrxDBDataset *frxDBDatasetFaturaVenda;
	TfrxPDFExport *frxPDFExport1;
	TfrxRTFExport *frxRTFExport1;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModuleReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleReport *DataModuleReport;
//---------------------------------------------------------------------------
#endif
