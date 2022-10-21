//---------------------------------------------------------------------------

#ifndef UnitBuscaProdutoH
#define UnitBuscaProdutoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
//---------------------------------------------------------------------------
class TFormBuscaProduto : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle2;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TPanel *Panel1;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label2;
	TPanel *Panel2;
	TBindSourceDB *BindSourceDB1;
	TStringGrid *StringGridBindSourceDB1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TBindingsList *BindingsList1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall StringGridBindSourceDB1SelectCell(TObject *Sender, const int ACol,
          const int ARow, bool &CanSelect);

private:	// User declarations
	int IdProduto;
public:		// User declarations
	__fastcall TFormBuscaProduto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBuscaProduto *FormBuscaProduto;
//---------------------------------------------------------------------------
#endif
