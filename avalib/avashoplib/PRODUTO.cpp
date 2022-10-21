/***********************************************************************
 * Module:  PRODUTO.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:09:14
 * Purpose: Implementation of the class PRODUTO
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "PRODUTO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::getPRODUTOID()
// Purpose:    Implementation of PRODUTO::getPRODUTOID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PRODUTO::getPRODUTOID(void)
{
   return PRODUTOID;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::setPRODUTOID(int newPRODUTOID)
// Purpose:    Implementation of PRODUTO::setPRODUTOID()
// Parameters:
// - newPRODUTOID
// Return:     void
////////////////////////////////////////////////////////////////////////

void PRODUTO::setPRODUTOID(int newPRODUTOID)
{
   PRODUTOID = newPRODUTOID;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::getPRODUTONOME()
// Purpose:    Implementation of PRODUTO::getPRODUTONOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string PRODUTO::getPRODUTONOME(void)
{
   return PRODUTONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::setPRODUTONOME(std::string newPRODUTONOME)
// Purpose:    Implementation of PRODUTO::setPRODUTONOME()
// Parameters:
// - newPRODUTONOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void PRODUTO::setPRODUTONOME(string newPRODUTONOME)
{
   PRODUTONOME = newPRODUTONOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::getPRODUTOPRECO()
// Purpose:    Implementation of PRODUTO::getPRODUTOPRECO()
// Return:     double
////////////////////////////////////////////////////////////////////////

double PRODUTO::getPRODUTOPRECO(void)
{
   return PRODUTOPRECO;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::setPRODUTOPRECO(double newPRODUTOPRECO)
// Purpose:    Implementation of PRODUTO::setPRODUTOPRECO()
// Parameters:
// - newPRODUTOPRECO
// Return:     void
////////////////////////////////////////////////////////////////////////

void PRODUTO::setPRODUTOPRECO(double newPRODUTOPRECO)
{
   PRODUTOPRECO = newPRODUTOPRECO;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::PRODUTO()
// Purpose:    Implementation of PRODUTO::PRODUTO()
// Return:     
////////////////////////////////////////////////////////////////////////

PRODUTO::PRODUTO()
{
   PRODUTOID = 0;
   PRODUTONOME = "";
   PRODUTOPRECO = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::~PRODUTO()
// Purpose:    Implementation of PRODUTO::~PRODUTO()
// Return:     
////////////////////////////////////////////////////////////////////////

PRODUTO::~PRODUTO()
{
   // TODO : implement
}


////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::IsEmpty()
// Purpose:    Implementation of PRODUTO::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PRODUTO::IsEmpty(void)
{
   if ((PRODUTONOME == "") || (PRODUTOPRECO == 0))
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::GetQuery()
// Purpose:    Implementation of PRODUTO::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query PRODUTO::GetQuery(TFDQuery *FDQuery)
{

	FDQuery->ParamByName("PRODUTONOME")->AsAnsiString = PRODUTONOME;
	FDQuery->ParamByName("PRODUTOPRECO")->AsInteger = PRODUTOPRECO;
	FDQuery = CATEGORIA::GetQueryID(FDQuery);
	return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       PRODUTO::SetQuery()
// Purpose:    Implementation of PRODUTO::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

PRODUTO * PRODUTO::SetQuery(TFDQuery *FDQuery)
{
	PRODUTOID = FDQuery->FieldByName("PRODUTOID")->AsInteger;
	PRODUTONOME = FDQuery->FieldByName("PRODUTONOME")->AsAnsiString;
	PRODUTOPRECO = FDQuery->FieldByName("PRODUTOPRECO")->AsFloat;
	CATEGORIA::SetQuery(FDQuery);
	return this;
}
Query PRODUTO::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("PRODUTOID")->AsInteger = PRODUTOID;
	return FDQuery;
}