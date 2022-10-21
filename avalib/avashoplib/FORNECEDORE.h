/***********************************************************************
 * Module:  FORNECEDORE.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:13:23
 * Purpose: Declaration of the class FORNECEDORE
 ***********************************************************************/
#ifndef FORNECEDOREH
#define FORNECEDOREH
#include "PRODUTO.h"

class FORNECEDORE
{
public:
   int getFORNECEDORID(void);
   void setFORNECEDORID(int newFORNECEDORID);
   string getFORNECEDORCONTACTO(void);
   void setFORNECEDORCONTACTO(string newFORNECEDORCONTACTO);
   string getFORNECEDORNOME(void);
   void setFORNECEDORNOME(string newFORNECEDORNOME);
   string getFORNECEDORENDERECO(void);
   void setFORNECEDORENDERECO(string newFORNECEDORENDERECO);
   FORNECEDORE();
   ~FORNECEDORE();
   FORNECEDORE(const FORNECEDORE& oldFORNECEDORE);
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   FORNECEDORE *SetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);

protected:
private:
   int FORNECEDORID;
   string FORNECEDORCONTACTO;
   string FORNECEDORNOME;
   string FORNECEDORENDERECO;


};

#endif