/***********************************************************************
 * Module:  VENDA.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:04:41
 * Purpose: Implementation of the class VENDA
 ***********************************************************************/
//---------------------------------------------------------------------------

#pragma hdrstop


#include "VENDA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


////////////////////////////////////////////////////////////////////////
// Name:       VENDA::getVENDAID()
// Purpose:    Implementation of VENDA::getVENDAID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int VENDA::getVENDAID(void)
{
   return VENDAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::setVENDAID(int newVENDAID)
// Purpose:    Implementation of VENDA::setVENDAID()
// Parameters:
// - newVENDAID
// Return:     void
////////////////////////////////////////////////////////////////////////

void VENDA::setVENDAID(int newVENDAID)
{
   VENDAID = newVENDAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::getVENDAQUANTIDADE()
// Purpose:    Implementation of VENDA::getVENDAQUANTIDADE()
// Return:     int
////////////////////////////////////////////////////////////////////////

int VENDA::getVENDAQUANTIDADE(void)
{
   return VENDAQUANTIDADE;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::setVENDAQUANTIDADE(int newVENDAQUANTIDADE)
// Purpose:    Implementation of VENDA::setVENDAQUANTIDADE()
// Parameters:
// - newVENDAQUANTIDADE
// Return:     void
////////////////////////////////////////////////////////////////////////

void VENDA::setVENDAQUANTIDADE(int newVENDAQUANTIDADE)
{
   VENDAQUANTIDADE = newVENDAQUANTIDADE;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::getVENDADATA()
// Purpose:    Implementation of VENDA::getVENDADATA()
// Return:     TDate
////////////////////////////////////////////////////////////////////////

TDate VENDA::getVENDADATA(void)
{
   return VENDADATA;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::setVENDADATA(TDate newVENDADATA)
// Purpose:    Implementation of VENDA::setVENDADATA()
// Parameters:
// - newVENDADATA
// Return:     void
////////////////////////////////////////////////////////////////////////

void VENDA::setVENDADATA(TDate newVENDADATA)
{
   VENDADATA = newVENDADATA;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::IsEmpty()
// Purpose:    Implementation of VENDA::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int VENDA::IsEmpty(void)
{
   if ((VENDAQUANTIDADE == 0))
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::GetQuery()
// Purpose:    Implementation of VENDA::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query VENDA::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("VENDAQUANTIDADE")->AsInteger = VENDAQUANTIDADE;
   FDQuery->ParamByName("VENDADATA")->AsDate= VENDADATA;
   FDQuery = PRODUTO::GetQueryID(FDQuery);
   FDQuery = CLIENTE::GetQueryID(FDQuery);
   FDQuery = USUARIO::GetQueryID(FDQuery);



   return FDQuery;

}

Query VENDA::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("VENDAID")->AsInteger = VENDAID;
	return FDQuery;
}


////////////////////////////////////////////////////////////////////////
// Name:       VENDA::SetQuery()
// Purpose:    Implementation of VENDA::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

VENDA* VENDA::SetQuery(TFDQuery *FDQuery)
{
	VENDAID = FDQuery->FieldByName("VENDAID")->AsInteger;
	VENDAQUANTIDADE = FDQuery->FieldByName("VENDAQUANTIDADE")->AsInteger;
	VENDADATA = FDQuery->FieldByName("VENDADATA")->AsDateTime;
	PRODUTO::SetQuery(FDQuery);
	CLIENTE::SetQuery(FDQuery);
	USUARIO::SetQuery(FDQuery);

	return this;
}


////////////////////////////////////////////////////////////////////////
// Name:       VENDA::VENDA()
// Purpose:    Implementation of VENDA::VENDA()
// Return:
////////////////////////////////////////////////////////////////////////

VENDA::VENDA()
{
   VENDAID = 0;
   VENDAQUANTIDADE = 0;
   VENDADATA = 0;

}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::~VENDA()
// Purpose:    Implementation of VENDA::~VENDA()
// Return:
////////////////////////////////////////////////////////////////////////

VENDA::~VENDA()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       VENDA::VENDA(const VENDA& oldVENDA)
// Purpose:    Implementation of VENDA::VENDA()
// Parameters:
// - oldVENDA
// Return:
////////////////////////////////////////////////////////////////////////

