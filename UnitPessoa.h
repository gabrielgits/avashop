//---------------------------------------------------------------------------

#ifndef UnitPessoaH
#define UnitPessoaH
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
#include <FMX.DateTimeCtrls.hpp>
#include "PESSOA.h"
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormPessoa : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TText *Text1;
	TPanel *Panel3;
	TEdit *Edit2;
	TLabel *Label1;
	TButton *Cancelar;
	TButton *Salvar;
	TLabel *Label2;
	TEdit *Edit3;
	TLabel *Label3;
	TEdit *Edit4;
	TLabel *Label4;
	TEdit *Edit5;
	TLabel *Label5;
	TDateEdit *DateEdit1;
	TImage *Image1;
	TButton *Button1;
	TButton *Button2;
	TOpenDialog *OpenDialog1;
	void __fastcall CancelarClick(TObject *Sender);
	void __fastcall SalvarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	   PESSOA Alterar;
public:		// User declarations
void MostrarForm();
	__fastcall TFormPessoa(TComponent* Owner);
	PESSOA MostrarForm(PESSOA IdPessoa);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPessoa *FormPessoa;
//---------------------------------------------------------------------------
#endif
