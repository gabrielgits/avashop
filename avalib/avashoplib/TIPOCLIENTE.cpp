/***********************************************************************
 * Module:  TIPOCLIENTE.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:01:25
 * Purpose: Implementation of the class TIPOCLIENTE
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#pragma package(smart_init)
#include "CLIENTE.h"
#include "TIPOCLIENTE.h"
//---------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::getTIPOCLIENTEID()
// Purpose:    Implementation of TIPOCLIENTE::getTIPOCLIENTEID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int TIPOCLIENTE::getTIPOCLIENTEID(void)
{
   return TIPOCLIENTEID;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::setTIPOCLIENTEID(int newTIPOCLIENTEID)
// Purpose:    Implementation of TIPOCLIENTE::setTIPOCLIENTEID()
// Parameters:
// - newTIPOCLIENTEID
// Return:     void
////////////////////////////////////////////////////////////////////////

void TIPOCLIENTE::setTIPOCLIENTEID(int newTIPOCLIENTEID)
{
   TIPOCLIENTEID = newTIPOCLIENTEID;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::getTIPOCLIENTENOME()
// Purpose:    Implementation of TIPOCLIENTE::getTIPOCLIENTENOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string TIPOCLIENTE::getTIPOCLIENTENOME(void)
{
   return TIPOCLIENTENOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::setTIPOCLIENTENOME(std::string newTIPOCLIENTENOME)
// Purpose:    Implementation of TIPOCLIENTE::setTIPOCLIENTENOME()
// Parameters:
// - newTIPOCLIENTENOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void TIPOCLIENTE::setTIPOCLIENTENOME(string newTIPOCLIENTENOME)
{
   TIPOCLIENTENOME = newTIPOCLIENTENOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::TIPOCLIENTE()
// Purpose:    Implementation of TIPOCLIENTE::TIPOCLIENTE()
// Return:     
////////////////////////////////////////////////////////////////////////

TIPOCLIENTE::TIPOCLIENTE()
{
   TIPOCLIENTEID = 0;
   TIPOCLIENTENOME = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::~TIPOCLIENTE()
// Purpose:    Implementation of TIPOCLIENTE::~TIPOCLIENTE()
// Return:     
////////////////////////////////////////////////////////////////////////

TIPOCLIENTE::~TIPOCLIENTE()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::TIPOCLIENTE(const TIPOCLIENTE& oldTIPOCLIENTE)
// Purpose:    Implementation of TIPOCLIENTE::TIPOCLIENTE()
// Parameters:
// - oldTIPOCLIENTE
// Return:     
////////////////////////////////////////////////////////////////////////

TIPOCLIENTE::TIPOCLIENTE(const TIPOCLIENTE& oldTIPOCLIENTE)
{
   TIPOCLIENTEID = oldTIPOCLIENTE.TIPOCLIENTEID;
   TIPOCLIENTENOME = oldTIPOCLIENTE.TIPOCLIENTENOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::IsEmpty()
// Purpose:    Implementation of TIPOCLIENTE::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int TIPOCLIENTE::IsEmpty(void)
{
   if(TIPOCLIENTENOME == "")
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::GetQuery()
// Purpose:    Implementation of TIPOCLIENTE::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query TIPOCLIENTE::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("TIPOCLIENTENOME")->AsAnsiString = TIPOCLIENTENOME;
	return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       TIPOCLIENTE::SetQuery()
// Purpose:    Implementation of TIPOCLIENTE::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

TIPOCLIENTE* TIPOCLIENTE::SetQuery(TFDQuery *FDQuery)
{
   TIPOCLIENTEID = FDQuery->FieldByName("TIPOCLIENTEID")->AsInteger;
   TIPOCLIENTENOME = FDQuery->FieldByName("TIPOCLIENTENOME")->AsAnsiString;
   return this;
}

Query TIPOCLIENTE::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("TIPOCLIENTEID")->AsInteger = TIPOCLIENTEID;
	return FDQuery;
}