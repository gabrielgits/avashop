//---------------------------------------------------------------------------

#ifndef UnitLoginH
#define UnitLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "USUARIO.h"
//---------------------------------------------------------------------------
class TFormLogin : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TButton *Button1;
	TLayout *Layout1;
	TButton *Button2;
	TEdit *EditUserName;
	TLabel *Label1;
	TEdit *EditSenha;
	TLabel *Label2;
	TButton *Button3;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	USUARIO UserLogin;
public:		// User declarations
	__fastcall TFormLogin(TComponent* Owner);
	 USUARIO __fastcall MostrarLogin();
	 int ErroLogin;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogin *FormLogin;
//---------------------------------------------------------------------------
#endif
