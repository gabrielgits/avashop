/***********************************************************************
 * Module:  STOCK.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:10:32
 * Purpose: Implementation of the class STOCK
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "STOCK.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



////////////////////////////////////////////////////////////////////////
// Name:       STOCK::getSTOCKID()
// Purpose:    Implementation of STOCK::getSTOCKID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int STOCK::getSTOCKID(void)
{
   return STOCKID;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::setSTOCKID(int newSTOCKID)
// Purpose:    Implementation of STOCK::setSTOCKID()
// Parameters:
// - newSTOCKID
// Return:     void
////////////////////////////////////////////////////////////////////////

void STOCK::setSTOCKID(int newSTOCKID)
{
   STOCKID = newSTOCKID;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::getSTOCKQUANTIA()
// Purpose:    Implementation of STOCK::getSTOCKQUANTIA()
// Return:     int
////////////////////////////////////////////////////////////////////////

int STOCK::getSTOCKQUANTIA(void)
{
   return STOCKQUANTIA;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::setSTOCKQUANTIA(int newSTOCKQUANTIA)
// Purpose:    Implementation of STOCK::setSTOCKQUANTIA()
// Parameters:
// - newSTOCKQUANTIA
// Return:     void
////////////////////////////////////////////////////////////////////////

void STOCK::setSTOCKQUANTIA(int newSTOCKQUANTIA)
{
   STOCKQUANTIA = newSTOCKQUANTIA;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::getSTOCKUPDATE()
// Purpose:    Implementation of STOCK::getSTOCKUPDATE()
// Return:     TDate
////////////////////////////////////////////////////////////////////////

TDate STOCK::getSTOCKUPDATE(void)
{
   return STOCKUPDATE;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::setSTOCKUPDATE(TDate newSTOCKUPDATE)
// Purpose:    Implementation of STOCK::setSTOCKUPDATE()
// Parameters:
// - newSTOCKUPDATE
// Return:     void
////////////////////////////////////////////////////////////////////////

void STOCK::setSTOCKUPDATE(TDate newSTOCKUPDATE)
{
   STOCKUPDATE = newSTOCKUPDATE;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::STOCK()
// Purpose:    Implementation of STOCK::STOCK()
// Return:     
////////////////////////////////////////////////////////////////////////

STOCK::STOCK()
{
   STOCKID = 0;
   STOCKQUANTIA = 0;
   STOCKUPDATE = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::~STOCK()
// Purpose:    Implementation of STOCK::~STOCK()
// Return:     
////////////////////////////////////////////////////////////////////////

STOCK::~STOCK()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::STOCK(const STOCK& oldSTOCK)
// Purpose:    Implementation of STOCK::STOCK()
// Parameters:
// - oldSTOCK
// Return:     
////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// Name:       STOCK::IsEmpty()
// Purpose:    Implementation of STOCK::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int STOCK::IsEmpty(void)
{
   if (STOCKQUANTIA == 0)
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::GetQuery()
// Purpose:    Implementation of STOCK::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query STOCK::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("STOCKQUANTIA")->AsInteger = STOCKQUANTIA;
   FDQuery->ParamByName("STOCKUPDATE")->AsDate = STOCKUPDATE;
   FDQuery = PRODUTO::GetQueryID(FDQuery);
   return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       STOCK::SetQuery()
// Purpose:    Implementation of STOCK::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

STOCK* STOCK::SetQuery(TFDQuery *FDQuery)
{
   STOCKID = FDQuery->FieldByName("STOCKID")->AsInteger;
   STOCKQUANTIA = FDQuery->FieldByName("STOCKQUANTIA")->AsInteger;
   STOCKUPDATE = FDQuery->FieldByName("STOCKUPDATE")->AsDateTime;
   PRODUTO::SetQuery(FDQuery);
	return this;
}
Query STOCK::GetQueryID(TFDQuery *FDQuery)
{
FDQuery->ParamByName("STOCKID")->AsInteger = STOCKID;
return FDQuery;
}