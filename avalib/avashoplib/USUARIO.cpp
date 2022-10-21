/***********************************************************************
 * Module:  USUARIO.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 10:59:44
 * Purpose: Implementation of the class USUARIO
 ***********************************************************************/
//---------------------------------------------------------------------------

#pragma hdrstop

#include "COMPRA.h"
#include "VENDA.h"
#include "USUARIO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::getUSUARIOID()
// Purpose:    Implementation of USUARIO::getUSUARIOID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int USUARIO::getUSUARIOID(void)
{
   return USUARIOID;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::setUSUARIOID(int newUSUARIOID)
// Purpose:    Implementation of USUARIO::setUSUARIOID()
// Parameters:
// - newUSUARIOID
// Return:     void
////////////////////////////////////////////////////////////////////////

void USUARIO::setUSUARIOID(int newUSUARIOID)
{
   USUARIOID = newUSUARIOID;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::getUSUARIONOME()
// Purpose:    Implementation of USUARIO::getUSUARIONOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string USUARIO::getUSUARIONOME(void)
{
   return USUARIONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::setUSUARIONOME(std::string newUSUARIONOME)
// Purpose:    Implementation of USUARIO::setUSUARIONOME()
// Parameters:
// - newUSUARIONOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void USUARIO::setUSUARIONOME(string newUSUARIONOME)
{
   USUARIONOME = newUSUARIONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::getUSUARIOSENHA()
// Purpose:    Implementation of USUARIO::getUSUARIOSENHA()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string USUARIO::getUSUARIOSENHA(void)
{
   return USUARIOSENHA;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::setUSUARIOSENHA(std::string newUSUARIOSENHA)
// Purpose:    Implementation of USUARIO::setUSUARIOSENHA()
// Parameters:
// - newUSUARIOSENHA
// Return:     void
////////////////////////////////////////////////////////////////////////

void USUARIO::setUSUARIOSENHA(string newUSUARIOSENHA)
{
   USUARIOSENHA = newUSUARIOSENHA;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::USUARIO()
// Purpose:    Implementation of USUARIO::USUARIO()
// Return:     
////////////////////////////////////////////////////////////////////////

USUARIO::USUARIO()
{
   USUARIOID = 0;
   USUARIONOME = "";
   USUARIOSENHA = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::~USUARIO()
// Purpose:    Implementation of USUARIO::~USUARIO()
// Return:     
////////////////////////////////////////////////////////////////////////

USUARIO::~USUARIO()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::IsEmpty()
// Purpose:    Implementation of USUARIO::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int USUARIO::IsEmpty(void)
{
   if ((USUARIONOME == "") || (USUARIOSENHA == ""))
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::GetQuery()
// Purpose:    Implementation of USUARIO::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query USUARIO::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("USUARIONOME")->AsAnsiString = USUARIONOME;
   FDQuery->ParamByName("USUARIOSENHA")->AsAnsiString = USUARIOSENHA;
   FDQuery->ParamByName("USUARIONOMECOMPLETO")->AsAnsiString = USUARIONOMECOMPLETO;
   FDQuery = PREVILEGIO::GetQueryID(FDQuery);
   return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       USUARIO::SetQuery()
// Purpose:    Implementation of USUARIO::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

USUARIO* USUARIO::SetQuery(TFDQuery *FDQuery)
{
   USUARIOID = FDQuery->FieldByName("USUARIOID")->AsInteger;
   USUARIONOME = FDQuery->FieldByName("USUARIONOME")->AsAnsiString;
   USUARIOSENHA = FDQuery->FieldByName("USUARIOSENHA")->AsAnsiString;
   USUARIONOMECOMPLETO = FDQuery->FieldByName("USUARIONOMECOMPLETO")->AsAnsiString;
   PREVILEGIO::SetQuery(FDQuery);
   return this;
}
Query USUARIO::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("USUARIOID")->AsInteger = USUARIOID;
	return FDQuery;
}

void USUARIO::setUSUARIONOMECOMPLETO(string newUSUARIONOMECOMPLETO)
{
	USUARIONOMECOMPLETO = newUSUARIONOMECOMPLETO;
}

string USUARIO::getUSUARIONOMECOMPLETO(void)
{
	return USUARIONOMECOMPLETO;
}
