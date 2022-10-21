/***********************************************************************
 * Module:  AvaAppInfo.cpp
 * Author:  Nick is Back
 * Modified: 7 de fevereiro de 2017 09:24:37
 * Purpose: Implementation of the class AvaAppInfo
 ***********************************************************************/
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "AvaAppInfo.h"

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::getAppPub()
// Purpose:    Implementation of AvaAppInfo::getAppPub()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaAppInfo::getAppPub(void)
{
   return AppPub;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::setAppPub(texto newAppPub)
// Purpose:    Implementation of AvaAppInfo::setAppPub()
// Parameters:
// - newAppPub
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaAppInfo::setAppPub(texto newAppPub)
{
   AppPub = newAppPub;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::getInstNome()
// Purpose:    Implementation of AvaAppInfo::getInstNome()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaAppInfo::getInstNome(void)
{
   return InstNome;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::setInstNome(texto newInstNome)
// Purpose:    Implementation of AvaAppInfo::setInstNome()
// Parameters:
// - newInstNome
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaAppInfo::setInstNome(texto newInstNome)
{
   InstNome = newInstNome;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::getAppVersao()
// Purpose:    Implementation of AvaAppInfo::getAppVersao()
// Return:     double
////////////////////////////////////////////////////////////////////////

double AvaAppInfo::getAppVersao(void)
{
   return AppVersao;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::setAppVersao(double newAppVersao)
// Purpose:    Implementation of AvaAppInfo::setAppVersao()
// Parameters:
// - newAppVersao
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaAppInfo::setAppVersao(double newAppVersao)
{
   AppVersao = newAppVersao;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::getAppNome()
// Purpose:    Implementation of AvaAppInfo::getAppNome()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaAppInfo::getAppNome(void)
{
   return AppNome;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::setAppNome(texto newAppNome)
// Purpose:    Implementation of AvaAppInfo::setAppNome()
// Parameters:
// - newAppNome
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaAppInfo::setAppNome(texto newAppNome)
{
   AppNome = newAppNome;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::AvaAppInfo()
// Purpose:    Implementation of AvaAppInfo::AvaAppInfo()
// Return:     
////////////////////////////////////////////////////////////////////////

AvaAppInfo::AvaAppInfo()
{
   AppPub = "avasoft";
   InstNome = "Cólegio Rosa de Angola";
   AppVersao = 0.5;
   AppNome = "avaschool";
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::~AvaAppInfo()
// Purpose:    Implementation of AvaAppInfo::~AvaAppInfo()
// Return:     
////////////////////////////////////////////////////////////////////////

AvaAppInfo::~AvaAppInfo()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::AvaAppInfo(const AvaAppInfo& oldAvaAppInfo)
// Purpose:    Implementation of AvaAppInfo::AvaAppInfo()
// Parameters:
// - oldAvaAppInfo
// Return:     
////////////////////////////////////////////////////////////////////////

AvaAppInfo::AvaAppInfo(const AvaAppInfo& oldAvaAppInfo)
{
   AppPub = oldAvaAppInfo.AppPub;
   InstNome = oldAvaAppInfo.InstNome;
   AppVersao = oldAvaAppInfo.AppVersao;
   AppNome = oldAvaAppInfo.AppNome;
   Path = oldAvaAppInfo.Path;
}



////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::getPath()
// Purpose:    Implementation of AvaAppInfo::getPath()
// Return:     AvaPath
////////////////////////////////////////////////////////////////////////

AvaPath AvaAppInfo::getPath(void)
{
   return Path;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaAppInfo::setPath(AvaPath newPath)
// Purpose:    Implementation of AvaAppInfo::setPath()
// Parameters:
// - newPath
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaAppInfo::setPath(AvaPath newPath)
{
   Path = newPath;
}

int AvaAppInfo::ReadRegistry()
{
	TRegistry* reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;;
	reg->Access = KEY_READ;

	if(!reg->OpenKey("Software\\Avasoft\\Avashop\\Info\\", false))
	{
		return 0;
	}
	AppPub = reg->ReadString("AppPub");
	InstNome = reg->ReadString("InstNome");
	AppVersao = reg->ReadFloat("AppVersao");
	AppNome = reg->ReadString("AppNome");
	reg->CloseKey();
	reg->Free();
	AvaPath::ReadRegistry();
	return 1;
}
int AvaAppInfo::WriteRegistry()
{
	TRegistry* reg = new TRegistry(KEY_WRITE);
	reg->RootKey = HKEY_CURRENT_USER;;
	reg->Access = KEY_WRITE;

	if(!reg->OpenKey("Software\\Avasoft\\Avashop\\Info\\", true))
	{
		return 0;
	}
	reg->WriteString("AppPub", AppPub);
	reg->WriteString("InstNome", InstNome);
	reg->WriteFloat("AppVersao", AppVersao);
	reg->WriteString("AppNome", AppNome);
	reg->CloseKey();
	reg->Free();
	AvaPath::WriteRegistry();
	return 1;
}