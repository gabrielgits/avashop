//---------------------------------------------------------------------------

#ifndef UnitProdutoH
#define UnitProdutoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
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
#include <FMX.ListBox.hpp>
#include "PRODUTO.h"

//---------------------------------------------------------------------------
class TFormProduto : public TForm
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
	TLabel *Label2;
	TEdit *Edit3;
	TLabel *Label3;
	TListView *ListView1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkListControlToField *LinkListControlToField1;
	TComboBox *ComboBox1;
	TButton *Button1;
	TBindSourceDB *BindSourceDB2;
	TLinkListControlToField *LinkListControlToField2;
	TRectangle *Rectangle1;
	TText *Text1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonNomeClick(TObject *Sender);
	void __fastcall ButtonAlterarClick(TObject *Sender);
	void __fastcall ButtonEliminarClick(TObject *Sender);
	void __fastcall SalvarClick(TObject *Sender);
	void __fastcall CancelarClick(TObject *Sender);
	void __fastcall ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ListView1DblClick(TObject *Sender);

private:	// User declarations
	int IdProduto;
	int Alterar;
public:		// User declarations
	PRODUTO MostrarForm();
	__fastcall TFormProduto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProduto *FormProduto;
//---------------------------------------------------------------------------
#endif
