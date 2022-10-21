/***********************************************************************
 * Module:  COMPRA.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:06:14
 * Purpose: Declaration of the class COMPRA
 ***********************************************************************/

#ifndef COMPRAH
#define COMPRAH
#include "PRODUTO.h"
#include "USUARIO.h"
#include "FORNECEDORE.h"

class COMPRA :public PRODUTO, public USUARIO, public FORNECEDORE
{
public:
   int getCOMPRAID(void);
   void setCOMPRAID(int newCOMPRAID);
   TDate getCOMPRADATA(void);
   void setCOMPRADATA(TDate newCOMPRADATA);
   int getCOMPRAQUANTIDADE(void);
   void setCOMPRAQUANTIDADE(int newCOMPRAQUANTIDADE);
   double getCOMPRAPRECO(void);
   void setCOMPRAPRECO(double newCOMPRAPRECO);
   COMPRA();
   ~COMPRA();
   int IsEmpty(void);
   Query GetQuery(FDQuery);
   Query SetQuery(FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);

   Query GetQuery(TFDQuery *FDQuery);
   COMPRA *SetQuery(TFDQuery *FDQuery);
protected:
private:
   TDate COMPRADATA;
   int COMPRAQUANTIDADE;
  int COMPRAID;
  double COMPRAPRECO;

};

#endif