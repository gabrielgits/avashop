//---------------------------------------------------------------------------

#ifndef UnitVendaH
#define UnitVendaH
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
#include <Data.Bind.Components.hpp>
#include <Data.Bind.Controls.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <Fmx.Bind.Navigator.hpp>
#include <System.Bindings.Outputs.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TFormVenda : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TText *Text1;
	TPanel *Panel2;
	TButton *ButtonNome;
	TButton *ButtonAlterar;
	TButton *ButtonImprimir;
	TEdit *Edit1;
	TButton *Button1;
	TEdit *Edit2;
	TButton *Button2;
	TButton *Button3;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TLayout *Layout1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EditQuant;
	TBindSourceDB *BindSourceDB1;
	TStringGrid *StringGridBindSourceDB1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TBindingsList *BindingsList1;
	TButton *Button4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ButtonNomeClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ButtonImprimirClick(TObject *Sender);
	void __fastcall ButtonAlterarClick(TObject *Sender);
private:	// User declarations
	int IdProduto;
	int IdCliente;
public:		// User declarations
	void MostrarForm();
	__fastcall TFormVenda(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVenda *FormVenda;
//---------------------------------------------------------------------------
#endif
