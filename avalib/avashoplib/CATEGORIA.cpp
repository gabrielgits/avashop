/***********************************************************************
 * Module:  CATEGORIA.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:11:50
 * Purpose: Implementation of the class CATEGORIA
 ***********************************************************************/


//---------------------------------------------------------------------------

#pragma hdrstop

#include "CATEGORIA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::getCATEGORIAID()
// Purpose:    Implementation of CATEGORIA::getCATEGORIAID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int CATEGORIA::getCATEGORIAID(void)
{
   return CATEGORIAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::setCATEGORIAID(int newCATEGORIAID)
// Purpose:    Implementation of CATEGORIA::setCATEGORIAID()
// Parameters:
// - newCATEGORIAID
// Return:     void
////////////////////////////////////////////////////////////////////////

void CATEGORIA::setCATEGORIAID(int newCATEGORIAID)
{
   CATEGORIAID = newCATEGORIAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::getCATEGORIANOME()
// Purpose:    Implementation of CATEGORIA::getCATEGORIANOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string CATEGORIA::getCATEGORIANOME(void)
{
   return CATEGORIANOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::setCATEGORIANOME(std::string newCATEGORIANOME)
// Purpose:    Implementation of CATEGORIA::setCATEGORIANOME()
// Parameters:
// - newCATEGORIANOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void CATEGORIA::setCATEGORIANOME(string newCATEGORIANOME)
{
   CATEGORIANOME = newCATEGORIANOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::CATEGORIA()
// Purpose:    Implementation of CATEGORIA::CATEGORIA()
// Return:     
////////////////////////////////////////////////////////////////////////

CATEGORIA::CATEGORIA()
{
   CATEGORIAID = 0;
   CATEGORIANOME = "";

}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::~CATEGORIA()
// Purpose:    Implementation of CATEGORIA::~CATEGORIA()
// Return:     
////////////////////////////////////////////////////////////////////////

CATEGORIA::~CATEGORIA()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::CATEGORIA(const CATEGORIA& oldCATEGORIA)
// Purpose:    Implementation of CATEGORIA::CATEGORIA()
// Parameters:
// - oldCATEGORIA
// Return:     
////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::IsEmpty()
// Purpose:    Implementation of CATEGORIA::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int CATEGORIA::IsEmpty(void)
{
   if (CATEGORIANOME == "")
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::GetQuery()
// Purpose:    Implementation of CATEGORIA::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query CATEGORIA::GetQuery(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("CATEGORIANOME")->AsAnsiString = CATEGORIANOME;
	return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       CATEGORIA::SetQuery()
// Purpose:    Implementation of CATEGORIA::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

CATEGORIA *CATEGORIA::SetQuery(TFDQuery *FDQuery)
{
	CATEGORIAID = FDQuery->FieldByName("CATEGORIAID")->AsInteger;
	CATEGORIANOME = FDQuery->FieldByName("CATEGORIANOME")->AsAnsiString;
	return this;
}
Query CATEGORIA::GetQueryID(TFDQuery *FDQuery)
{
 FDQuery->ParamByName("CATEGORIAID")->AsInteger = CATEGORIAID;
 return FDQuery;
}
