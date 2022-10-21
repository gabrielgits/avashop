//---------------------------------------------------------------------------

#ifndef UnitGestaoVendaH
#define UnitGestaoVendaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.Controls.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <Fmx.Bind.Navigator.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
//---------------------------------------------------------------------------
class TFormGestaoVenda : public TForm
{
__published:	// IDE-managed Components
	TBindSourceDB *BindSourceDB1;
	TStringGrid *StringGridBindSourceDB1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TBindNavigator *NavigatorBindSourceDB1;
	TBindingsList *BindingsList1;
	TDateEdit *DateEdit1;
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label2;
	TButton *Button3;
	TLabel *Label3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TLinkFillControlToProperty *LinkFillControlToPropertyTagString;
	TGroupBox *GroupBox1;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGestaoVenda(TComponent* Owner);
	void MostrarForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGestaoVenda *FormGestaoVenda;
//---------------------------------------------------------------------------
#endif
