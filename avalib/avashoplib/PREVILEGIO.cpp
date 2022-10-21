/***********************************************************************
 * Module:  PREVILEGIO.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 10:23:47
 * Purpose: Implementation of the class PREVILEGIO
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "PREVILEGIO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::getPREVILEGIOID()
// Purpose:    Implementation of PREVILEGIO::getPREVILEGIOID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PREVILEGIO::getPREVILEGIOID(void)
{
   return PREVILEGIOID;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::setPREVILEGIOID(int newPREVILEGIOID)
// Purpose:    Implementation of PREVILEGIO::setPREVILEGIOID()
// Parameters:
// - newPREVILEGIOID
// Return:     void
////////////////////////////////////////////////////////////////////////

void PREVILEGIO::setPREVILEGIOID(int newPREVILEGIOID)
{
   PREVILEGIOID = newPREVILEGIOID;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::getPREVILEGIONOME()
// Purpose:    Implementation of PREVILEGIO::getPREVILEGIONOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string PREVILEGIO::getPREVILEGIONOME(void)
{
   return PREVILEGIONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::setPREVILEGIONOME(std::string newPREVILEGIONOME)
// Purpose:    Implementation of PREVILEGIO::setPREVILEGIONOME()
// Parameters:
// - newPREVILEGIONOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void PREVILEGIO::setPREVILEGIONOME(string newPREVILEGIONOME)
{
   PREVILEGIONOME = newPREVILEGIONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::PREVILEGIO()
// Purpose:    Implementation of PREVILEGIO::PREVILEGIO()
// Return:     
////////////////////////////////////////////////////////////////////////

PREVILEGIO::PREVILEGIO()
{
   PREVILEGIOID = 0;
   PREVILEGIONOME = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::~PREVILEGIO()
// Purpose:    Implementation of PREVILEGIO::~PREVILEGIO()
// Return:     
////////////////////////////////////////////////////////////////////////

PREVILEGIO::~PREVILEGIO()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::PREVILEGIO(const PREVILEGIO& oldPREVILEGIO)
// Purpose:    Implementation of PREVILEGIO::PREVILEGIO()
// Parameters:
// - oldPREVILEGIO
// Return:     
////////////////////////////////////////////////////////////////////////

PREVILEGIO::PREVILEGIO(const PREVILEGIO& oldPREVILEGIO)
{
   PREVILEGIOID = oldPREVILEGIO.PREVILEGIOID;
   PREVILEGIONOME = oldPREVILEGIO.PREVILEGIONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::IsEmpty()
// Purpose:    Implementation of PREVILEGIO::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PREVILEGIO::IsEmpty(void)
{
	if (PREVILEGIONOME == "")
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::GetQuery()
// Purpose:    Implementation of PREVILEGIO::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query PREVILEGIO::GetQuery(TFDQuery *FDQuery)
{

	FDQuery->ParamByName("PREVILEGIONOME")->AsAnsiString = PREVILEGIONOME;
	return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       PREVILEGIO::SetQuery()
// Purpose:    Implementation of PREVILEGIO::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

PREVILEGIO* PREVILEGIO::SetQuery(TFDQuery *FDQuery)
{
   PREVILEGIOID = FDQuery->FieldByName("PREVILEGIOID")->AsInteger;
   PREVILEGIONOME = FDQuery->FieldByName("PREVILEGIONOME")->AsAnsiString;
   return this;
}
Query PREVILEGIO::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("PREVILEGIOID")->AsInteger = PREVILEGIOID;
	return FDQuery;
}