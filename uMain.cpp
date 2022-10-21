//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "uMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TCameraComponentForm *CameraComponentForm;
//---------------------------------------------------------------------------
__fastcall TCameraComponentForm::TCameraComponentForm(TComponent* Owner)
	: TForm(Owner)
{

}
void TCameraComponentForm::MostrarForm()
{
	FillResolutions();
	CameraComponent->Active = true;
	ShowModal();
}


//---------------------------------------------------------------------------
void __fastcall TCameraComponentForm::btnStartCameraClick(TObject *Sender)
{

	CameraComponent->Active = false;
	AnsiString image;
	if (SaveDialog1->Execute())
	{
		// First, check if the file exists.
		if (FileExists(SaveDialog1->FileName))
		{
			// If it exists, throw an exception.
			CameraComponent->Active = true;
			throw(Exception("Arquivo ja exitente. Não foi possivel subscrever."));

		}
		else
		{
			HWND__ * handle;
			image = SaveDialog1->FileName+".png";
			imgCameraView->Bitmap->SaveToFile(image);
			UnicodeString cmd = "open";
			UnicodeString cmd2 = image;
			ShellExecute(handle,cmd.w_str(),cmd2.w_str(),NULL,NULL,0);
		}
	}
	CameraComponent->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TCameraComponentForm::GetImage()
{
	CameraComponent->SampleBufferToBitmap(imgCameraView->Bitmap, true);
}

//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::FormCreate(TObject *Sender)
{
    CameraComponent->Active = false;
	//Label1->Text = "Avasoft Copyright © 2017, Todos os Direitos Reservado\nwww.avasoft.ga";
}
//---------------------------------------------------------------------------

void TCameraComponentForm::FillResolutions()
{
	System::DynamicArray<TVideoCaptureSetting> LSettings = CameraComponent->AvailableCaptureSettings;
	cbResolutions->Clear();
	for (int i = LSettings.Low; i <= LSettings.High; i++)
		cbResolutions->Items->Add(UnicodeString(LSettings[i].Width) + " x " + LSettings[i].Height + " x " + LSettings[i].FrameRate);
	cbResolutions->ItemIndex = 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void TCameraComponentForm::ChangeQuality(const TVideoCaptureQuality ANewQuality)
{
	bool LActive = CameraComponent->Active;
	CameraComponent->Active = False;
	CameraComponent->Quality = ANewQuality;
	CameraComponent->Active = LActive;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::cbResolutionsChange(TObject *Sender)
{
	int LIndex;
	DynamicArray<TVideoCaptureSetting> LSettings;
	bool LActive = CameraComponent->Active;
	CameraComponent->Active = False;
	LIndex = cbResolutions->ItemIndex;
	LSettings = CameraComponent->AvailableCaptureSettings;
	if (LSettings.Length > 0)
		CameraComponent->CaptureSetting = LSettings[LIndex];
	CameraComponent->Active = LActive;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::CameraComponentSampleBufferReady(TObject *Sender, const TMediaTime ATime)
{
	TThread::Synchronize(TThread::CurrentThread, GetImage);
}
//---------------------------------------------------------------------------



void __fastcall TCameraComponentForm::Button1Click(TObject *Sender)
{
	CameraComponent->Active = false;
	Close();
}
//---------------------------------------------------------------------------

