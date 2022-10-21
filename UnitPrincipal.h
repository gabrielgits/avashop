//---------------------------------------------------------------------------

#ifndef UnitPrincipalH
#define UnitPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "UnitDB.h"
#include <FMX.Menus.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Calendar.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TFormPrincipal : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *MenuItem1;
	TMenuItem *MenuItem2;
	TMenuItem *MenuItem3;
	TMenuItem *MenuItem4;
	TMenuItem *MenuItem5;
	TStyleBook *StyleBook1;
	TCalendar *Calendar1;
	TMenuItem *MenuItem6;
	TMenuItem *MenuItem7;
	TMenuItem *MenuItem8;
	TMenuItem *MenuItem9;
	TMenuItem *MenuItem10;
	TMenuItem *MenuItem11;
	TMenuItem *MenuItem12;
	TMenuItem *MenuItem13;
	TMenuItem *MenuItem14;
	TMenuItem *MenuItem15;
	TMenuItem *MenuItem17;
	TMenuItem *MenuItem18;
	TMenuItem *MenuItem19;
	TMenuItem *MenuItem20;
	TMenuItem *MenuItem21;
	TMenuItem *MenuItem22;
	TMenuItem *MenuItem23;
	TMenuItem *MenuItem24;
	TMenuItem *MenuItem25;
	TMenuItem *MenuItem26;
	TMenuItem *MenuItem27;
	TMenuItem *MenuItem28;
	TMenuItem *MenuItem29;
	TMenuItem *MenuItem30;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TStatusBar *StatusBar1;
	TMenuItem *MenuItem16;
	TMemo *Memo1;
	TMenuItem *MenuItem31;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MenuItem29Click(TObject *Sender);
	void __fastcall MenuItem30Click(TObject *Sender);
	void __fastcall MenuItem7Click(TObject *Sender);
	void __fastcall MenuItem8Click(TObject *Sender);
	void __fastcall MenuItem9Click(TObject *Sender);
	void __fastcall MenuItem10Click(TObject *Sender);
	void __fastcall MenuItem11Click(TObject *Sender);
	void __fastcall MenuItem12Click(TObject *Sender);
	void __fastcall MenuItem13Click(TObject *Sender);
	void __fastcall MenuItem14Click(TObject *Sender);
	void __fastcall MenuItem17Click(TObject *Sender);
	void __fastcall MenuItem18Click(TObject *Sender);
	void __fastcall MenuItem20Click(TObject *Sender);
	void __fastcall MenuItem19Click(TObject *Sender);
	void __fastcall MenuItem22Click(TObject *Sender);
	void __fastcall MenuItem24Click(TObject *Sender);
	void __fastcall MenuItem25Click(TObject *Sender);
	void __fastcall MenuItem23Click(TObject *Sender);
	void __fastcall MenuItem16Click(TObject *Sender);
	void __fastcall MenuItem31Click(TObject *Sender);
private:	// User declarations
	void __fastcall FecharMenu();
	void __fastcall TerminarSessao();
	void RegitroApp();

public:		// User declarations
	__fastcall TFormPrincipal(TComponent* Owner);
	void __fastcall AcessoMenu(int Previlegio);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
#endif
