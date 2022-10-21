/***********************************************************************
 * Module:  PESSOA.cpp
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:03:26
 * Purpose: Implementation of the class PESSOA
 ***********************************************************************/

//---------------------------------------------------------------------------

#pragma hdrstop

#include "CLIENTE.h"
#include "USUARIO.h"
#include "PESSOA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include "CLIENTE.h"
#include "USUARIO.h"
#include "PESSOA.h"

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::getPESSOAID()
// Purpose:    Implementation of PESSOA::getPESSOAID()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PESSOA::getPESSOAID(void)
{
   return PESSOAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::setPESSOAID(int newPESSOAID)
// Purpose:    Implementation of PESSOA::setPESSOAID()
// Parameters:
// - newPESSOAID
// Return:     void
////////////////////////////////////////////////////////////////////////

void PESSOA::setPESSOAID(int newPESSOAID)
{
   PESSOAID = newPESSOAID;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::getPESSOANOME()
// Purpose:    Implementation of PESSOA::getPESSOANOME()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string PESSOA::getPESSOANOME(void)
{
   return PESSOANOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::setPESSOANOME(std::string newPESSOANOME)
// Purpose:    Implementation of PESSOA::setPESSOANOME()
// Parameters:
// - newPESSOANOME
// Return:     void
////////////////////////////////////////////////////////////////////////

void PESSOA::setPESSOANOME(string newPESSOANOME)
{
   PESSOANOME = newPESSOANOME;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::getPESSOADATA()
// Purpose:    Implementation of PESSOA::getPESSOADATA()
// Return:     TDate
////////////////////////////////////////////////////////////////////////

TDate PESSOA::getPESSOADATA(void)
{
   return PESSOADATA;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::setPESSOADATA(TDate newPESSOADATA)
// Purpose:    Implementation of PESSOA::setPESSOADATA()
// Parameters:
// - newPESSOADATA
// Return:     void
////////////////////////////////////////////////////////////////////////

void PESSOA::setPESSOADATA(TDate newPESSOADATA)
{
   PESSOADATA = newPESSOADATA;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::getPESSOACONTACTO()
// Purpose:    Implementation of PESSOA::getPESSOACONTACTO()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string PESSOA::getPESSOACONTACTO(void)
{
   return PESSOACONTACTO;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::setPESSOACONTACTO(std::string newPESSOACONTACTO)
// Purpose:    Implementation of PESSOA::setPESSOACONTACTO()
// Parameters:
// - newPESSOACONTACTO
// Return:     void
////////////////////////////////////////////////////////////////////////

void PESSOA::setPESSOACONTACTO(string newPESSOACONTACTO)
{
   PESSOACONTACTO = newPESSOACONTACTO;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::getPESSOAMORADA()
// Purpose:    Implementation of PESSOA::getPESSOAMORADA()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string PESSOA::getPESSOAMORADA(void)
{
   return PESSOAMORADA;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::setPESSOAMORADA(std::string newPESSOAMORADA)
// Purpose:    Implementation of PESSOA::setPESSOAMORADA()
// Parameters:
// - newPESSOAMORADA
// Return:     void
////////////////////////////////////////////////////////////////////////

void PESSOA::setPESSOAMORADA(string newPESSOAMORADA)
{
   PESSOAMORADA = newPESSOAMORADA;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::getPESSOABI()
// Purpose:    Implementation of PESSOA::getPESSOABI()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

string PESSOA::getPESSOABI(void)
{
   return PESSOABI;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::setPESSOABI(std::string newPESSOABI)
// Purpose:    Implementation of PESSOA::setPESSOABI()
// Parameters:
// - newPESSOABI
// Return:     void
////////////////////////////////////////////////////////////////////////

void PESSOA::setPESSOABI(string newPESSOABI)
{
   PESSOABI = newPESSOABI;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::PESSOA()
// Purpose:    Implementation of PESSOA::PESSOA()
// Return:     
////////////////////////////////////////////////////////////////////////

PESSOA::PESSOA()
{
   PESSOAID = 0;
   PESSOANOME = "";
   PESSOADATA = 0;
   PESSOACONTACTO = "";
   PESSOAMORADA = "";
   PESSOABI = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::~PESSOA()
// Purpose:    Implementation of PESSOA::~PESSOA()
// Return:     
////////////////////////////////////////////////////////////////////////

PESSOA::~PESSOA()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::PESSOA(const PESSOA& oldPESSOA)
// Purpose:    Implementation of PESSOA::PESSOA()
// Parameters:
// - oldPESSOA
// Return:     
////////////////////////////////////////////////////////////////////////

PESSOA::PESSOA(const PESSOA& oldPESSOA)
{
   PESSOAID = oldPESSOA.PESSOAID;
   PESSOANOME = oldPESSOA.PESSOANOME;
   PESSOADATA = oldPESSOA.PESSOADATA;
   PESSOACONTACTO = oldPESSOA.PESSOACONTACTO;
   PESSOAMORADA = oldPESSOA.PESSOAMORADA;
   PESSOABI = oldPESSOA.PESSOABI;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::IsEmpty()
// Purpose:    Implementation of PESSOA::IsEmpty()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PESSOA::IsEmpty(void)
{
   if ((PESSOAID == 0) || (PESSOANOME == "") || (PESSOACONTACTO == "" ) ||(PESSOAMORADA == "") || (PESSOABI == ""))
   {
		return 1;
   }
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::GetQuery()
// Purpose:    Implementation of PESSOA::GetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

Query PESSOA::GetQuery(TFDQuery *FDQuery)
{

   FDQuery->ParamByName("PESSOANOME")->AsAnsiString = PESSOANOME;
   FDQuery->ParamByName("PESSOADATA")->AsDate = PESSOADATA;
   FDQuery->ParamByName("PESSOACONTACTO")->AsAnsiString = PESSOACONTACTO;
   FDQuery->ParamByName("PESSOAMORADA")->AsAnsiString = PESSOAMORADA;
   FDQuery->ParamByName("PESSOABI")->AsAnsiString = PESSOABI;
   return FDQuery;
}

////////////////////////////////////////////////////////////////////////
// Name:       PESSOA::SetQuery()
// Purpose:    Implementation of PESSOA::SetQuery()
// Return:     Query
////////////////////////////////////////////////////////////////////////

PESSOA* PESSOA::SetQuery(TFDQuery *FDQuery)
{
   PESSOAID = FDQuery->FieldByName("PESSOAID")->AsInteger;
   PESSOANOME = FDQuery->FieldByName("PESSOANOME")->AsAnsiString;
   PESSOADATA = FDQuery->FieldByName("PESSOADATA")->AsDateTime;
   PESSOACONTACTO = FDQuery->FieldByName("PESSOACONTACTO")->AsAnsiString;
   PESSOAMORADA = FDQuery->FieldByName("PESSOAMORADA")->AsAnsiString;
   PESSOABI = FDQuery->FieldByName("PESSOABI")->AsAnsiString;
	return this;
}
Query PESSOA::GetQueryID(TFDQuery *FDQuery)
{
	FDQuery->ParamByName("PESSOAID")->AsInteger = PESSOAID;
	return FDQuery;
}