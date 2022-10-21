//---------------------------------------------------------------------------

#ifndef UnitCategoriaH
#define UnitCategoriaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include "UnitDB.h"
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <FMX.Graphics.hpp>




//---------------------------------------------------------------------------
class TFormCategoria : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TButton *ButtonNome;
	TButton *ButtonAlterar;
	TButton *ButtonEliminar;
	TPanel *Panel3;
	TEdit *Edit2;
	TLabel *Label1;
	TButton *Cancelar;
	TButton *Salvar;
	TListView *ListView1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkFillControlToField *LinkFillControlToField1;
	TButton *Button1;
	TRectangle *Rectangle1;
	TText *Text1;
	TBrushObject *Brush1;
	TBrushObject *Brush2;
	TBrushObject *Brush3;
	void __fastcall SalvarClick(TObject *Sender);
	void __fastcall ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall ButtonEliminarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonAlterarClick(TObject *Sender);
	void __fastcall ButtonNomeClick(TObject *Sender);
	void __fastcall CancelarClick(TObject *Sender);

private:	// User declarations
	int IdCategoria;
	int Alterar;
public:		// User declarations
	void MostrarForm();
	__fastcall TFormCategoria(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCategoria *FormCategoria;
//---------------------------------------------------------------------------
#endif
