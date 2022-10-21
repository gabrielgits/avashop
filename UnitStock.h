//---------------------------------------------------------------------------

#ifndef UnitStockH
#define UnitStockH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
//---------------------------------------------------------------------------
class TFormStock : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TButton *ButtonNome;
	TButton *ButtonAlterar;
	TButton *ButtonEliminar;
	TListView *ListView1;
	TRectangle *Rectangle1;
	TText *Text1;
	TRectangle *Rectangle2;
	TMemo *Memo1;
	TLabel *Label8;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkFillControlToField *LinkFillControlToField1;
	TButton *Button1;
	void __fastcall ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall ButtonEliminarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonNomeClick(TObject *Sender);
	void __fastcall ButtonAlterarClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	   int IdProduto;
	   int IdStock;
void MostrarForm();
	__fastcall TFormStock(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStock *FormStock;
//---------------------------------------------------------------------------
#endif
