//---------------------------------------------------------------------------

#ifndef UnitSplashH
#define UnitSplashH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFormSplash : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TAniIndicator *AniIndicator1;
	TLabel *Label1;
	TText *Text1;
	TTimer *Timer1;
	TText *Text3;
	TLabel *Label2;
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	int i;
public:		// User declarations
	__fastcall TFormSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSplash *FormSplash;
//---------------------------------------------------------------------------
#endif
