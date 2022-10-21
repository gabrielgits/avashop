/***********************************************************************
 * Module:  AvaLicence.cpp
 * Author:  Nick is Back
 * Modified: 7 de fevereiro de 2017 09:20:23
 * Purpose: Implementation of the class AvaLicence
 ***********************************************************************/
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "AvaLicence.h"

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::getContacto()
// Purpose:    Implementation of AvaLicence::getContacto()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaLicence::getContacto(void)
{
   return Contacto;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::setContacto(texto newContacto)
// Purpose:    Implementation of AvaLicence::setContacto()
// Parameters:
// - newContacto
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaLicence::setContacto(texto newContacto)
{
   Contacto = newContacto;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::getCliente()
// Purpose:    Implementation of AvaLicence::getCliente()
// Return:     texto
////////////////////////////////////////////////////////////////////////

texto AvaLicence::getCliente(void)
{
   return Cliente;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::setCliente(texto newCliente)
// Purpose:    Implementation of AvaLicence::setCliente()
// Parameters:
// - newCliente
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaLicence::setCliente(texto newCliente)
{
   Cliente = newCliente;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::getData()
// Purpose:    Implementation of AvaLicence::getData()
// Return:     TDate
////////////////////////////////////////////////////////////////////////

TDate AvaLicence::getData(void)
{
   return Data;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::setData(TDate newData)
// Purpose:    Implementation of AvaLicence::setData()
// Parameters:
// - newData
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaLicence::setData(TDate newData)
{
   Data = newData;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::getTempo()
// Purpose:    Implementation of AvaLicence::getTempo()
// Return:     int
////////////////////////////////////////////////////////////////////////

int AvaLicence::getTempo(void)
{
   return Tempo;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::setTempo(int newTempo)
// Purpose:    Implementation of AvaLicence::setTempo()
// Parameters:
// - newTempo
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaLicence::setTempo(int newTempo)
{
   Tempo = newTempo;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::getTipo()
// Purpose:    Implementation of AvaLicence::getTipo()
// Return:     int
////////////////////////////////////////////////////////////////////////

int AvaLicence::getTipo(void)
{
   return Tipo;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::setTipo(int newTipo)
// Purpose:    Implementation of AvaLicence::setTipo()
// Parameters:
// - newTipo
// Return:     void
////////////////////////////////////////////////////////////////////////

void AvaLicence::setTipo(int newTipo)
{
   Tipo = newTipo;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::AvaLicence()
// Purpose:    Implementation of AvaLicence::AvaLicence()
// Return:     
////////////////////////////////////////////////////////////////////////

AvaLicence::AvaLicence()
{
   Contacto = "sem contacto";
   Cliente = "Desconhecido";
   Data = Date().CurrentDate();
   Tempo = 60;
   Tipo = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::~AvaLicence()
// Purpose:    Implementation of AvaLicence::~AvaLicence()
// Return:     
////////////////////////////////////////////////////////////////////////

AvaLicence::~AvaLicence()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       AvaLicence::AvaLicence(const AvaLicence& oldAvaLicence)
// Purpose:    Implementation of AvaLicence::AvaLicence()
// Parameters:
// - oldAvaLicence
// Return:     
////////////////////////////////////////////////////////////////////////

AvaLicence::AvaLicence(const AvaLicence& oldAvaLicence)
{
   Contacto = oldAvaLicence.Contacto;
   Cliente = oldAvaLicence.Cliente;
   Data = oldAvaLicence.Data;
   Tempo = oldAvaLicence.Tempo;
   Tipo = oldAvaLicence.Tipo;
}

int AvaLicence::ReadRegistry()
{
	TRegistry* reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;;
	reg->Access = KEY_READ;

	if(!reg->OpenKey("Software\\Avasoft\\Avashop\\Licence\\", false))
	{
		return 0;
	}
	Contacto = reg->ReadString("Contacto");
	Cliente = reg->ReadString("Cliente");
	Data = reg->ReadDate("Data");
	Tempo = reg->ReadInteger("Tempo");
	Tipo = reg->ReadInteger("Tipo");
	reg->CloseKey();
	reg->Free();
	return 1;
}
int AvaLicence::WriteRegistry()
{
	TRegistry* reg = new TRegistry(KEY_WRITE);
	reg->RootKey = HKEY_CURRENT_USER;;
	reg->Access = KEY_WRITE;

	if(reg->KeyExists("Software\\Avasoft\\Avashop\\Licence\\"))
	{
		return 0;
	}
	reg->OpenKey("Software\\Avasoft\\Avashop\\Licence\\",true);
	reg->WriteString("Contacto", Contacto);
	reg->WriteString("Cliente", Cliente);
	reg->WriteDate("Data", Data);
	reg->WriteInteger("Tempo", Tempo);
	reg->WriteInteger("Tipo", Tipo);
	reg->CloseKey();
	reg->Free();
	return 1;
}