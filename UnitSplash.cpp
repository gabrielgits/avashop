//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitSplash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormSplash *FormSplash;
//---------------------------------------------------------------------------
__fastcall TFormSplash::TFormSplash(TComponent* Owner)
	: TForm(Owner)
{
	i = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormSplash::Timer1Timer(TObject *Sender)
{
	if (i > 10)
	{
		Timer1->Enabled = false;

		AniIndicator1->Enabled = false;
		Close();
		return;
	}
	//ProgressBar1->StepIt();
	i++;
}
//---------------------------------------------------------------------------
