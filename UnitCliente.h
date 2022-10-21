//---------------------------------------------------------------------------

#ifndef UnitClienteH
#define UnitClienteH
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
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <FMX.ListBox.hpp>
#include "CLIENTE.h"
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TFormCliente : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TButton *ButtonTipoCliente;
	TButton *ButtonAlterar;
	TButton *ButtonEliminar;
	TPanel *Panel3;
	TEdit *EditConta;
	TLabel *Label1;
	TButton *Cancelar;
	TButton *Salvar;
	TListView *ListView1;
	TButton *ButtonAtualizar;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TBindSourceDB *BindSourceDB2;
	TEdit *Edit1;
	TMemo *Memo1;
	TLabel *Label4;
	TRectangle *Rectangle1;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit2;
	TLabel *Label8;
	TLinkListControlToField *LinkListControlToField1;
	TLinkListControlToField *LinkListControlToField2;
	TRectangle *Rectangle2;
	TText *Text1;
	TButton *Button2;
	void __fastcall ButtonAlterarClick(TObject *Sender);
	void __fastcall ButtonEliminarClick(TObject *Sender);
	void __fastcall ButtonAtualizarClick(TObject *Sender);
	void __fastcall CancelarClick(TObject *Sender);
	void __fastcall SalvarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonTipoClienteClick(TObject *Sender);
	void __fastcall ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ListView1DblClick(TObject *Sender);

private:	// User declarations
	   int IdCliente;
	   int Alterar;
	   int IPessoa;
	   PESSOA pPESSOA;
public:		// User declarations
CLIENTE MostrarForm();

	__fastcall TFormCliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCliente *FormCliente;
//---------------------------------------------------------------------------
#endif
