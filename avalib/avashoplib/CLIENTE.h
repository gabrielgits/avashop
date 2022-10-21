/***********************************************************************
 * Module:  CLIENTE.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:07:45
 * Purpose: Declaration of the class CLIENTE
 ***********************************************************************/

#ifndef CLIENTEH
#define CLIENTEH
#include "TIPOCLIENTE.h"
#include "PESSOA.h"


class CLIENTE :public TIPOCLIENTE, public PESSOA
{
public:
   int getCLIENTEID(void);
   void setCLIENTEID(int newCLIENTEID);
   double getCLIENTECONTA(void);
   void setCLIENTECONTA(double newCLIENTECONTA);
   CLIENTE();
   ~CLIENTE();
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   CLIENTE *SetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);

protected:
private:
   double CLIENTECONTA;
   int CLIENTEID;

};

#endif