/***********************************************************************
 * Module:  COMPRA.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:06:14
 * Purpose: Implementation of the class COMPRA
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "COMPRA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::getCOMPRAID()
// Purpose:    Implementation of COMPRA::getCOMPRAID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int COMPRA::getCOMPRAID(void)
{
   return COMPRAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::setCOMPRAID(int newCOMPRAID)
// Purpose:    Implementation of COMPRA::setCOMPRAID()
// Parameters:
// - newCOMPRAID
// Return:     void
////////////////////////////////////////////////////////////////////////

void COMPRA::setCOMPRAID(int newCOMPRAID)
{
   COMPRAID = newCOMPRAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::getCOMPRADATA()
// Purpose:    Implementation of COMPRA::getCOMPRADATA()
// Return:     TDate
////////////////////////////////////////////////////////////////////////

TDate COMPRA::getCOMPRADATA(void)
{
   return COMPRADATA;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::setCOMPRADATA(TDate newCOMPRADATA)
// Purpose:    Implementation of COMPRA::setCOMPRADATA()
// Parameters:
// - newCOMPRADATA
// Return:     void
////////////////////////////////////////////////////////////////////////

void COMPRA::setCOMPRADATA(TDate newCOMPRADATA)
{
   COMPRADATA = newCOMPRADATA;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::getCOMPRAQUANTIDADE()
// Purpose:    Implementation of COMPRA::getCOMPRAQUANTIDADE()
// Return:     int
////////////////////////////////////////////////////////////////////////

int COMPRA::getCOMPRAQUANTIDADE(void)
{
   return COMPRAQUANTIDADE;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::setCOMPRAQUANTIDADE(int newCOMPRAQUANTIDADE)
// Purpose:    Implementation of COMPRA::setCOMPRAQUANTIDADE()
// Parameters:
// - newCOMPRAQUANTIDADE
// Return:     void
////////////////////////////////////////////////////////////////////////

void COMPRA::setCOMPRAQUANTIDADE(int newCOMPRAQUANTIDADE)
{
   COMPRAQUANTIDADE = newCOMPRAQUANTIDADE;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::COMPRA()
// Purpose:    Implementation of COMPRA::COMPRA()
// Return:
////////////////////////////////////////////////////////////////////////
double COMPRA::getCOMPRAPRECO(void)
{
   return COMPRAPRECO;
}
////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::COMPRA()
// Purpose:    Implementation of COMPRA::COMPRA()
// Return:
////////////////////////////////////////////////////////////////////////
void COMPRA::setCOMPRAPRECO(double newCOMPRAPRECO)
{
   COMPRAPRECO = newCOMPRAPRECO;
}

COMPRA::COMPRA()
{
   COMPRAID = 0;
   COMPRADATA = 0;
   COMPRAQUANTIDADE = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::~COMPRA()
// Purpose:    Implementation of COMPRA::~COMPRA()
// Return:     
////////////////////////////////////////////////////////////////////////

COMPRA::~COMPRA()
{
   // TODO : implement
}


////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::IsEmpty()
// Purpose:    Implementation of COMPRA::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int COMPRA::IsEmpty(void)
{
   if (COMPRAQUANTIDADE == 0)
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::GetQuery()
// Purpose:    Implementation of COMPRA::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query COMPRA::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("COMPRADATA")->AsDate = COMPRADATA;
   FDQuery->ParamByName("COMPRAQUANTIDADE")->AsInteger = COMPRAQUANTIDADE;
   FDQuery->ParamByName("COMPRAPRECO")->AsFloat = COMPRAPRECO;
   FDQuery = PRODUTO::GetQueryID(FDQuery);
   FDQuery = USUARIO::GetQueryID(FDQuery);
   FDQuery = FORNECEDORE::GetQueryID(FDQuery);

   return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       COMPRA::SetQuery()
// Purpose:    Implementation of COMPRA::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

COMPRA* COMPRA::SetQuery(TFDQuery *FDQuery)
{
	COMPRAID = FDQuery->FieldByName("COMPRAID")->AsInteger;
	COMPRADATA = FDQuery->FieldByName("COMPRADATA")->AsDateTime;
	COMPRAQUANTIDADE = FDQuery->FieldByName("COMPRAQUANTIDADE")->AsInteger;
	COMPRAPRECO = FDQuery->FieldByName("COMPRAPRECO")->AsFloat;

	 PRODUTO::SetQuery(FDQuery);
	 USUARIO::SetQuery(FDQuery);
	 FORNECEDORE::SetQuery(FDQuery);

	return this;
}
Query COMPRA::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("COMPRAID")->AsInteger = COMPRAID;
	return FDQuery;
}