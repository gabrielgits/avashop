/***********************************************************************
 * Module:  FORNECEDORE.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:13:23
 * Purpose: Implementation of the class FORNECEDORE
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "FORNECEDORE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::getFORNECEDORID()
// Purpose:    Implementation of FORNECEDORE::getFORNECEDORID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int FORNECEDORE::getFORNECEDORID(void)
{
   return FORNECEDORID;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::setFORNECEDORID(int newFORNECEDORID)
// Purpose:    Implementation of FORNECEDORE::setFORNECEDORID()
// Parameters:
// - newFORNECEDORID
// Return:     void
////////////////////////////////////////////////////////////////////////

void FORNECEDORE::setFORNECEDORID(int newFORNECEDORID)
{
   FORNECEDORID = newFORNECEDORID;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::getFORNECEDORCONTACTO()
// Purpose:    Implementation of FORNECEDORE::getFORNECEDORCONTACTO()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string FORNECEDORE::getFORNECEDORCONTACTO(void)
{
   return FORNECEDORCONTACTO;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::setFORNECEDORCONTACTO(std::string newFORNECEDORCONTACTO)
// Purpose:    Implementation of FORNECEDORE::setFORNECEDORCONTACTO()
// Parameters:
// - newFORNECEDORCONTACTO
// Return:     void
////////////////////////////////////////////////////////////////////////

void FORNECEDORE::setFORNECEDORCONTACTO(string newFORNECEDORCONTACTO)
{
   FORNECEDORCONTACTO = newFORNECEDORCONTACTO;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::getFORNECEDORNOME()
// Purpose:    Implementation of FORNECEDORE::getFORNECEDORNOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string FORNECEDORE::getFORNECEDORNOME(void)
{
   return FORNECEDORNOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::setFORNECEDORNOME(std::string newFORNECEDORNOME)
// Purpose:    Implementation of FORNECEDORE::setFORNECEDORNOME()
// Parameters:
// - newFORNECEDORNOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void FORNECEDORE::setFORNECEDORNOME(string newFORNECEDORNOME)
{
   FORNECEDORNOME = newFORNECEDORNOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::getFORNECEDORENDERECO()
// Purpose:    Implementation of FORNECEDORE::getFORNECEDORENDERECO()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string FORNECEDORE::getFORNECEDORENDERECO(void)
{
   return FORNECEDORENDERECO;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::setFORNECEDORENDERECO(std::string newFORNECEDORENDERECO)
// Purpose:    Implementation of FORNECEDORE::setFORNECEDORENDERECO()
// Parameters:
// - newFORNECEDORENDERECO
// Return:     void
////////////////////////////////////////////////////////////////////////

void FORNECEDORE::setFORNECEDORENDERECO(string newFORNECEDORENDERECO)
{
   FORNECEDORENDERECO = newFORNECEDORENDERECO;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::FORNECEDORE()
// Purpose:    Implementation of FORNECEDORE::FORNECEDORE()
// Return:     
////////////////////////////////////////////////////////////////////////

FORNECEDORE::FORNECEDORE()
{
   FORNECEDORID = 0;
   FORNECEDORCONTACTO = "";
   FORNECEDORNOME = "";
   FORNECEDORENDERECO = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::~FORNECEDORE()
// Purpose:    Implementation of FORNECEDORE::~FORNECEDORE()
// Return:     
////////////////////////////////////////////////////////////////////////

FORNECEDORE::~FORNECEDORE()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::FORNECEDORE(const FORNECEDORE& oldFORNECEDORE)
// Purpose:    Implementation of FORNECEDORE::FORNECEDORE()
// Parameters:
// - oldFORNECEDORE
// Return:     
////////////////////////////////////////////////////////////////////////

FORNECEDORE::FORNECEDORE(const FORNECEDORE& oldFORNECEDORE)
{
   FORNECEDORID = oldFORNECEDORE.FORNECEDORID;
   FORNECEDORCONTACTO = oldFORNECEDORE.FORNECEDORCONTACTO;
   FORNECEDORNOME = oldFORNECEDORE.FORNECEDORNOME;
   FORNECEDORENDERECO = oldFORNECEDORE.FORNECEDORENDERECO;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::IsEmpty()
// Purpose:    Implementation of FORNECEDORE::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int FORNECEDORE::IsEmpty(void)
{
   if ((FORNECEDORCONTACTO == "") || (FORNECEDORNOME == "" ) || (FORNECEDORENDERECO == "" ))
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::GetQuery()
// Purpose:    Implementation of FORNECEDORE::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query FORNECEDORE::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("FORNECEDORCONTACTO")->AsAnsiString = FORNECEDORCONTACTO;
   FDQuery->ParamByName("FORNECEDORNOME")->AsAnsiString = FORNECEDORNOME;
   FDQuery->ParamByName("FORNECEDORENDERECO")->AsAnsiString = FORNECEDORENDERECO;
	return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       FORNECEDORE::SetQuery()
// Purpose:    Implementation of FORNECEDORE::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

FORNECEDORE* FORNECEDORE::SetQuery(TFDQuery *FDQuery)
{
  FORNECEDORID = FDQuery->FieldByName("FORNECEDORID")->AsInteger;
  FORNECEDORCONTACTO = FDQuery->FieldByName("FORNECEDORCONTACTO")->AsAnsiString;
  FORNECEDORNOME = FDQuery->FieldByName("FORNECEDORNOME")->AsAnsiString;
  FORNECEDORENDERECO = FDQuery->FieldByName("FORNECEDORENDERECO")->AsAnsiString;
  return this;
}
Query FORNECEDORE::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("FORNECEDORID")->AsInteger = FORNECEDORID;
	return FDQuery;
}