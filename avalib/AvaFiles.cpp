/***********************************************************************
 * Module:  AvaFiles.cpp
 * Author:  Nick is Back
 * Modified: 7 de fevereiro de 2017 09:20:23
 * Purpose: Implementation of the class AvaFiles
 ***********************************************************************/
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "AvaFiles.h"

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::getLicence()
// Purpose:    Implementation of AvaFiles::getLicence()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaFiles::getLicence(void)
{
   return Licence;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::setLicence(texto newLicence)
// Purpose:    Implementation of AvaFiles::setLicence()
// Parameters:
// - newLicence
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaFiles::setLicence(texto newLicence)
{
   Licence = newLicence;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::getFotopadrao()
// Purpose:    Implementation of AvaFiles::getFotopadrao()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaFiles::getFotopadrao(void)
{
   return fotopadrao;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::setFotopadrao(texto newFotopadrao)
// Purpose:    Implementation of AvaFiles::setFotopadrao()
// Parameters:
// - newFotopadrao
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaFiles::setFotopadrao(texto newFotopadrao)
{
   fotopadrao = newFotopadrao;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::getAvaconnect()
// Purpose:    Implementation of AvaFiles::getAvaconnect()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaFiles::getAvaconnect(void)
{
   return Avaconnect;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::setAvaconnect(texto newAvaconnect)
// Purpose:    Implementation of AvaFiles::setAvaconnect()
// Parameters:
// - newAvaconnect
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaFiles::setAvaconnect(texto newAvaconnect)
{
   Avaconnect = newAvaconnect;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::getAvacam()
// Purpose:    Implementation of AvaFiles::getAvacam()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaFiles::getAvacam(void)
{
   return Avacam;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::setAvacam(texto newAvacam)
// Purpose:    Implementation of AvaFiles::setAvacam()
// Parameters:
// - newAvacam
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaFiles::setAvacam(texto newAvacam)
{
   Avacam = newAvacam;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::AvaFiles()
// Purpose:    Implementation of AvaFiles::AvaFiles()
// Return:     
////////////////////////////////////////////////////////////////////////

AvaFiles::AvaFiles()
{
   Licence = "licence.txt";
   fotopadrao = "fotopadrao.png";
   Avaconnect = "avaconnect.exe";
   Avacam = "avacam.exe";
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::~AvaFiles()
// Purpose:    Implementation of AvaFiles::~AvaFiles()
// Return:     
////////////////////////////////////////////////////////////////////////

AvaFiles::~AvaFiles()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaFiles::AvaFiles(const AvaFiles& oldAvaFiles)
// Purpose:    Implementation of AvaFiles::AvaFiles()
// Parameters:
// - oldAvaFiles
// Return:     
////////////////////////////////////////////////////////////////////////

AvaFiles::AvaFiles(const AvaFiles& oldAvaFiles)
{
   Licence = oldAvaFiles.Licence;
   fotopadrao = oldAvaFiles.fotopadrao;
   Avaconnect = oldAvaFiles.Avaconnect;
   Avacam = oldAvaFiles.Avacam;
}

int AvaFiles::ReadRegistry()
{
	TRegistry* reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;;
	reg->Access = KEY_READ;

	if(!reg->OpenKey("Software\\Avasoft\\Avaschool\\Info\\Files\\", false))
	{
		return 0;
	}
	Licence = reg->ReadString("Licence");
	fotopadrao = reg->ReadString("fotopadrao");
	Avaconnect = reg->ReadString("Avaconnect");
	Avacam = reg->ReadString("Avacam");
	reg->CloseKey();
	reg->Free();
	return 1;
}
int AvaFiles::WriteRegistry()
{
	TRegistry* reg = new TRegistry(KEY_WRITE);
	reg->RootKey = HKEY_CURRENT_USER;;
	reg->Access = KEY_WRITE;

	if(!reg->OpenKey("Software\\Avasoft\\Avaschool\\Info\\FIles\\", true))
	{
		return 0;
	}
	reg->WriteString("Licence", Licence);
	reg->WriteString("fotopadrao", fotopadrao);
	reg->WriteString("Avaconnect", Avaconnect);
	reg->WriteString("Avacam", Avacam);
	reg->CloseKey();
	reg->Free();
	return 1;
}