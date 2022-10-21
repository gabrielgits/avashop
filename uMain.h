//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#ifndef uMainH
#define uMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Media.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TCameraComponentForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btnStartCamera;
	TLabel *lblCameraResolution;
	TComboBox *cbResolutions;
	TImage *imgCameraView;
	TCameraComponent *CameraComponent;
	TRectangle *Rectangle1;
	TButton *Button1;
	TText *Text1;
	TLabel *Label1;
	TSaveDialog *SaveDialog1;
	TLayout *Layout1;
	void __fastcall btnStartCameraClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbResolutionsChange(TObject *Sender);
	void __fastcall CameraComponentSampleBufferReady(TObject *Sender, const TMediaTime ATime);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	void __fastcall GetImage();
	void FillResolutions();

	void ChangeQuality(const TVideoCaptureQuality ANewQuality);
public:		// User declarations
	__fastcall TCameraComponentForm(TComponent* Owner);
	void MostrarForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TCameraComponentForm *CameraComponentForm;
//---------------------------------------------------------------------------
#endif
