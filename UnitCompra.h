//---------------------------------------------------------------------------

#ifndef UnitCompraH
#define UnitCompraH
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
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TFormCompra : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TButton *ButtonNome;
	TButton *ButtonAlterar;
	TButton *ButtonEliminar;
	TPanel *Panel3;
	TButton *Cancelar;
	TButton *Salvar;
	TLabel *Quantidade;
	TEdit *Edit2;
	TLabel *Label3;
	TComboBox *ComboBox2;
	TListView *ListView1;
	TButton *Button1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TRectangle *Rectangle1;
	TMemo *Memo1;
	TLabel *Label8;
	TBindSourceDB *BindSourceDB2;
	TLinkListControlToField *LinkListControlToField2;
	TLinkListControlToField *LinkListControlToField1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TBindSourceDB *BindSourceDB3;
	TLinkListControlToField *LinkListControlToField3;
	TRectangle *Rectangle2;
	TText *Text1;
	TEdit *Edit1;
	TLabel *Label2;
	void __fastcall ButtonNomeClick(TObject *Sender);
	void __fastcall ButtonAlterarClick(TObject *Sender);
	void __fastcall ButtonEliminarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CancelarClick(TObject *Sender);
	void __fastcall SalvarClick(TObject *Sender);
	void __fastcall ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall Panel3Click(TObject *Sender);

private:	// User declarations
	   int IdCompra;
	   int Alterar;
public:		// User declarations
	__fastcall TFormCompra(TComponent* Owner);
	void __fastcall MostrarForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCompra *FormCompra;
//---------------------------------------------------------------------------
#endif
