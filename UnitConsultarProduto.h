//---------------------------------------------------------------------------

#ifndef UnitConsultarProdutoH
#define UnitConsultarProdutoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TFormProcurarProdutos : public TForm
{
__published:	// IDE-managed Components
	TBindSourceDB *BindSourceDB1;
	TStringGrid *StringGridBindSourceDB1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TBindingsList *BindingsList1;
	TRectangle *Rectangle1;
	TLayout *Layout1;
	TEdit *Edit1;
	TButton *Button1;
	TText *Text1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormProcurarProdutos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProcurarProdutos *FormProcurarProdutos;
//---------------------------------------------------------------------------
#endif
