//---------------------------------------------------------------------------

#ifndef UnitLigacaoH
#define UnitLigacaoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "UnitDB.h"
//---------------------------------------------------------------------------
class TFormLigacao : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TText *Text1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	AvaInfoDB InfoDB;
public:		// User declarations
	__fastcall TFormLigacao(TComponent* Owner);
	int IniciarConexao();
	void __fastcall MostrarLigacao();
	CriarConexao();
	AplicarConexao();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLigacao *FormLigacao;
//---------------------------------------------------------------------------
#endif
