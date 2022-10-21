/***********************************************************************
 * Module:  CLIENTE.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:07:45
 * Purpose: Implementation of the class CLIENTE
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "CLIENTE.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::getCLIENTEID()
// Purpose:    Implementation of CLIENTE::getCLIENTEID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int CLIENTE::getCLIENTEID(void)
{
   return CLIENTEID;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::setCLIENTEID(int newCLIENTEID)
// Purpose:    Implementation of CLIENTE::setCLIENTEID()
// Parameters:
// - newCLIENTEID
// Return:     void
////////////////////////////////////////////////////////////////////////

void CLIENTE::setCLIENTEID(int newCLIENTEID)
{
   CLIENTEID = newCLIENTEID;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::getCLIENTECONTA()
// Purpose:    Implementation of CLIENTE::getCLIENTECONTA()
// Return:     double
////////////////////////////////////////////////////////////////////////

double CLIENTE::getCLIENTECONTA(void)
{
   return CLIENTECONTA;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::setCLIENTECONTA(double newCLIENTECONTA)
// Purpose:    Implementation of CLIENTE::setCLIENTECONTA()
// Parameters:
// - newCLIENTECONTA
// Return:     void
////////////////////////////////////////////////////////////////////////

void CLIENTE::setCLIENTECONTA(double newCLIENTECONTA)
{
   CLIENTECONTA = newCLIENTECONTA;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::CLIENTE()
// Purpose:    Implementation of CLIENTE::CLIENTE()
// Return:     
////////////////////////////////////////////////////////////////////////

CLIENTE::CLIENTE()
{
   CLIENTEID = 0;
   CLIENTECONTA = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::~CLIENTE()
// Purpose:    Implementation of CLIENTE::~CLIENTE()
// Return:     
////////////////////////////////////////////////////////////////////////

CLIENTE::~CLIENTE()
{
   // TODO : implement
}


////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::IsEmpty()
// Purpose:    Implementation of CLIENTE::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int CLIENTE::IsEmpty(void)
{
   if (CLIENTECONTA == 0)
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::GetQuery()
// Purpose:    Implementation of CLIENTE::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query CLIENTE::GetQuery(TFDQuery *FDQuery)
{

	FDQuery->ParamByName("CLIENTECONTA")->AsFloat = CLIENTECONTA;
	FDQuery = TIPOCLIENTE::GetQueryID(FDQuery);
	FDQuery = PESSOA::GetQueryID(FDQuery);
	return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       CLIENTE::SetQuery()
// Purpose:    Implementation of CLIENTE::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

CLIENTE * CLIENTE::SetQuery(TFDQuery *FDQuery)
{
   CLIENTEID = FDQuery->FieldByName("CLIENTEID")->AsInteger;
	CLIENTECONTA = FDQuery->FieldByName("CLIENTECONTA")->AsFloat;
	 TIPOCLIENTE::SetQuery(FDQuery);
	 PESSOA::SetQuery(FDQuery);
	return this;
}
Query CLIENTE::GetQueryID(TFDQuery *FDQuery)
{
 FDQuery->ParamByName("CLIENTEID")->AsInteger = CLIENTEID;
 return FDQuery;
}